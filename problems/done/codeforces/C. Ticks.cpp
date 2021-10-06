// Problem: C. Ticks
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/C
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        
        vector<string> grid(n);
        for(auto &s : grid) cin >> s;
        
        vector<vi> mx_0(n, vi(m));
        vector<vi> mx_1(n, vi(m));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            
            if(grid[i][j] == '*'){
                if(i&&j){
                    mx_0[i][j] = mx_0[i-1][j-1]+1;
                }
                else{
                    mx_0[i][j] = 1;
                }
            }
            else{
                mx_0[i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            
            if(grid[i][j] == '*'){
                if((i)&&(j+1 < m)){
                    mx_1[i][j] = mx_1[i-1][j+1]+1;
                }
                else{
                    mx_1[i][j] = 1;
                }
            }
            else{
                mx_1[i][j] = 0;
            }
        }
        
        bool ans = true;
        vector<vi> vis(n, vi(m));
        
        for(int i = n-1; i >= 0; i--){
            
            for(int j = 0; j < m; j++) if(grid[i][j] == '*'){
                
                int cmx = min(mx_0[i][j], mx_1[i][j]);
                
                if(cmx > k){
                    int foo = 0;
                    while(cmx--){
                        vis[i-foo][j-foo] = true;
                        vis[i-foo][j+foo] = true;
                        foo++;
                    }
                }
                else if(!vis[i][j]){
                    ans = false;
                    break;
                }
                
            }
            
            if(!ans) break;
        }        
        
        cout << (ans ? "YES" : "NO") << endl;
    }	
    
    
}
