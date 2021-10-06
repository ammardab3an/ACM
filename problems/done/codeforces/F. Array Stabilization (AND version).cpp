// Problem: F. Array Stabilization (AND version)
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/F
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
 
const int NMAX = 1e6 + 10;
const int LOG_MAX = ceil(log2(double(NMAX))) + 1;
const int BLOCK = ceil(sqrt(double(NMAX)));

int arr[NMAX];
int par[LOG_MAX][NMAX];
int par_and[LOG_MAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, d;
        cin >> n >> d;
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        int log_2 = ceil(log2(double(n))) + 1;
        
        for(int i = 0; i < n; i++){
            par[0][i] = (i-d+n)%n;
            par_and[0][i] = arr[par[0][i]];
        }
        
        for(int j = 1; j < log_2; j++)
        for(int i = 0; i < n; i++){
            par[j][i] = par[j-1][par[j-1][i]];
            par_and[j][i] = par_and[j-1][i] & par_and[j-1][par[j-1][i]];
        }
        
        auto test = [&](int m){
            
            for(int i = 0; i < n; i++){
                
                int ai = arr[i];
                
                int cur = i;
                for(int j = 0; j < log_2; j++) if((m>>j)&1){
                    ai &= par_and[j][cur];
                    cur = par[j][cur];
                    if(!ai) break;
                }
                
                if(ai) return false;
            }    
                
            return true;
        };
        
        int l = 0;
        int r = n;
        
        int ans = -1;
        
        while(l <= r){
            
            int mid = (l+r)/2;
            
            if(test(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        cout << ans << endl;
    }	
}
