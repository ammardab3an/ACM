// Problem: D. Cut and Stick
// Contest: Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/contest/1514/problem/D
// Memory Limit: 512 MB
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

const int NMAX = 3e5 + 10;
const int MMAX = 3e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];


int n, m, cans;
int arr[NMAX];
int cnt[NMAX];
int frq[NMAX];
int ans[MMAX];

void add(int idx){
    frq[cnt[arr[idx]]]--;
    frq[++cnt[arr[idx]]]++;
    cans = max(cans, cnt[arr[idx]]);
}

void rem(int idx){
    frq[cnt[arr[idx]]]--;
    frq[--cnt[arr[idx]]]++;
    if(!frq[cans]) cans--;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < m; i++){
        cin >> q[i].lo >> q[i].hi;
        q[i].lo--, q[i].hi--, q[i].idx= i;
    }
    
    sort(q, q+m);
    
    int l = 1, r = 0;
    for(int i = 0; i < m; i++){

        int cl = q[i].lo;
        int cr = q[i].hi;
        int ci = q[i].idx;

        while(r < cr) add(++r);
        while(cl < l) add(--l);
        while(cr < r) rem(r--);
        while(l < cl) rem(l++);
        
        int mx = cans;
        int tot = r-l+1;
        tot -= mx;
        
        // cout << mx << endl;
        
        int c = (r-l+1+1)/2;
        
        if(mx <= c){
            ans[ci] = 1;
        }
        else{
            ans[ci] = 1 + (mx-(tot+1));
        }
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
