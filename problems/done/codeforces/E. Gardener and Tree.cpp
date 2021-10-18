// Problem: E. Gardener and Tree
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 4e5 + 10;

vi adj[NMAX];
bool vis[NMAX];
int deg[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;
        
        memset(vis, 0, n * sizeof (vis[0]));
        
        for(int i = 0; i < n; i++){
            adj[i].clear();
            deg[i] = 0;
        }
        
        
        for(int i = 0; i < n-1; i++){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            deg[u]++, deg[v]++;
        }
        
        queue<int> que;
        
        for(int i = 0; i < n; i++){
            if(adj[i].size() <= 1){
                que.push(i);
                vis[i] = true;
            }
        }
        
        int ans = n;
        
        while(k-- && !que.empty()){
            
            ans -= que.size();
            
            queue<int> nque;
            
            while(!que.empty()){
                
                int u = que.front(); que.pop();
                
                for(auto v : adj[u]){
                    
                    deg[v]--;
                    
                    if(vis[v] == 0 && deg[v] <= 1){
                        nque.push(v);
                        vis[v] = true;
                    }
                } 
                
            }    
            
            que = nque;
        }
        
        cout << ans << endl;
    }	
}
