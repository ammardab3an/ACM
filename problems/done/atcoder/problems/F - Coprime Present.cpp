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

int A, B;
vi primes;
int mem[75][1 << 20];

int go(int pos, int msk){
    
    if(A+pos == B+1) return 1;
    
    int &ret = mem[pos][msk];
    if(ret + 1) return ret;
    
    int stPath = go(pos+1, msk);
    int ndPath = 0;
    
    int nmsk = 0;
    for(int i = 0; i < primes.size(); i++){
        if((A+pos) % primes[i] == 0){
            nmsk |= 1 << i;
        }
    }
    
    if(!(msk & nmsk)){
        ndPath = go(pos+1, msk | nmsk);
    }
    
    return ret = stPath + ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> A >> B;
    
    for(int i = 2; i <= B-A; i++){
        bool isPrime = true;
        for(int j = 2; j < i; j++) if(i%j==0){
            isPrime = false;
            break;
        }
        if(isPrime) primes.push_back(i);
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, 0);
}
