// Problem: Chef and his study plans
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/SUBSEG2
// Memory Limit: 256 MB
// Time Limit: 750 ms
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e6 + 10;
const int LOG = ceil(log2(NMAX));

int n, q, sz;
int arr[NMAX];
int par[NMAX][LOG];
int dist[NMAX][LOG];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> q;

    memset(arr, INF, sizeof arr);

    for(int i = 0; i < n; i++){
        
        int l, r;
        cin >> l >> r; l--, r--;
        
        arr[l] = min(arr[l], r);
    }
    
    for(int i = 1e6; i >= 0; i--){
        arr[i] = min(arr[i+1], arr[i]);
    }
    
    memset(par, INF, sizeof par);
    
    for(int i = 1e6; i >= 0; i--){
        
        par[i][0] = arr[i];
        
        for(int j = 1; j < LOG; j++){
            if(par[i][j-1] < INF){            
                par[i][j] = par[par[i][j-1]+1][j-1];
            }
        }
    }
    
    while(q--){
        
        int l, r;
        cin >> l >> r;
        l--, r--;
        
        int ans = 0;
        
        for(int i = LOG-1; i >= 0; i--){
            
            if(par[l][i] <= r){

                l = par[l][i]+1;
                ans += 1 << i;
            }
        }
        
        cout << ans << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    