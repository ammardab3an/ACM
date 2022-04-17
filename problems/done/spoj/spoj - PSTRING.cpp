// Problem: Remove The String
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PSTRING/en/
// Memory Limit: 1536 MB
// Time Limit: 1265 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

int n, m;
string x, y;
int y_pre[1010];
int mem[10010][1010];
int memo[1010][26];

int newL(int l, char c){
	int &ret = memo[l][c-'a'];
	if(ret+1) return ret;
	while(l && y[l] != c) l = y_pre[l-1];
	if(y[l]==c) l++;
	return ret = l;
}

void computePrefix(){
	y_pre[0] = 0;
	for(int i = 1; i < m; i++){
		y_pre[i] = newL(y_pre[i-1], y[i]);
	}
}

int go(int i, int j){
	
	if(j == m){
		return INF;
	}
	
	if(i == n){
		return 0;
	}
	
	int &ret = mem[i][j];
	if(ret+1) return ret;
	
	int st_path = 1 + go(i+1, j);
	int nd_path = go(i+1, newL(j, x[i]));
	
	return ret = min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    while(cin >> x >> y){
    	
    	n = x.size();
    	m = y.size();
    	
    	memset(mem, -1, sizeof mem);
    	memset(memo, -1, sizeof memo);
    	
    	computePrefix();
    	
    	int ans = go(0, 0);
    	cout << ans << endl;
    }
}
