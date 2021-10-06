// Problem: A. 2Dimension
// Contest: Codeforces - Test
// URL: https://codeforces.com/gym/345001/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int NMAX = 1e3 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int grid[NMAX][NMAX];
int tmp[NMAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
        
        int n, m, o, q;
        cin >> n >> m >> o >> q;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> grid[i][j];
        
        memset(tmp, 0, sizeof tmp);
        
        while(o--){
            
            int i, j, x, y, k;
            cin >> i >> j >> x >> y >> k;
            i--, j--, x--, y--;
            
            tmp[i][j] += k;
            tmp[i][y+1] -= k;
            tmp[x+1][j] -= k;
            tmp[x+1][y+1] += k;
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            
            if(i) tmp[i][j] += tmp[i-1][j];
            if(j) tmp[i][j] += tmp[i][j-1];
            if(i&&j) tmp[i][j] -= tmp[i-1][j-1];
            
            // cout << tmp[i][j] << ' ';
            // if(j==m-1) cout << endl;
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            
            tmp[i][j] += grid[i][j];
            if(i) tmp[i][j] += tmp[i-1][j];
            if(j) tmp[i][j] += tmp[i][j-1];
            if(i&&j) tmp[i][j] -= tmp[i-1][j-1];
        }
        
        while(q--){
            
            int i, j, x, y;
            cin >> i >> j >> x >> y;
            i--, j--, x--, y--;
            
            int ans = tmp[x][y];
            if(i) ans -= tmp[i-1][y];
            if(j) ans -= tmp[x][j-1];
            if(i&&j) ans += tmp[i-1][j-1];
            
            cout << ans << endl;
        }
    }
}
