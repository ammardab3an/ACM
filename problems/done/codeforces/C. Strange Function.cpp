// Problem: C. Strange Function
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
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
    return (1ll * a%MOD + b%MOD + MOD + MOD) % MOD;
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

const int PMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    int sz = primes.size();
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        int ans = 0;
        
        for(int i = 0; i < sz; i++){
            
            int cp = 1;
            
            for(int k = 0; ; k++){
                
                int a = 1;
                int b = 1;
                
                a *= cp;
                cp *= primes[i];
                b *= cp;
                
                bool bad = false;
                
                for(int j = 0; j < sz; j++) if(j != i){
                    
                    int tp = 1;
                    while(tp*primes[j] < cp) tp *= primes[j];
                    
                    int _a = a, _b = b;
                        
                    a *= tp;
                    b *= tp;
                    
                    if(a/tp != _a || b/tp != _b){
                        bad = true;
                        break;
                    }    
                    
                    if(tp == 1) break;
                }
                
                if(bad) break;
                
                int ans0 = n/a;
                int ans1 = n/b;
                
                if(!ans0) break;
                
                int cur_ans = add(ans0, -ans1);
                
                ans = add(ans, mul(cp, cur_ans));
            }    
        }
        
        cout << ans << endl;
    }	
}
