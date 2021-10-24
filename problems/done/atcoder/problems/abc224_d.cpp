// Problem: D - 8 Puzzle on Graph
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

int m;
vi adj[9];
bool vis[9][9][9][9][9][9][9][9];

inline bool good(vi &tmp){

    for(int i = 0; i < 8; i++){
        if(tmp[i] != i){
            return false;
        }
    }

    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi tmp(8);
    for(auto &i : tmp) cin >> i, i--;
    
    queue<pair<int, vi>> que;
    que.push({0, tmp});
    
    while(!que.empty()){
        
        auto fr = que.front(); que.pop();
        
        int d = fr.first;
        vi tmp = fr.second;
        
        if(good(tmp)){
            cout << d << endl;
            exit(0);
        }
        
        vi pmt(9, -1);
        for(int i = 0; i < 8; i++){
            pmt[tmp[i]] = i;
        }
        
        int u;
        for(int i = 0; i < 9; i++) if(pmt[i] == -1){
            u = i;
            break;
        }
        
        for(auto v : adj[u]){
            
            int t = tmp[pmt[v]];
            tmp[pmt[v]] = u;
            bool &cvis = vis[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]][tmp[6]][tmp[7]];
            
            if(!cvis){
                cvis = true;
                que.push({d+1, tmp});
            }
                    
            tmp[pmt[v]] = t;
        }
    }
    
    cout << -1 << endl;
}
