// Problem: D. Magic Numbers
// Contest: Codeforces - Educational Codeforces Round 8
// URL: https://codeforces.com/problemset/problem/628/D
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

int add(int a, int b){
    return (1ll * a + b + MOD + MOD) % MOD;
}

int mul(int a, int b){
    return (1ll * a * b) % MOD;
}

int m, d, n;
char num[2020];
int mem[2020][2020][2][3];

int go(int i, int rem, bool b_l, int e){
    
    if(i == n) return !rem;
    
    int &ret = mem[i][rem][b_l][e+1];
    if(ret+1) return ret;
    
    if((e != -1) && ((i+e)%2 == 0)){
        
        int nd = d;
                
        if(!b_l && ((num[i]-'0') < nd))
            return ret = 0;
        else{
            int nrem = rem;
            nrem = (nrem * 10) % m;
            nrem = (nrem + nd) % m;
            return ret = go(i+1, nrem, b_l || (nd < (num[i]-'0')), e);
        }
    }
    
    int lo = 0;
    int hi = b_l ? 9 : num[i]-'0';
    
    int ans = 0;
    
    for(int nd = lo; nd <= hi; nd++){
        
        if((e == -1) && (nd == d)) continue;
        if((e != -1) && ((i+e)%2==1) && (nd == d)) continue;
        
        int nrem = rem;
        nrem = (nrem * 10) % m;
        nrem = (nrem + nd) % m;
        
        int ne = e;
        if(e == -1) ne = nd ? (i+1)%2 : -1;
        
        int tmp = go(i+1, nrem, b_l || (nd < (num[i]-'0')), ne);
        
        ans = add(ans, tmp);
    }    
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> m >> d;
    
    cin >> num;
    n = strlen(num);
    memset(mem, -1, sizeof mem);
    int lower = go(0, 0, 0, -1);
    
    int l_mod = 0;
    int good = true;
    for(int i = 0; i < n; i++){
        l_mod = (l_mod * 10) % m;
        l_mod = (l_mod + num[i]-'0') % m;
        good &= (i%2==1 && ((num[i]-'0') == d)) || (i%2==0 && ((num[i]-'0') != d));
    }
    
    if(good && !l_mod) lower--;
    
    cin >> num;
    n = strlen(num);
    memset(mem, -1, sizeof mem);
    int upper = go(0, 0, 0, -1);
    
    cout << add(upper, -lower) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
