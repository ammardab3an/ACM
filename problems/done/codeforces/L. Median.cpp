// Problem: L. Median
// Contest: Codeforces - 2019 JUST Programming Contest
// URL: https://codeforces.com/gym/102152/problem/L
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

int grid[1010][1010];
int pre[1010][1010];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m, h, w;
    cin >> n >> m >> h >> w;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
    
    int l = 1;
    int r = n*m;
    
    int ans = -1;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        bool found = false;
        
        for(int i = 0; i < n && !found; i++)
        for(int j = 0; j < m && !found; j++){
            
            pre[i][j] = (grid[i][j] <= mid) ? +1 : -1;
            if(i) pre[i][j] += pre[i-1][j];
            if(j) pre[i][j] += pre[i][j-1];
            if(i&&j) pre[i][j] -= pre[i-1][j-1];
            
            if(i >= h-1 && j >= w-1){
                
                int csm = pre[i][j];
                if(i-h >= 0) csm -= pre[i-h][j];
                if(j-w >= 0) csm -= pre[i][j-w];
                if(i-h >= 0 && j-w >= 0) csm += pre[i-h][j-w];
                
                if(csm > 0){
                    found = true;
                }
            }
        }
        
        if(found){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    cout << ans << endl;
}
