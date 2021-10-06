// Problem: E. Air Conditioners
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		vi vec_a(k), vec_t(k);
		for(auto &i : vec_a) cin >> i;
		for(auto &i : vec_t) cin >> i;
		
		vi pos(k);
		for(int i = 0; i < k; i++) pos[i] = i;
		
		sort(pos.begin(), pos.end(), [&](int a, int b){
			return vec_a[a] < vec_a[b];
		});
		
		multiset<int> pre_st, suf_st;
		
		for(int i = 0; i < k; i++){
			suf_st.insert(vec_t[i]+vec_a[i]);
		}
		
		int j = 0;
		for(int i = 1; i <= n; i++){
			
			while(j < k && vec_a[pos[j]] < i){
				suf_st.erase(suf_st.find(vec_t[pos[j]]+vec_a[pos[j]]));
				pre_st.insert(vec_t[pos[j]]-vec_a[pos[j]]);
				j++;
			}
			
			int stPath = INFLL, ndPath = INFLL;
			
			if(!pre_st.empty()){
				stPath = *pre_st.begin() + i;
			}
			if(!suf_st.empty()){
				ndPath = *suf_st.begin() - i;
			}
			
			cout << min(stPath, ndPath) << ' ';
		}
		
		cout << endl;
    }	
}