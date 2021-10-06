// Problem: S - Digit Sum
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_s
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

int d, n;
string k;

int mem[10010][110][2];

string num;

int go(int pos, int mod, bool lower){
    
    if(pos == n) return !mod;
    
    int &ret = mem[pos][mod][lower];
    if(ret + 1) return ret;
    
    int ans = 0;
    
    int mx = lower ? 9 : k[pos] - '0';
    
    for(int i = 0; i <= mx; i++){
        
        num.push_back(i + '0');
        (ans += go(pos+1, (mod + i) % d, lower || (i != (k[pos] - '0')))) %= MOD;
        num.pop_back();
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> k >> d; n = k.size();
    memset(mem, -1, sizeof mem);
    cout << go(0, 0, 0) - 1;
}
