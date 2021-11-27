// Problem: F - Treasure Hunting
// Contest: AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest 227)
// URL: https://atcoder.jp/contests/abc227/tasks/abc227_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int lo, hi;
int n, m, k;
int arr[33][33];
int mem[33][33][66];
int vis[33][33][66], vid;

int go(int i, int j, int rst){
    
    if(arr[i][j] > hi){
        return int(60) * INF;    
    }
    
    if(i == n-1 && j==m-1){
        
        if(rst > 1 || (rst==1 && arr[i][j] < lo)){
            return int(60) * INF;
        }
        
        if(rst==1 && arr[i][j] >= lo){    
            return arr[i][j];
        }
        else if(rst==0){
            return (arr[i][j] >= lo ? arr[i][j] : 0);
        }
    }    
    
    if(vis[i][j][rst]==vid){
        return mem[i][j][rst];
    }
    else{
        vis[i][j][rst] = vid;
    }
    
    int ans = int(60) * INF;
       
    if(rst && arr[i][j] >= lo){
    
        int st_path = int(60) * INF;
        int nd_path = int(60) * INF;
        
        if(i!=n-1) st_path = arr[i][j] + go(i+1, j, rst-1);
        if(j!=m-1) nd_path = arr[i][j] + go(i, j+1, rst-1);
        
        ans = min(ans, min(st_path, nd_path));
    }
    
    if(arr[i][j] <= lo){        
    
        int st_path = int(60) * INF;
        int nd_path = int(60) * INF;
        
        if(i!=n-1) st_path = go(i+1, j, rst);
        if(j!=m-1) nd_path = go(i, j+1, rst);
        
        ans = min(ans, min(st_path, nd_path));
    }
    
    return mem[i][j][rst] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        cin >> arr[i][j];
    }
    
    vi vec;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) vec.push_back(arr[i][j]);
    
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    
    int ans = int(60) * INF;
    
    for(int i = 0; i < vec.size(); i++)
    for(int j = i; j < vec.size(); j++){
        
        ::lo = vec[i];
        ::hi = vec[j];
        
        vid++;
        int cans = go(0, 0, k);
        
        ans = min(ans, cans);    
    }
    
    cout << ans << endl;
}
