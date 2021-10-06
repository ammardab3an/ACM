// Problem: E. Jumping
// Contest: Codeforces - 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// URL: https://codeforces.com/gym/101147/problem/E
// Memory Limit: 512 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

vi adj[NMAX];
int dist[NMAX];

void dij(int u){
    
    memset(dist, INF, sizeof dist);
    
    dist[u] = 0;
    priority_queue<pii> que;
    que.push({0, u});
    
    while(!que.empty()){
        
        auto tp = que.top(); que.pop();
        
        int cu = tp.second;
        int cd = -tp.first;
        
        // cout << cu << ' ' << cd << ' ' << endl;
        
        if(dist[cu] < cd) continue;
        
        for(auto v : adj[cu]){
            
            int nu = v;
            int nd = cd + 1;
            
            if(dist[nu] > nd){
                dist[nu] = nd;
                que.push({-nd, nu});
            }
        }
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("jumping.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) adj[i].clear();
        
        for(int i = 0; i < n; i++){
            
            int di;
            cin >> di;
            
            if(i+di < n) {
                adj[i+di].push_back(i);
            }
            
            if(i-di >= 0){
                adj[i-di].push_back(i);            
            }
                
        }
        
        dij(n-1);
        
        for(int i = 0; i < n; i++){
            int cdist = dist[i];
            if(cdist >= INF) cdist = -1;
            cout << cdist << endl;
        }
    }	
}
