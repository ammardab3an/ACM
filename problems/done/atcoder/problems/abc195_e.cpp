// Problem: E - Lucky 7 Battle
// Contest: AtCoder - Panasonic Programming Contest (AtCoder Beginner Contest 195)
// URL: https://atcoder.jp/contests/abc195/tasks/abc195_e
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

int n;
string num, turns;
int mem[NMAX][7];

inline int add(int a, int b){
    return (a+b)%7;
}

inline int mul(int a, int b){
    return (a*b)%7;
}

int fast_pow(int n, int p){
    if(!p) return 1;
    if(p&1) return (n * fast_pow(n, p-1))%7;
    int tmp = fast_pow(n, p/2);
    return (tmp * tmp)%7;
}

bool go(int pos, int rem){
    
    if(pos == n) return !rem;
    
    int &ret = mem[pos][rem];
    if(ret + 1) return ret;
    
    bool stPath = go(pos+1, rem);
    bool ndPath = go(pos+1, add(rem, mul(num[pos] - '0', fast_pow(10, n-pos-1))));
    
    int turn = turns[pos] == 'T';
    
    return ret = !turn ? min(stPath, ndPath) : max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> num >> turns;
    memset(mem, -1, sizeof mem);
    cout << (go(0, 0) ? "Takahashi" : "Aoki") << endl;
}
