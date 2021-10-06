// Problem: G - Bitmap
// Contest: Virtual Judge - Contest 1
// URL: https://vjudge.net/contest/436651#problem/G
// Memory Limit: 1572 MB
// Time Limit: 4000 ms
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
char grid[200][200];
int dist[200][200];
pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m; 
}

void bfs(int i, int j){
    
    queue<iii> que;
    que.push({0, {i, j}});
    dist[i][j] = 0;
    
    while(!que.empty()){
        
        auto fr = que.front(); que.pop();
        
        int d = fr.first;
        int ci = fr.second.first;
        int cj = fr.second.second;
        
        for(auto p : mvArr){
            
            int ni = ci + p.first;
            int nj = cj + p.second;
            int nd = d + 1;
            
            if(in(ni, nj) && (dist[ni][nj] > nd)){
                dist[ni][nj] = nd;
                que.push({nd, {ni, nj}});
            }
        }
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> grid[i];
        
        memset(dist, INF, sizeof dist);
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(grid[i][j] == '1'){
            bfs(i, j);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << dist[i][j] << ' '; 
            cout << endl;
        }
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
