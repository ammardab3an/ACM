
// F. AA Country and King Dreamoon
// https://qoj.ac/contest/1124/problem/5665?v=1

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		int m = 2*n-1;
		m = max(m, int(0));
		
		vi vec(m);
		for(auto &i : vec) cin >> i, --i;
		
		if(n==0){
			n = 3e5;
			m = 2*n-1;
			vec = vi(m, -1);
		}
		
		vi par(n, -1);
		vector<set<int>> adj(n);
		vector<bool> vis(n);
		
		set<int> st_not_exists, st_suf;
		
		vec[0] = 0;
		vec[m-1] = 0;
		for(int i = 0; i < m; i++) if(vec[i] != -1){
			vis[vec[i]] = true;
		}
		for(int i = 0; i < n; i++) if(!vis[i]){
			st_not_exists.insert(i);
		}
		
		for(int i = 1; i < m && (vec[i]!=-1); i++){
			int p = vec[i-1];
			if(par[vec[i]]==-1) par[vec[i]] = p;
		}
		
		for(int i = m-2; i >= 0 && (vec[i]!=-1); i--){
			
			int p = vec[i+1];
			st_suf.insert(vec[i]);
			
			if(par[vec[i]]==-1){
				adj[p].insert(vec[i]);
				par[vec[i]] = p;
			}
			
			if(i) if(par[vec[i]] != -1 && par[vec[i]]==vec[i-1]){
				adj[vec[i-1]].erase(vec[i]);
			}
		}
		
		par[0] = INF;
		st_suf.insert(0);
		
		int l = 0;
		while(l < m && vec[l] != -1) l++;
		
		for(int i = l; i < m && (vec[i]==-1); i++){
			
			int p = vec[i-1];
			
			if(adj[p].empty()){
				
				int st_path = !st_suf.count(p) ? par[p] : INF;
				int nd_path = !st_not_exists.empty() ? *st_not_exists.begin() : INF;
				
				if(st_path < nd_path){
					vec[i] = st_path;
				}
				else{
					vec[i] = nd_path;
					st_not_exists.erase(st_not_exists.begin());
					par[vec[i]] = p;
				}
			}
			else{
				
				int st_path = *adj[p].begin();
				int nd_path = !st_not_exists.empty() ? *st_not_exists.begin() : INF;
				
				if(st_path < nd_path){
					vec[i] = st_path;
					adj[p].erase(adj[p].begin());
				}
				else{
					vec[i] = nd_path;
					st_not_exists.erase(st_not_exists.begin());
					par[vec[i]] = p;
				}
			}
			
			// cout << i << endl;
			// for(auto e : vec) cout << e << ' '; cout << endl;
			// cout << flush;
		}
		
		for(auto e : vec) cout << e+1 << ' '; cout << endl;
    }	
}