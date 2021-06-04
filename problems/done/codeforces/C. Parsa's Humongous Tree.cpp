// Problem: C. Parsa's Humongous Tree
// Contest: Codeforces - Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX][2];
vi adj[NMAX];

int mem[NMAX][3];

int go(int nd, int p, int par){
    
    int &ret = mem[nd][p+1];
    if(ret+1) return ret;
    
    int stPath = 0;
    int ndPath = 0;
    
    if(p != -1){
        stPath += abs(arr[nd][0] - arr[par][p]);
        ndPath += abs(arr[nd][1] - arr[par][p]);
    }
    
    for(auto nxt : adj[nd]) if(nxt != par){
        stPath += go(nxt, 0, nd);
        ndPath += go(nxt, 1, nd);
    }    
    
    return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> arr[i][0] >> arr[i][1];
            adj[i].clear();
        }
        
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v; u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        memset(mem, -1, sizeof mem);
        
        cout << go(0, -1, -1) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
