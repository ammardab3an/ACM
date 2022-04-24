// Problem: F1. Array Shuffling
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    
    // fastIO;
    #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		map<int, vi> mp;
		
		for(int i = 0; i < n; i++){
			mp[vec[i]].push_back(i);
		}
		
		vector<vi> tmp;
		for(auto p : mp){
			tmp.push_back(p.second);	
		}
		
		vi pos(tmp.size());
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&](int i, int j){
			return tmp[i].size() > tmp[j].size();
		});
		
		// for(int p : pos){
			// for(auto i : tmp[p]){
				// cout << i << ' ' ;
			// }
			// cout << endl;
		// }
		// cout << endl;
		
		vector<vi> ans;
		
		while(!pos.empty()){
			
			ans.push_back({});
			
			for(auto p : pos){
				ans.back().push_back(tmp[p].back());
				tmp[p].pop_back();
			}
			
			while(!pos.empty() && tmp[pos.back()].empty()){
				pos.pop_back();
			}
		}
		
		for(auto v : ans){
			
			sort(v.begin(), v.end(), [&](int i, int j){
				return vec[i] < vec[j];
			});
			
			// for(auto i : v) cout << i << ' '; cout << endl;
			
			int t = vec[v.back()];
			
			for(int i = v.size()-1; i > 0; i--){
				vec[v[i]] = vec[v[i-1]];
			}
			
			vec[v[0]] = t;
		}
		
		for(auto i : vec) cout << i << ' '; cout << endl;
    }	
}