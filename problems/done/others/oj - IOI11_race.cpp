
// https://oj.uz/problem/view/IOI11_race

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

const int NMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n, k, log_n;
vpii adj[NMAX];
int depth[NMAX], sub[NMAX], par[NMAX][LOG_MAX];
int cpar[NMAX];

void dfs0(int u, int p){

    for(auto [v, w]: adj[u]) if(v != p){

        depth[v] = depth[u] + 1;

        par[v][0] = u;
        for(int i = 1; i < log_n; i++)
            par[v][i] = par[par[v][i-1]][i-1];

        dfs0(v, u);
    }
}

int lca(int u, int v){

    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < log_n; i++) if(diff & (1<<i)) u = par[u][i];
    if(u == v) return u;
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int nn;
void dfs1(int u, int p){

    nn++;
    sub[u] = 1;

    for(auto [v, w] : adj[u]) if(v != p){
        dfs1(v, u);
        sub[u] += sub[v];
    }
}

int dfs2(int u, int p){

    for(auto [v, w] : adj[u]) if(v != p) if(sub[v] > nn/2){
        return dfs2(v, u);
    }

    return u;
}

int _dist[NMAX];
int _depth[NMAX];
map<int, int> freq;
vi update_later;

int go(int u, int p){

    int ret = INFLL;
    auto it = freq.find(k-_dist[u]);
    
    if(it != freq.end()){
        ret = it->second + _depth[u];
    }
    
    update_later.push_back(u);

    for(auto [v, w] : adj[u]) if(v != p){

        _dist[v] = _dist[u]+w;
        _depth[v] = _depth[u]+1;
        
        ret = min(ret, go(v, u));

        if(p==-1){
            
            for(auto u : update_later){
                
                auto it = freq.find(_dist[u]);
                
                if(it==freq.end()){
                    freq[_dist[u]] = _depth[u];
                }
                else{
                    freq[_dist[u]] = min(it->second, _depth[u]);
                }
            }
            
            update_later.clear();
        }
    }

    return ret;
}

int decompose(int u, int p){

    nn = 0;
    dfs1(u, u);
    int centroid = dfs2(u, u);
    if(p == -1) p = centroid;
    cpar[centroid] = p;

    _dist[centroid] = 0;
    _depth[centroid] = 0;
    update_later.clear();
    freq.clear();
    freq[0] = 0;

    int ret = go(centroid, -1);

    for(auto [v, w] : adj[centroid]){
        adj[v].erase(find(adj[v].begin(), adj[v].end(), (pii){centroid, w}));
        ret = min(ret, decompose(v, centroid));
    }

    adj[centroid].clear();

    return ret;
}

int best_path(int32_t N, int32_t K, int32_t H[][2], int32_t L[]){

    ::n = N;
    ::k = K;
    log_n = ceil(log2(double(N)));

    for(int i = 0; i < n; i++){
        adj[i].clear();
    }
    
    for(int i = 0; i < n-1; i++){
        int u = H[i][0];
        int v = H[i][1];
        adj[u].push_back({v, L[i]});
        adj[v].push_back({u, L[i]});
    }

    dfs0(0, -1);
    int ret = decompose(0, -1);
    if(ret==INFLL) ret = -1;
    
    return ret;
}

#ifdef CPEDU

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    int32_t N, K;
    cin >> N >> K;

    int32_t H[N-1][2];
    for(int i = 0; i < N-1; i++){
        cin >> H[i][0] >> H[i][1];
    }

    int32_t L[N-1];
    for(int i = 0; i < N-1; i++){
        cin >> L[i];
    }

    cout << best_path(N, K, H, L) << endl;
}

#endif
