// Problem: Y - Grid 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_y
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

#define x first
#define y second

inline int mul(int a, int b){
    return ((lli) a * b) % MOD;
}

inline int add(int a, int b){
    return ((lli) a + b + 2 * MOD) % MOD;
}

int fast_pow(int n, int p){
    if(!p) return 1;
    if(p&1) return mul(n, fast_pow(n, p-1));
    int tmp = fast_pow(n, p/2);
    return mul(tmp, tmp);
}

int fact[NMAX], ifact[NMAX];

void fill_fact(int n = NMAX){
    fact[0] = ifact[0] = 1;
    for(int i = 1; i < n; i++){
        fact[i] = mul(fact[i-1], i);
        ifact[i] = mul(ifact[i-1], fast_pow(i, MOD-2));
    }    
}

int choose(int n, int c){
    return mul(mul(fact[n], ifact[c]), ifact[n-c]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    //init
    fill_fact();
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vpii points(k);
    for(auto &p : points) cin >> p.x >> p.y;
    
    k++;
    points.emplace_back(n, m); 
    
    sort(points.begin(), points.end());
    
    vi ans;
    for(auto p : points)
        ans.emplace_back(choose(p.x + p.y -2, p.y -1));
        
    for(int i =  0 ; i < k; i++)
    for(int j = i+1; j < k; j++){
        
        int dx = points[j].x - points[i].x;
        int dy = points[j].y - points[i].y;
        
        if(dx < 0 || dy < 0) continue;
        
        ans[j] = add(ans[j], - mul(choose(dx+dy, dy), ans[i]));
    }
    
    cout << ans[k-1];
}
