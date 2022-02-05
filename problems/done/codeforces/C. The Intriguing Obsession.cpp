// Problem: C. The Intriguing Obsession
// Contest: Codeforces - Codeforces Round #439 (Div. 2)
// URL: https://codeforces.com/problemset/problem/869/C
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
const int MOD = 998244353; //1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
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


int cho[5050][5050];
int fac[5050], ifac[5050];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < 5050; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[5050-1] = pow_exp(fac[5050-1], MOD-2);
	for(int i = 5050-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	return mul(fac[n], mul(ifac[c], ifac[n-c]));	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int mn_0 = min(a, b);
    int mn_1 = min(b, c);
    int mn_2 = min(c, a);
    
	int cans_2 = 0;
    for(int k = 0; k <= mn_2; k++){
		int tt = mul(choose(a, k), choose(c, k));
    	tt = mul(tt, fac[k]);	
    	cans_2 = add(cans_2, tt);
    }
    
	int cans_1 = 0;
    for(int j = 0; j <= mn_1; j++){
    	int tt = mul(choose(b, j), choose(c, j));
    	tt = mul(tt, fac[j]);	
    	cans_1 = add(cans_1, tt);
    }
    
	int cans_0 = 0;
    for(int i = 0; i <= mn_0; i++){
    	int tt = mul(choose(a, i), choose(b, i));
    	tt = mul(tt, fac[i]);	
    	cans_0 = add(cans_0, tt);
    }
    
	int ans = mul(cans_0, mul(cans_1, cans_2));	
	
    cout << ans << endl;
}
