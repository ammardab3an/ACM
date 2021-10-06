// Problem: F - Coprime Present
// Contest: AtCoder - Panasonic Programming Contest (AtCoder Beginner Contest 195)
// URL: https://atcoder.jp/contests/abc195/tasks/abc195_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

auto print = [](int msk){
    for(int i = 20-1; i >= 0; i--) cout << bool(msk & (1 << i));
    cout << endl;
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int A, B;
    cin >> A >> B;
    
    vi primes;
    for(int i = 2; i <= B-A; i++){
        bool isPrime = true;
        for(int j = 2; j < i; j++) if(i%j==0){
            isPrime = false;
            break;
        }
        if(isPrime) primes.push_back(i);
    }
    
    vi msks(B-A+1);
    
    for(int num = A; num <= B; num++){
        
        int msk = 0;
        for(int i = 0; i < primes.size(); i++){
            if((num) % primes[i] == 0){
                msk |= 1 << i;
            }
        }
        
        msks[num - A] = msk;
    }
    
    vi dp(1 << primes.size());
    
    dp[0] = 1;
    
    for(int num = A; num <= B; num++){
        
        int msk = msks[num - A];
        
        int nmsk = (~msk) & ((1 << primes.size()) -1);
        
        for(int p = nmsk; ; p = (p-1) & nmsk){
            dp[msk | p] += dp[p];
            if(!p) break;
        }
    }
    
    cout << accumulate(dp.begin(), dp.end(), 0);
}
