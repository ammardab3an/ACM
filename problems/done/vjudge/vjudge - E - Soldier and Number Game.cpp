// Problem: E - Soldier and Number Game
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/E
// Memory Limit: 262 MB
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

const int  MAX = 2e5 + 10;
const int NMAX = 5e6 + 10;
const int MMAX = 2e5 + 10;

vl primes;
int isNotPrime[NMAX];
int mem[NMAX];

void fillPrimes(){
    
    for(lli i = 2; i < NMAX; i++) if(!isNotPrime[i]){
        primes.push_back(i);
        for(lli j = i*i; j < NMAX; j += i){
            isNotPrime[j] = 1;
        }
    }
}

int go(int num){
    if(num == 1) return 0;
    if(mem[num] != -1) return mem[num];
    for(auto i : primes){
        if(i*i > num) break;
        if(num%i==0){
            return mem[num] = 1 + go(num/i);
        }
    }
    return mem[num] = 1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    fillPrimes();
    memset(mem, -1, sizeof mem);
    for(int i = 5000000; i > 0; i--) go(i);
    for(int i = 1; i <= 5000000; i++) mem[i] += mem[i-1];
    
    int t; cin >> t; while(t--){
        
        int a, b;
        cin >> a >> b;    
        cout << mem[a] - mem[b] << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
