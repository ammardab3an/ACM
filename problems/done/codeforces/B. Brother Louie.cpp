// Problem: B. Brother Louie
// Contest: Codeforces - 2015 ACM Syrian Collegiate Programming Contest
// URL: https://codeforces.com/gym/101086/problem/B
// Memory Limit: 256 MB
// Time Limit: 6000 ms
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

int l[NMAX], r[NMAX];
pair<double, double> cor[NMAX];
int idx[NMAX], cnt;
int lvl[NMAX];
int vis[NMAX], vid;

pair<double, double> dfs(int u){
    
    if(l[u] == -1){
        
        if(!cnt){
            idx[cnt++] = u;
            return cor[u] = {0, 0};
        }
        
        auto pst = cor[idx[cnt-1]];
        idx[cnt++] = u;
        
        pair<double, double> ret;
        ret.first = pst.first + 2.0;
        ret.second = pst.second + 1.0;
        
        return cor[u] = ret;
    }   
    
    lvl[l[u]] = lvl[u]+1;
    lvl[r[u]] = lvl[u]+1;
    
    auto p0 = dfs(l[u]);
    auto p1 = dfs(r[u]);
    
    pair<double, double> ret = {(p0.first + p1.first)/2.0, (p0.second+p1.second)/2.0}; 
    
    return cor[u] = ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cout << fixed << setprecision(4);
    
    int t; cin >> t; while(t--){

        int n, q;
        cin >> n >> q;
        
        vid++;
        
        for(int i = 0; i < n; i++){
            
            int m;
            cin >> m;
            
            if(m){
                cin >> l[i] >> r[i];
                l[i]--, r[i]--;
                vis[l[i]] = vis[r[i]] = vid;
            }
            else{
                l[i] = r[i] = -1;
            }
        }
        
        int root = -1;
        for(int i = 0; i < n; i++) if(vis[i] != vid){
            root = i;
            break;
        }
        
        assert(root != -1);
        
        lvl[root] = cnt = 0;
        auto zero_cor = dfs(root);
        
        for(int i = 0; i < n; i++){
            cor[i].first -= zero_cor.first;
            cor[i].second -= zero_cor.second;
        }
        
        while(q--){
            
            int r, v, h, u;
            cin >> r >> v >> h >> u;
            u--;
            
            auto tmp = cor[u];
            
            double x, y;
            x = double(r) * cor[u].first + double(h) * cor[u].second;
            y = -1.0 * (double(v) + 2.0 * double(r)) * lvl[u];
            
            cout << x << ' ' << y << endl;
        }
    }	
}
