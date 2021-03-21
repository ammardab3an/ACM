// Problem: A - Not coprime
// Contest: AtCoder - AtCoder Regular Contest 114
// URL: https://atcoder.jp/contests/arc114/tasks/arc114_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define lli int64_t

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

    int n;
    cin >> n;
    
    vi vec(n);
    for(int &i : vec) cin >> i;
    
    vi primes;
    for(int i = 2; i <= 50; i++){
        
        bool isPrime = true;
        for(int j = 2; j < i; j++) if(i%j==0){
            isPrime = false;
            break;
        }
        
        if(isPrime) primes.push_back(i);
    }
    
    lli ans = INFLL;
    
    int m = primes.size();
    
    int msk = (1 << m) -1;
    
    for(int perm = msk; perm; perm = (perm-1)&msk){
        
        lli num = 1;
        for(int i = 0; i < m; i++) if(perm & (1 << i)) num *= primes[i];
        
        bool coPrime = true;
        for(auto i : vec) if(gcd(i, num) == 1){
            coPrime = false;
            break;
        }
        
        if(coPrime) ans = min(ans, num);
    }
    
    cout << ans;
}
