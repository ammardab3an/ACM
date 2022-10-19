// Problem: A. Ivan the Fool and the Probability Theory
// Contest: Codeforces - Codeforces Round #594 (Div. 1)
// URL: https://codeforces.com/contest/1239/problem/A
// Memory Limit: 512 MB
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

int mem[NMAX][2][2];

int go(int i, bool b0, bool b1){
	
	if(i==0){
		return 1;	
	}
	
	int &ret = mem[i][b0][b1];
	if(ret+1) return ret;
	
	int ans = 0;
	
	if(b1){
		ans = go(i-1, !b0, 0);	
	}
	else{
		int st_path = go(i-1, !b0, 0);
		int nd_path = go(i-1, b0, 1);
		ans = add(st_path, nd_path);
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
    
    int n, m;
    cin >> n >> m;
    
    memset(mem, -1, sizeof mem);
    
    int st_path = go(n-1, 0, 0);
    int nd_path = go(n-1, 1, 0);
    int rd_path = go(m-1, 0, 0);
    int th_path = go(m-1, 1, 0);

	// cout << st_path << ' ' << nd_path << ' ' << rd_path << ' ' << th_path << endl;
	    
    int ans = add(add(st_path, nd_path), add(rd_path, th_path));
    
    ans = add(ans, -2);
    
    cout << ans << endl;
}

/*

xxx
xxx

010
010

010
101

101
101

101
010

00
01
11
10

*/