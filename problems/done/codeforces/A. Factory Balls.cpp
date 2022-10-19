// Problem: A. Factory Balls
// Contest: Codeforces - XXII Open Cup. Grand Prix of Seoul
// URL: https://codeforces.com/gym/103855/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

int n, k, m;
int arr[22];
int msk[22];
int dist[1<<10][1<<10];
int pre_calc[1<<10];
int pre_comp[22];

void bfs(int good, int used){
	
	memset(dist, -1, sizeof dist);
	
	queue<pii> que;
	dist[good][used] = 0;
	que.push({good, used});
	
	while(!que.empty()){
		
		auto fr = que.front();
		que.pop();
		
		int cgood = fr.first;
		int cused = fr.second;
		int cdist = dist[cgood][cused];
		
		for(int i = 0; i < m; i++){
			int nused = cused ^ (1<<i);
			if(dist[cgood][nused]==-1){
				dist[cgood][nused] = cdist+1;
				que.push({cgood, nused});
			}
		}	
		
		for(int i = 0; i < k; i++){
			int msk = pre_calc[cused];
			int ngood = cgood & msk;
			ngood |= pre_comp[i] & (~msk);
			if(dist[ngood][cused]==-1){
				dist[ngood][cused] = cdist+1;
				que.push({ngood, cused});
			}
		}
	}		
}

void init(){
	
	for(int used = (1<<m)-1; used >= 0; used--){
		int cmsk = 0;
		for(int j = 0; j < m; j++) if((used>>j)&1){
			cmsk |= msk[j];
		}
		pre_calc[used] = cmsk;
	}
		
	for(int i = 0; i < n; i++){
		pre_comp[arr[i]] |= 1<<i;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> k >> m;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	--arr[i];
    }
    
    for(int i = 0; i < m; i++){
    	int sz;
    	cin >> sz;
    	for(int j = 0; j < sz; j++){
    		int ai;
    		cin >> ai;
    		ai--;
    		msk[i] |= 1 << ai;
    	}
    }
    
    init();
    
    int good = 0;
    for(int i = 0; i < n; i++) if(arr[i]==0){
    	good |= 1<<i;
    }
    
    bfs(good, 0);
    
    int ans = dist[(1<<n)-1][0];
    cout << ans << endl;
}
