// Problem: Permutation Swaps
// Contest: CodeChef - May Cook-Off 2021 Division 3
// URL: https://www.codechef.com/COOK129C/problems/P7SWAPS
// Memory Limit: 256 MB
// Time Limit: 500 ms
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
 

const int NMAX = 1E5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n;
int arr[NMAX];
int tmp[NMAX];
int par[LOG_MAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n; i++) cin >> tmp[i];
        
        for(int i = 0; i < n; i++){
            par[0][tmp[i]-1] = i;
        }
        
        int LOG = ceil(log2((double)n));
        
        for(int i = 1; i < LOG; i++){
            for(int j = 0; j < n; j++)
                par[i][j] = par[i-1][par[i-1][j]];
        }
        
        int cnt = 0;
        
        auto get = [&](int i){
            
            int cur = i;
            for(int j = LOG-1; j >= 0; j--) if(cnt&(1 << j)){
                cur = par[j][cur];
            }
            
            return cur;
        };
        
        
        int q; cin >> q; while(q--){
            
            int x;
            cin >> x;
            
            if(x == 1){
                cnt++;
            }
            else if(x == 2){
                
                int l, r;
                cin >> l >> r;
                l--, r--;
                
                int i = get(l);
                int j = get(r);
                
                swap(arr[i], arr[j]);
            }
            else{
                int i;
                cin >> i; i--;
                cout << arr[get(i)] << endl;
            }
        }
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
