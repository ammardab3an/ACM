// Problem: C. Serval and Toxel's Arrays
// Contest: Codeforces - Codeforces Round #853 (Div. 2)
// URL: https://codeforces.com/contest/1789/problem/C
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		vi vec(n);
		for(auto &i : vec) cin >> i, --i;
		
		vi frq(n+m);
		int sm = n;
		int ans = 0;
		
		for(auto i : vec){
			frq[i]++;
		}
		
		map<int, int> mp;
		for(auto i : vec) mp[i] = 0;
		int mp_add = 0;
		
		for(int i = 0; i < m; i++){
			
			int p, v;
			cin >> p >> v;
			p--, v--;
			
			// cout << sm << endl;
			
			{
				auto it = mp.find(vec[p]);
				if(it != mp.end()){
					frq[vec[p]] += it->second + mp_add;
					mp.erase(it);
				}
			}
			
			sm -= frq[vec[p]];
			vec[p] = v;
			sm += frq[vec[p]];
			
			ans += n*(i+1);
			ans += n*(i+1)-sm;
			
			mp[v] = -mp_add;
			mp_add++;
			sm += n;
		}
		
		cout << ans << endl;
    }	
}
