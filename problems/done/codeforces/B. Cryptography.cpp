// Problem: B. Cryptography
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B
// Memory Limit: 1024 MB
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int r, n, m;
    cin >> r >> n >> m;
    
    #define ARR array< array<int, 2>, 2>
    
    vector<ARR> tree(2 * n);
    
    for(int i = 0; i < n; i++){
        cin >> tree[i+n][0][0] >> tree[i+n][0][1] >> tree[i+n][1][0] >> tree[i+n][1][1];
    }
    
    auto merge = [&](ARR a0, ARR a1){
        
        ARR res = {(array<int, 2>){0, 0}, (array<int, 2>){0, 0}};
        
        for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++)  
        {
            (res[i][k] += (a0[i][j] * a1[j][k]) % r) %= r;
        }
        
        return res;
    };
    
    for(int i = n-1; i > 0; i--) tree[i] = merge(tree[i*2], tree[i*2+1]);
    
    while(m--){
        
        int l, r;
        cin >> l >> r;
        l--, r--;
        
        l += n;
        r += n + 1;
        
        ARR resl = {(array<int, 2>){1, 0}, (array<int, 2>){0, 1}};
        ARR resr = {(array<int, 2>){1, 0}, (array<int, 2>){0, 1}};
        
        for(; l < r; l/=2, r/=2){
            if(l&1) resl = merge(resl, tree[l++]);
            if(r&1) resr = merge(tree[--r], resr);
        }
        
        ARR res = merge(resl, resr);
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++) cout << res[i][j] << ' ';
            cout << endl;
        } cout << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
