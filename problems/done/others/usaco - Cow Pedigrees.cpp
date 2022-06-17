// Problem: 奶牛家谱 Cow Pedigrees
// Contest: Virtual Judge - %E6%B4%9B%E8%B0%B7
// URL: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1472
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
const int MOD = 9901; // 1e9 + 7;
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

int mem1[1010][1010];
int mem2[1010][1010];

int countEqual(int n, int h);

int countLess(int n, int h){
	
	if(h==1){
		return 0;
	}
	
	int &ret = mem1[n][h];
	if(ret+1) return ret;
	
	return ret = add(countLess(n, h-1), countEqual(n, h-1));
}

int countEqual(int n, int h){
	
	if(h==1){
		return n==1;
	}
	
	int &ret = mem2[n][h];
	if(ret+1) return ret;
	
	int ans = 0;
	
	int i = 1;
	int j = n-2;
	
	while(i <= j){
		
		int st_path = mul(countEqual(i, h-1), countLess(j, h-1));		
		int nd_path = mul(countLess(i, h-1), countEqual(j, h-1));
		int rd_path = mul(countEqual(i, h-1), countEqual(j, h-1));
		
		ans = add(ans, add(mul(2, add(st_path, nd_path)), rd_path));
		
		i+=2;
		j-=2;
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	memset(mem1, -1, sizeof mem1);
	memset(mem2, -1, sizeof mem2);
	
	int n, h;
	while(cin >> n >> h){
		int ans = countEqual(n, h);
		cout << ans << endl;
	}
}
