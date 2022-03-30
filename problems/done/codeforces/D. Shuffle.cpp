// Problem: D. Shuffle
// Contest: Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1622/D
// Memory Limit: 512 MB
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
const int MOD = 998244353 ; //1e9 + 7;
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

int fac[NMAX], ifac[NMAX];

void init(){
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
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
    
    int n, k;
    cin >> n >> k;
    
    string str;
    cin >> str;
    
    {
    	int cnt = 0;
    	for(auto c : str) cnt += c=='1';
    	if(cnt < k){
    		cout << 1 << endl;
    		return 0;
    	}
    }
    
    int ans = 1;
    
    for(int i = 0; i < n; i++){
    	
    	int cnt_1 = 0;
    	
    	for(int j = i; j < n; j++){
    		
    		cnt_1 += str[j]=='1';
    		
    		if(cnt_1 > k) break;
    		if(i==j) continue;
    		
    		int c1 = cnt_1 - (str[i]=='0') - (str[j]=='0');
    		
    		if(j-i-1 >= c1 && c1 >= 0){
	    		int cans = choose(j-i-1, c1);
	    		ans = add(ans, cans);
    		}
    	}
    }
	 
    cout << ans << endl;
}
