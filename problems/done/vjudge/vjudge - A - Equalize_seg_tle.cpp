// Problem: A - Equalize
// Contest: Virtual Judge - Contest 2
// URL: https://vjudge.net/contest/436948#problem/A
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
const int AMAX = 1e6 + 10;

int n, m, q;
int grid[1010][1010];
int tree[AMAX << 2];

set<int> st;
map<int, int> to, fr;

void update(int nd, int l, int r, int p, int val){
    
    if(l > p || p > r) return;
    
    if(l == r){
        tree[nd] += val;
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query(int nd, int l, int r, int k){
    
    if(l == r){
        return l;
    }    
    
    int mid = (l+r)/2;
    
    if(tree[nd*2] >= k) return query(nd*2, l, mid, k);
    else return query(nd*2+1, mid+1, r, k-tree[nd*2]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m >> q;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        cin >> grid[i][j];
        st.insert(grid[i][j]);
    }
    
    {
        int c = 1;
        for(auto i : st){
            to[i] = c;
            fr[c] = i;
            c++;
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) grid[i][j] = to[grid[i][j]];
    }
    
    while(q--){
                   
        int h, w;
        cin >> h >> w;
        
        for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) update(1, 1, AMAX, grid[i][j], 1);
        
        int ans = query(1, 1, AMAX, (h*w+1)/2);
        
        for(int i = 0; i+h-1 < n; i++){
            
            if(i%2==0){
                
                for(int j = 1; j+w-1 < m; j++){
                    
                    for(int ni = i; ni < i+h; ni++){
                        update(1, 1, AMAX, grid[ni][j-1], -1);
                        update(1, 1, AMAX, grid[ni][j+w-1], +1);
                    }
    
                    int cans = query(1, 1, AMAX, (h*w+1)/2);
                    ans = max(ans, cans);
                }            
                
                
                if(i+h < n){
                    
                    for(int j = m-w; j < m; j++){
                        update(1, 1, AMAX, grid[i][j], -1);
                        update(1, 1, AMAX, grid[i+h][j], +1);
                    }
                    
                    int cans = query(1, 1, AMAX, (h*w+1)/2);
                    ans = max(ans, cans);
                }
                else{
                    
                    for(int ni = i; ni < i+h; ni++)
                    for(int nj = m-w; nj < m; nj++)
                        update(1, 1, AMAX, grid[ni][nj], -1);
                }
            }
            
            else{
                
                for(int j = m-w-1; j >= 0; j--){
                    
                    for(int ni = i; ni < i+h; ni++){
                        
                        update(1, 1, AMAX, grid[ni][j+w], -1);
                        update(1, 1, AMAX, grid[ni][j], +1);
                    }
                    
                    int cans = query(1, 1, AMAX, (h*w+1)/2);
                    ans = max(ans, cans);
                }
                
                if(i+h < n){
                    
                    for(int j = 0; j < w; j++){
                        update(1, 1, AMAX, grid[i][j], -1);
                        update(1, 1, AMAX, grid[i+h][j], +1);
                    }
                    
                    int cans = query(1, 1, AMAX, (h*w+1)/2);
                    ans = max(ans, cans);
                }
                else{
                    
                    for(int ni = i; ni < i+h; ni++)
                    for(int nj = 0; nj < w; nj++)
                        update(1, 1, AMAX, grid[ni][nj], -1);
                }
            }
            
        }
        
        cout << fr[ans] << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
