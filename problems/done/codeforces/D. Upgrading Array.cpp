// Problem: D. Upgrading Array
// Contest: Codeforces - Codeforces Round #236 (Div. 2)
// URL: https://codeforces.com/problemset/problem/402/D
// Memory Limit: 256 MB
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

const int NMAX = 5e3 + 10;

int n, m;
int arr[NMAX];
int bad[NMAX];
int notPrime[32000];
int calc_arr[NMAX];
int calc_gcd[NMAX];
int mem[NMAX][NMAX];
vi primes;

void sieve(){
    
    for(lli i = 2; i < 32000; i++) if(!notPrime[i]){
        primes.emplace_back(i);
        for(lli j = i*i; j < 32000; j += i) notPrime[j] = true;
    }
    
}

int calc(int num){
    
    int res = 0;
    int tmp = num;
    
    for(auto p : primes){   
        if(1ll*p*p > num) break;
        while(num%p==0) num/=p, res++;
    }
    if(num!=1) res++;
    
    num = tmp;
    for(int i = 0; i < m; i++){
        while(num%bad[i]==0) num/=bad[i], res-=2;
    }
    
    return res;
}

int go(int i, int g){
    
    if(i == -1) return 0;
    
    int &ret = mem[i][g];
    if(ret+1) return ret;
    
    int stPath = calc_arr[i] - calc_gcd[g] + go(i-1, g);
    int ndPath = calc_arr[i] - calc_gcd[i] + go(i-1, i);
    
    return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    sieve();
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> bad[i];
    
    for(int i = 0; i < n; i++) calc_arr[i] = calc(arr[i]);
    
    int pst_gcd = 0;
    for(int i = 0; i < n; i++){
        pst_gcd = __gcd(pst_gcd, arr[i]);
        calc_gcd[i] = calc(pst_gcd);
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(n-1, n) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
