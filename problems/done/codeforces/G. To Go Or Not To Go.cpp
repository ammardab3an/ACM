// Problem: G. To Go Or Not To Go?
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/G
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
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

int n, m, w;
int grid[2020][2020];
bool vist[2020][2020];
int dist[2020][2020];
pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool good(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

iii bfs(int i, int j){
    
    memset(vist, 0, sizeof vist);
    
    vist[i][j] = true;
    queue<iii> que;    
    que.push({0, {i, j}});
    
    iii ans = {INFLL, {-1, -1}};
    
    while(!que.empty()){
        
        auto fr = que.front(); que.pop();
        
        int cdis = fr.first;
        int ci = fr.second.first;
        int cj = fr.second.second;
        
        if(!i && !j) dist[ci][cj] = cdis;
        
        if(grid[ci][cj]){
            if(grid[ci][cj] + cdis * w < ans.first){
                ans = {grid[ci][cj] + cdis * w, fr.second};
            }
        }
        
        for(auto p : mvArr){
            
            int ni = ci + p.first;
            int nj = cj + p.second;
            int ndis = cdis + 1;
            
            if(!good(ni, nj) || vist[ni][nj] || grid[ni][nj] == -1) continue;
            
            vist[ni][nj] = true;
            que.push({ndis, {ni, nj}});
        }
    }
    
    return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    memset(dist, INF, sizeof dist);
    
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
    
    iii p0 = bfs(0, 0);
    iii p1 = bfs(n-1, m-1);
    
    int ans = INFLL;
    
    if(dist[n-1][m-1] != INFLL) ans = dist[n-1][m-1] * w;
    
    if(p0.first < INFLL && p1.first < INFLL){
        ans = min(ans, p0.first + p1.first - (p0.second == p1.second) * grid[p0.second.first][p0.second.second]);
    }
    
    if(ans < INFLL){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
        
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
