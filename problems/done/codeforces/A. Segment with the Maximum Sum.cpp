// Problem: A. Segment with the Maximum Sum
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
    
    int n, m;
    cin >> n >> m;
    
    #define PAIR pair<pll, pll>
    #define ANS first.first
    #define SUM first.second
    #define PRE second.first
    #define SUF second.second
    
    vector<PAIR> tree(2 * n);
    
    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        int fo = max(0, ai);
        tree[i + n] = {{fo, ai}, {fo, fo}};
    }
    
    auto merge = [](PAIR p0, PAIR p1){
            
        PAIR res;
        
        res.SUM = p0.SUM + p1.SUM;
        res.ANS = max({p0.ANS, p1.ANS, p0.SUF + p1.PRE});  
        res.PRE = max(p0.PRE, p0.SUM + p1.PRE);
        res.SUF = max(p1.SUF, p0.SUF + p1.SUM);
        
        return res;
    };
    
    for(int i = n-1; i > 0; i--) tree[i] = merge(tree[i*2], tree[i*2+1]);
    
    auto update = [&](int i, int v){
        i += n;
        int fo = max(v, 0);
        for(tree[i] = {{fo, v}, {fo, fo}}; i /= 2; ) tree[i] = merge(tree[i*2], tree[i*2+1]);    
    };
    
    auto query = [&](int l, int r){
        
        l += n;
        r += n;
        
        PAIR resl = {{0, 0}, {0, 0}};
        PAIR resr = {{0, 0}, {0, 0}};
            
        for(; l < r; l/=2, r/=2){
            if(l&1) resl = merge(resl, tree[l++]);
            if(r&1) resr = merge(tree[--r], resr);
        }
        
        return merge(resl, resr);
    };
    
    cout << query(0, n).ANS << endl;
    
    while(m--){
        
        int i, v;
        cin >> i >> v;
        
        update(i, v);
        cout << query(0, n).ANS << endl;        
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
