// Problem: C2. Skyscrapers (hard version)
// Contest: Codeforces - Codeforces Round #622 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1313/C2
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
	
	vi tmp(n);
	
	{
		int sm = 0;
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			
			while(mp.size() && (mp.rbegin()->first > vec[i])){
				pii tmp = *mp.rbegin();
				mp.erase(mp.find(tmp.first));
				mp[vec[i]] += tmp.second;
				sm -= tmp.first * tmp.second;
				sm += vec[i] * tmp.second;
			}
			
			mp[vec[i]]++;
			sm += vec[i];
			
			tmp[i] += sm;
		}
	}
	{
		int sm = 0;
		map<int, int> mp;
		for(int i = n-1; i >= 0; i--){
			
			while(mp.size() && (mp.rbegin()->first > vec[i])){
				pii tmp = *mp.rbegin();
				mp.erase(mp.find(tmp.first));
				mp[vec[i]] += tmp.second;
				sm -= tmp.first * tmp.second;
				sm += vec[i] * tmp.second;
			}
			
			mp[vec[i]]++;
			sm += vec[i];
			
			tmp[i] += sm;
		}
	}
	
	for(int i = 0; i < n; i++){
		tmp[i] -= vec[i];
	}
	
	int mx_idx = max_element(tmp.begin(), tmp.end()) - tmp.begin();
	
	int mn = vec[mx_idx];
	for(int i = mx_idx+1; i < n; i++){
		mn = min(mn, vec[i]);
		vec[i] = mn;
	}
	
	mn = vec[mx_idx];
	for(int i = mx_idx-1; i >= 0; i--){
		mn = min(mn, vec[i]);
		vec[i] = mn;
	}
	
    for(auto i : vec) cout << i << ' '; cout << endl;
}
