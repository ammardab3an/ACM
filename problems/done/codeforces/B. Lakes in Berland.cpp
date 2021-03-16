// Problem: B. Lakes in Berland
// Contest: Codeforces - Level 2 Contest 5
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/319609/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, k;
char grid[55][55];
int vis[55][55];
pii mvArr[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool good(int i , int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int bfs(int i, int j, bool color){
    
    queue<pii> que;
    que.push({i, j});
    vis[i][j] = true;
    
    int sz = 0;
    bool b = true;
    
    while(!que.empty()){
        
        auto fr = que.front(); que.pop();
        
        int ci = fr.first;
        int cj = fr.second;
       
        sz ++;
        
        if(ci == 0 || ci == n-1 || cj == 0 || cj == m-1) b = false;
        
        if(color) grid[ci][cj] = '*';
        
        for(auto p : mvArr){
            
            int ni = ci + p.first;
            int nj = cj + p.second;
            
            if(good(ni, nj) && !vis[ni][nj] && grid[ni][nj] == '.'){
                vis[ni][nj] = true;
                que.push({ni, nj});
            }
        }
    }  
    
    return b * sz;  
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> grid[i];
    
    vector<pair<int, pii> > vec;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(grid[i][j] == '.' && !vis[i][j]) {
        int sz = bfs(i, j, 0);
        if(sz > 0) vec.push_back({sz, {i, j}});
    }
    
    sort(vec.begin(), vec.end());
    
    int ans_sz = 0;
    
    memset(vis, 0, sizeof vis);
    
    for(int i = 0; i < (vec.size() - k); i++){
        ans_sz += vec[i].first;
        int ci = vec[i].second.first;
        int cj = vec[i].second.second;
        bfs(ci, cj, 1);
    }
    
    cout << ans_sz << endl;
    for(int i = 0; i < n; i++) cout << grid[i] << endl;;
}
