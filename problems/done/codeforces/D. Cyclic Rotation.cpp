// Problem: D. Cyclic Rotation
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/D
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
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec_a(n), vec_b(n);
		for(auto &i : vec_a) cin >> i;
		for(auto &i : vec_b) cin >> i;
		
		map<int, int> mp, lst;
		
		for(int i = 0; i < n; i++){
			lst[vec_a[i]] = i;
		}
		
		bool ans = true;
		
		int j = 0; 
		for(int i = 0; i < n; i++){
			
			// cout << i << ' ' << j << ' ' << mp[vec_a[i]] << endl;
			
			if(vec_a[i] != vec_b[j]){
				
				if(lst[vec_a[i]] == i){
					ans = false;
					break;
				}
				else{
					mp[vec_a[i]]++;
				}
			}
			else{
				
				mp[vec_a[i]]++;
				
				while(j < n && vec_b[j]==vec_a[i] && mp[vec_a[i]]){
					mp[vec_a[i]]--;
					j++;
				}
				
				if(mp[vec_a[i]]){
					if(lst[vec_a[i]]==i){
						ans = false;
						break;
					}
				}
			}
		}
		
		ans &= j==n;
		
		for(auto p : mp){
			ans &= p.second==0;
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
