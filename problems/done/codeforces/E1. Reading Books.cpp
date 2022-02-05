// Problem: E1. Reading Books (easy version)
// Contest: Codeforces - Codeforces Round #653 (Div. 3)
// URL: https://codeforces.com/contest/1374/problem/E1
// Memory Limit: 256 MB
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
    
    int t = 1; while(t--){

		int n, k;
		cin >> n >> k;
		
		vector<vi> vec(4);
		
		for(int i = 0; i < n; i++){
			
			int v, a, b;
			cin >> v >> a >> b;
			
			vec[(a << 1) | b].push_back(v);
		}
		
		vector<vi> pre;
		
		for(auto &v : vec){
			
			sort(v.begin(), v.end());
			
			pre.push_back(vi(v.size()));
			
			if(v.size()){
				pre.back()[0] = v[0];
				for(int i = 1; i < v.size(); i++){
					pre.back()[i] = pre.back()[i-1] + v[i];
				}
			}
		}
		
		int ans = INFLL;
		bool found = false;
		
		int mx = min((int)vec[3].size(), k);
		
		for(int i = 0; i <= mx; i++){
			
			int sz[] = {k-i, k-i, i};
			
			if(k-i > vec[1].size() || k-i > vec[2].size()){
				continue;
			}
			
			int cans = 0;
			for(int i = 1; i <= 3; i++){
				if(sz[i-1]){
					cans += pre[i][sz[i-1]-1];
				}
			}
			
			found = true;
			ans = min(ans, cans);
		}
		
		if(!found){
			cout << -1 << endl;
		}
		else{
			cout << ans << endl;
		}
    }	
}
