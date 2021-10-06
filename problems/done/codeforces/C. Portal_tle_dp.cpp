// Problem: C. Portal
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.com/contest/1581/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n, m;
char grid[555][555];
int pre[2][555][555];
int mem[555][5];
int vis[555][5], vid;

int l, r;
int go(int i, int k){
    
    if(i==n){
        return INF;
    }    
    
    if(vis[i][k] == vid){
        return mem[i][k];
    }
    else{
        vis[i][k] = vid;
    }
    
    int ans = INF;
    
    if(k==0){
        int st_path = go(i+1, 0);
        int nd_path =  (pre[0][i][r-1] - pre[0][i][l]) + go(i+1, 1);
        ans = min(ans, min(st_path, nd_path));
    }
    else{
        int st_path = (pre[1][i][r-1] - pre[1][i][l]) + (grid[i][l] == '0') + (grid[i][r] == '0') + go(i+1, min((int)4, k+1));
        int nd_path = k < 4 ? INF : (pre[0][i][r-1] - pre[0][i][l]);
        ans = min(ans, min(st_path, nd_path));
    }
    
    return mem[i][k] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n >> m;
        
        for(int i = 0; i < n; i++) cin >> grid[i];
        
        for(int k = 0; k < 2; k++)
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            pre[k][i][j] = grid[i][j]-'0' == k;
            if(j) pre[k][i][j] += pre[k][i][j-1];
        }
        
        int ans = INF;
        
        for(int i = 0; i < m; i++)
        for(int j = i+3; j < m; j++){
            
            vid++;
            :: l = i;
            :: r = j;
            
            int cans = go(0, 0);
            
            ans = min(ans, cans);
        }
        
        cout << ans << endl;
    }	
}
