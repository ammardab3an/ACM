// Problem: F. Median and Queries
// Contest: Codeforces - 2018 JUST Programming Contest 1.0
// URL: https://codeforces.com/gym/101778/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int grid[111][111];
int pre[505][111][111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, m, q;
        cin >> n >> m >> q;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> grid[i][j];
        
        for(int k = 1; k <= 500; k++){
            
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                
                pre[k][i][j] = bool(grid[i][j] >= k);
                if(i) pre[k][i][j] += pre[k][i-1][j];
                if(j) pre[k][i][j] += pre[k][i][j-1];
                if(i&&j) pre[k][i][j] -= pre[k][i-1][j-1];
            }
        }
        
        while(q--){
            
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            
            int l = 1;
            int r = 500;
            
            int ans = -1;
            
            int cnt = (c-a+1) * (d-b+1);
            
            while(l <= r){
                
                int mid = (l+r)/2;
                
                int k = mid;
                
                int sm = pre[k][c][d];
                if(a) sm -= pre[k][a-1][d];
                if(b) sm -= pre[k][c][b-1];
                if(a&&b) sm += pre[k][a-1][b-1];
                
                if(sm > cnt-sm){
                    ans = mid;
                    l = mid+1;    
                }
                else{
                    r = mid-1;
                }
            }
            
            cout << ans << endl;
        }
    }	
}
