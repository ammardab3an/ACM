// Problem: D. Cut
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/D
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

const int NMAX = 1e5 + 10;
const int LOG = ceil(log2(NMAX));

int n, m;
int arr[NMAX];
int nxt[NMAX];
int pst[NMAX];
int notPrime[NMAX];
vi primes;
int par[LOG][NMAX];

void init(){
    
    primes.push_back(2);
    for(int i = 4; i < NMAX; i += 2) notPrime[i] = true;
    for(lli i = 3; i < NMAX; i += 2) if(!notPrime[i]){
        primes.push_back(i);
        for(lli j = i*i; j < NMAX; j += i) notPrime[j] = true;
    }
    
    for(int i = 0; i < NMAX; i++) pst[i] = n;
    
    nxt[n] = n;
    
    for(int i = n-1; i >= 0; i--){
        
        int mn = n;
        int tmp = arr[i];
        
        for(int p : primes){
            
            if(1ll*p*p > tmp) break;
            
            if(tmp%p==0){
                while(tmp%p==0) tmp/=p;
                mn = min(mn, pst[p]);
                pst[p] = i;            
            }
        }
        
        if(tmp != 1) mn = min(mn, pst[tmp]), pst[tmp] = i;
        
        nxt[i] = min(mn, nxt[i+1]);;
    }
    
    // for(int i = 0; i < n; i++) cout << nxt[i] << ' ';
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    init();
    
    memset(par, -1, sizeof par);
    
    for(int i = 0; i <= n; i++) par[0][i] = nxt[i];
    
    for(int i = 1; i < LOG; i++)
    for(int j = 0; j < n; j++){
        par[i][j] = par[i-1][par[i-1][j]];
    }
    
    for(int i = 0; i < m; i++){
        
        int l, r;
        cin >> l >> r; l--, r--;
        
        int cur = l;
        int cnt = 0;
        
        for(int i = LOG-1; i >= 0; i--){
            
            if(par[i][cur] != -1 && par[i][cur] <= r){
                
                cnt += 1 << i;
                cur = par[i][cur];
            }
        }
        
        cout << cnt+1 << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
