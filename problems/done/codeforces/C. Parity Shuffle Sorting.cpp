// Problem: C. Parity Shuffle Sorting
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforces.com/contest/1733/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
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

bool debug = false;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; 
    
    if(debug){
    	cout << t << endl;
    }
    
    while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		if(debug){
			cout << n << endl;
			for(auto i : vec) cout << i << ' '; 
			cout << endl;
		}
		
		vpii ans;
		
		vector<set<pii>> st(2);
		
		for(int i = 0; i < n; i++){
			st[vec[i]%2].insert({vec[i], i});
		}
		
		for(int i = 0; i < n; i++){
			
			int b = vec[i]%2;
			
			int tt = vec[i];
			
			if(i && (st[b].begin()->first < vec[i-1])){
				assert(vec[i-1]%2 != vec[i]%2);
				ans.push_back({i-1, i});
				vec[i] = vec[i-1];
			}
			else{
				int j = st[b].begin()->second;
				ans.push_back({i, j});
				vec[i] = vec[j];
			}
			
			st[b].erase({tt, i});
		}
		
		int tot = 0;
		for(auto &[l, r] : ans){
			tot += l != r;
			if(l > r) swap(l, r);
		}
		
		cout << tot << endl;
		for(auto [l, r] : ans) if(l != r){
			cout << l+1 << ' ' << r+1 << endl;
		}
    }	
}
