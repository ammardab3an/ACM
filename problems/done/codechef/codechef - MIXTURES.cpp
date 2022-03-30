// Problem: Mixtures
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/MIXTURES
// Memory Limit: 256 MB
// Time Limit: 1818 ms
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
int arr[111];
int pre[111];
int mem[111][111];

inline int sm(int l, int r){
	return (pre[r] - pre[l] + arr[l]) % 100;
}

int go(int l, int r){
	
	if(l == r){
		return 0;
	}
	
	int &ret = mem[l][r];
	if(ret+1) return ret;
	
	int ans = INFLL;
	
	for(int i = l; i < r; i++){
		
		int cans = go(l, i) + go(i+1, r);
		cans += sm(l, i) * sm(i+1, r);
		
		ans = min(ans, cans);	
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
    
    while(cin >> n){
    	
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	
    	pre[0] = arr[0];
    	for(int i = 1; i < n; i++){
    		pre[i] = pre[i-1] + arr[i];
    	}
    	
    	memset(mem, -1, sizeof mem);
    	
    	cout << go(0, n-1) << endl;
    }
}
