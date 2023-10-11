// Problem: D. Dima and Bacteria
// Contest: Codeforces - Codeforces Round 234 (Div. 2)
// URL: https://codeforces.com/contest/400/problem/D
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

int par[NMAX];
int dist[555][555];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return false;
	}
	
	if(rand()&1) swap(u, v);
	
	par[u] = v;
	
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vi tmp(k);
	for(auto &i : tmp) cin >> i;
	
	for(int i = 1; i < k; i++){
		tmp[i] += tmp[i-1];
	}
	
	memset(dist, INF, sizeof dist);
	
	for(int i = 0; i < n; i++){
		par[i] = i;
	}
	
	while(m--){
		
		int u, v, w;
		cin >> u >> v >> w;
		
		assert(u <= n && v <= n);		
		// if(u > n || v > n) continue;
		
		int pu = lower_bound(tmp.begin(), tmp.end(), u) - tmp.begin();
		int pv = lower_bound(tmp.begin(), tmp.end(), v) - tmp.begin();
		
		// cout << ' ' << pu << ' ' << pv << ' ' << w << endl;
		
		if(w == 0){
			merge(u-1, v-1);
		}
		
		if(pu != pv){
			if(w < dist[pu][pv]){
				dist[pu][pv] = dist[pv][pu] = w;
			}
		}
	}
	
	bool good = true;
	
	for(int i = 0; i < k; i++){
		
		int lst = i ? tmp[i-1] : 0;
		
		int pp = get_par(lst);
		for(int j = lst; j < tmp[i]; j++){
			if(get_par(j) != pp){
				good = false;
				break;
			}
		}
		
		if(!good) break;
	}
	
	if(!good){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i = 0; i < k; i++){
		dist[i][i] = 0;
	}
	
	for(int z = 0; z < k; z++)
	for(int x = 0; x < k; x++)
	for(int y = 0; y < k; y++){
		dist[x][y] = min(dist[x][y], dist[x][z] + dist[z][y]);
	}
	
	cout << "Yes" << endl;
	for(int i = 0; i < k; i++){
		
		for(int j = 0; j < k; j++){
			
			if(dist[i][j] > (10000 * 500)){
				dist[i][j] = -1;
			}	
			
			cout << dist[i][j] << ' ';
		}
		
		cout << endl;
	}
}
