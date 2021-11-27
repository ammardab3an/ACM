// Problem: L. Spicy Restaurant
// Contest: Codeforces - The 2021 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103117/problem/L
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
 
const int NMAX = 5e5 + 10;

int n, m, q;
int arr[NMAX];
vi adj[NMAX];
int dist[NMAX];
vi mp[111];
int ans[NMAX];

void dij(const vi &nds){
    
    memset(dist, INF, sizeof dist);
    
    queue<pii> que;
    
    for(auto i : nds){
        dist[i] = 0;
        que.push({0, i});
    }
    
    while(!que.empty()){
        
        auto tp = que.front(); que.pop();
        
        int cd = tp.first;
        int cn = tp.second;
        
        if(dist[cn] < cd){
            continue;
        }
        
        for(auto v : adj[cn]){
            if(dist[v] > cd+1){
                dist[v] = cd+1;
                que.push({(cd+1), v});
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

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vpii que(q);
    for(auto &p : que){
        cin >> p.first >> p.second;
        p.first--;
    }
    
    memset(ans, INF, sizeof ans);
    
    for(int i = 1; i <= 100; i++) if(mp[i].size()){
        
        dij(mp[i]);
        
        for(int j = 0; j < q; j++){
            
            if(i <= que[j].second){
                
                ans[j] = min(ans[j], dist[que[j].first]);
            }    
        }
    }
    
    for(int i = 0; i < q; i++){
        if(ans[i] >= INF) ans[i] = -1;
    }
    
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}
