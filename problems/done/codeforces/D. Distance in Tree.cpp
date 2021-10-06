// Problem: D. Distance in Tree
// Contest: Codeforces - VK Cup 2012 Round 1
// URL: https://codeforces.com/contest/161/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

// #define endl '\n'
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 5e4 + 10;

int n, k, ans;
vi adj[NMAX];

int dist[NMAX][555];

void dfs(int u, int p){
    
    dist[u][0] = 1;
    
    for(auto v : adj[u]) if(v != p){
        
        dfs(v, u);
        
        for(int i = 1; i < k+10; i++){
            dist[u][i] += dist[v][i-1];
        }
    }    
}

int go(int u, int p){
    
    int ret = 0;
    int cnt = 0;
    
    for(auto v : adj[u]) if(v != p){
        
        for(int i = 1; i < k+10; i++){
            dist[u][i] -= dist[v][i-1];
        }
        for(int i = 1; i < k+10; i++){
            dist[v][i] += dist[u][i-1];
        }
        
        ret += go(v, u);
        
        for(int i = 1; i < k+10; i++){
            dist[v][i] -= dist[u][i-1];
        }
        for(int i = 1; i < k+10; i++){
            dist[u][i] += dist[v][i-1];
        }
        
        ret += dist[v][k];
        if(k-1) ret -= dist[v][k-2];
        
        cnt++;
    }    
    
    ret += dist[u][k-1] * cnt;
    
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    cout << (go(0, -1)+dist[0][k])/2 << endl;
}
