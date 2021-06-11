// Problem: D. Maximum Distributed Tree
// Contest: Codeforces - Codeforces Round #665 (Div. 2)
// URL: https://codeforces.com/contest/1401/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 1e5 + 10;
const int MMAX = 6e4 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
vi adj[NMAX];
pii edges[NMAX];
int sub[NMAX];
int depth[NMAX];
int tmp[NMAX], tmp_sz;
int ai[MMAX];

int dfs(int u, int p){
    
    sub[u] = 1;
    for(auto v : adj[u]) if(v != p){
        
        depth[v] = depth[u] + 1;
        
        dfs(v, u);
        sub[u] += sub[v];    
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n;
        
        tmp_sz = 0;
        for(int i = 0; i < n; i++) adj[i].clear();
        
        for(int i = 0; i < n-1; i++){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            adj[u].push_back(v);
            adj[v].push_back(u);    
            edges[i] = {u, v};
        }
        
        dfs(0, -1);
        
        for(int i = 0; i < n-1; i++){
            
            int u = edges[i].first;
            int v = edges[i].second;
            
            if(depth[u] < depth[v]) swap(u, v);
            
            tmp[tmp_sz++] = (n-sub[u]) * sub[u];
        }
        
        sort(tmp, tmp+tmp_sz);
        reverse(tmp, tmp+tmp_sz);
        
        // for(int i = 0; i < n-1; i++) cout << tmp[i] << ' ' ; cout << endl;
        
        int ans = 0;
        
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) cin >> ai[i];
        
        sort(ai, ai+m);
        reverse(ai, ai+m);
        
        if(n-1 >= m){
            
            int pos = 0;
            for(int i = 0; i < m; i++){
                ans = add(ans, mul(tmp[pos++], ai[i]));
            }
            
            while(pos < tmp_sz){
                ans = add(ans, tmp[pos++]);
            }
            
        }
        else{
            
            int dif = m-(n-1);
            
            int i;
            int a0 = 1;
            for(i = 0; i <= dif; i++){    
                a0 = mul(a0, ai[i]);
            }
            
            int pos = 0;
            ans = add(ans, mul(tmp[pos++], a0));
            
            for(; i < m; i++){
                ans = add(ans, mul(tmp[pos++], ai[i]));
            }
        }
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
