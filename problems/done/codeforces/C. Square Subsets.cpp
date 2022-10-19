// Problem: C. Square Subsets
// Contest: Codeforces - Codeforces Round #448 (Div. 2)
// URL: https://codeforces.com/contest/895/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

int n;
int frq[71];
int imsk[71];
int mem[71][1<<19];
int pow2[NMAX];

void init(){
	pow2[0] = 1;
	for(int i = 1; i < NMAX; i++){
		pow2[i] = mul(pow2[i-1], 2);
	}
}

int go(int i, int msk){
	
	if(i==71){
		return msk==0;
	}
	
	int &ret = mem[i][msk];
	if(ret+1) return ret;
	
	int st_path = go(i+1, msk);
	int nd_path = 0;
	int rd_path = 0;
	
	if(frq[i] >= 1){	
		nd_path = mul(pow2[frq[i]-1], go(i+1, msk^imsk[i]));
	}
	if(frq[i] >= 2){	
		rd_path = mul(add(pow2[frq[i]-1], -1), go(i+1, msk));
	}
	
	int ans = add(st_path, add(nd_path, rd_path));
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	int ai;
    	cin >> ai;
    	frq[ai]++;
    }
    
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
    
    for(int i = 1; i <= 70; i++){
    	for(int j = 0; j < primes.size(); j++){
    		
    		int x = i;
    		int p = primes[j];
    		int cnt = 0;
    		
    		while(x && (x%p==0)){
    			cnt++;
    			x /= p;
    		}
    		
    		if(cnt%2==1){
	    		imsk[i] |= 1 << j;			
    		}
    	}
    }
    
    init();
    memset(mem, -1, sizeof mem);
    
    int ans = go(1, 0);
    ans = add(ans, -1);
    
    cout << ans << endl;
}