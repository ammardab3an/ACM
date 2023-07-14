// Problem: J. Joining Capitals
// Contest: Codeforces - 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/101908/problem/J
// Memory Limit: 1024 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

struct node{
	int x, y;
} arr[111];

double _dist(int i, int j){
	int dx = arr[i].x-arr[j].x;
	int dy = arr[i].y-arr[j].y;
	return sqrt(dx*dx + dy*dy);	
}

double dp[111][111][1<<10];
double dist[11][111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i].x >> arr[i].y;
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
    	dist[i][j] = _dist(i, j);
    }
    
    for(int msk = 1; msk < (1<<k); msk++)
    for(int i = k; i < n; i++)
    for(int j = k; j <= n; j++)
    {
    	double ans = 1e18;
    	
    	if(j==n){
    		for(int p = k; p < n; p++){
    			double cans = dp[i][p][msk] + dist[i][p];
    			ans = min(ans, cans);
    		}	
    		dp[i][j][msk] = ans;
    		continue;
    	}
    	
    	for(int p = 0; p < k; p++) if((msk>>p)&1){
    		double st_path = dp[i][j][msk^(1<<p)];
    		double nd_path = dp[j][n][msk^(1<<p)];
    		double rd_path = dp[i][n][msk^(1<<p)];
    		double cans = min(st_path, min(nd_path, rd_path)) + dist[j][p];
    		ans = min(ans, cans);
    	}
    	
    	dp[i][j][msk] = ans;	
    }
    
    double ans = 1e18;
    for(int i = k; i < n; i++){
    	double cans = dp[i][n][(1<<k)-1];
    	ans = min(ans, cans);
    }
    
    cout << fixed << setprecision(5) << ans << endl;
}
