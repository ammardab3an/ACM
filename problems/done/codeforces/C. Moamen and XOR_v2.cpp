// Problem: C. Moamen and XOR
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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

int fac[NMAX], ifac[NMAX];

void init(){
    
    fac[0] = 1;
    for(int i = 1; i < NMAX; i++) fac[i] = mul(fac[i-1], i);
    
    ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
    for(int i = NMAX-2; i >= 0; i--) ifac[i] = mul(ifac[i+1], i+1);
}

int choose(int n, int c){
    return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;
        
        int tmp_cho = 0;
        for(int i = 0; i < n; i+=2){
            tmp_cho = add(tmp_cho, choose(n, i));    
        }
        
        if(k==0){
            cout << 1 << endl;
            continue;    
        }
        
        int ans;
        
        if(n%2==0){
            
            int x_num = tmp_cho;
            int x_den = pow_exp(2, n);
            int x = mul(x_num, pow_exp(x_den, MOD-2));
            
            int s_nom = add(1, -pow_exp(x, k));
            int s_den = add(1, -x);
            int s = mul(s_nom, pow_exp(s_den, MOD-2));
            
            int c = pow_exp(2, (n*(k-1)) % (MOD-1));
            
            ans = add(mul(c, s), pow_exp(tmp_cho, k));
        }
        else{
            ans = pow_exp(add(1, tmp_cho), k);
        }
        
        cout << ans << endl;   
    }	
}

/*

n%2==0

ans = sum( tmp^i * 2^(n*(k-(i+1))) ) + tmp^k
    = 2^(n*(k-1)) * sum((tmp/(2^n))^i) + tmp^k
    : i {0, k-1}

n%2==1

ans = (1+tmp)^k

*/