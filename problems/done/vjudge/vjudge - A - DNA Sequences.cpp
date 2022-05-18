// Problem: A - DNA Sequences
// Contest: Virtual Judge - Dynamic Programming Week 3
// URL: https://vjudge.net/contest/490538#problem/A
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
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

int n, m, k;
string str_a, str_b;
int mem0[1010][1010];
int mem1[1010][1010][2];
int vis0[1010][1010];
int vis1[1010][1010][2];
int vid;

int calc(int i, int j){
	
	if(i>=n || j>=m){
		return 0;
	}
	
	if(str_a[i] != str_b[j]){
		return 0;
	}
	
	if(vis0[i][j] == vid){
		return mem0[i][j];
	}
	else{
		vis0[i][j] = vid;
	}
	
	return mem0[i][j] = 1 + calc(i+1, j+1);
}

int go(int i, int j, bool b){
	
	if(i>=n || j>=m){
		return 0;
	}
	
	if(vis1[i][j][b] == vid){
		return mem1[i][j][b];
	}
	else{
		vis1[i][j][b] = vid;
	}
	
	int st_path = go(i+1, j, 0);
	int nd_path = go(i, j+1, 0);
	int rd_path = 0;
	int th_path = 0;
	
	if(calc(i, j) >= k){
		rd_path = k + go(i+k, j+k, 1);	
	}
	
	if(b && (str_a[i]==str_b[j])){
		th_path = 1 + go(i+1, j+1, 1);
	}
	
	return mem1[i][j][b] = max({st_path, nd_path, rd_path, th_path});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    while(cin >> k, k){
    	
    	cin >> str_a >> str_b;
    	
    	n = str_a.size();
    	m = str_b.size();
    	
    	vid++;
    	
    	int ans = go(0, 0, 0);
    	cout << ans << endl;
    }
    
    return 0;
}
