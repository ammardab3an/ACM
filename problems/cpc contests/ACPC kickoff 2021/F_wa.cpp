
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("protecting-memes.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, m;
        cin >> n >> m;
        
        string a, b;
        cin >> a >> b;
        
        string can;
        cin >> can;
        
        vi ans(n);
        for(int i = 0; i < n; i++) ans[i] = can[i] == '1';
        
        int i = n-1;
        int j = m-1; 
        
        vi cnt(n);
        int ccnt = 0;
        
        while(j >= 0){
            
            if((a[i] == b[j])){
                ccnt++;
                cnt[i] = ccnt;
                i--, j--;
            }
            else{
                cnt[i] = ccnt;
                i--;
            }
            
        }
        
        while(i >= 0) cnt[i--] = ccnt;
        
        // for(auto i : cnt) cout << i << ' ' ; cout << endl;
        
        j = 0;
        
        for(int i = 0; i+1 < n; i++){
            
            if(j == m) break;
            
            if(can[i] == '0'){
                if((a[i] == b[j]) && (m-j-1 <= cnt[i+1])){
                    j++;
                }
            }    
        }
        
        i = n-1;
        int k = m-1;
        
        // cout << j << endl;
        // for(auto i : ans) cout << i; cout << endl;
        
        while(j <= k){
            
            if((a[i] == b[k])){
                ans[i] = 0;
                i--, k--;
            }
            else{
                i--;
            }
        }
        
        for(auto i : ans) cout << i; cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
