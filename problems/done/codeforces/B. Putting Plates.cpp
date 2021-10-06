// Problem: B. Putting Plates
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/B
// Memory Limit: 512 MB
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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
char grid[22][22];
int vis[22][22];

bool good(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int go(int i, int j){
    
    if(vis[i][j] == 2) return 0;
    
    int cnt = 0;
    
    if(!vis[i][j]){
        grid[i][j] = '1';
        for(auto ni : {i+1, i-1, i})
        for(auto nj : {j+1, j-1, j}) if(good(ni, nj)){
            vis[ni][nj] = 1;
        }
        cnt++;
    }
    
    vis[i][j] = 2;
    
    if(i == 0){
        if(j < m-1) return cnt + go(0, j+1);
        if(j == m-1) return cnt + go(1, m-1);
    }
    
    if(i == n-1){
        if(j != 0) return cnt + go(i, j-1);
        if(j == 0) return cnt + go(i-1, j);
    }
    
    if(j == 0){
        return cnt + go(i-1, 0);
    }
    
    if(j == m-1){
        return cnt + go(i+1, j);
    }
    
    return cnt;
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
        
        memset(vis, 0, sizeof vis);    
        memset(grid, 0, sizeof grid);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            grid[i][j] = '0';
        
        int stPath = go(0, 0);
        
        for(int i = 0; i < n; i++) cout << grid[i] << endl;
        cout << endl;
    }	
}
