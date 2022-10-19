// Problem: C. Bubble Strike
// Contest: Codeforces - Bubble Cup 14 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred, Div. 1)
// URL: https://codeforces.com/problemset/problem/1599/C
// Memory Limit: 256 MB
// Time Limit: 500 ms
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
 
const int NMAX = 1e3 + 10;

int mem[NMAX][NMAX];

int choose(int n, int c){
	
	if(n < c){
		return 0;
	}
	
	if(n==c || !c){
		return 1;
	}
	
	int &ret = mem[n][c];
	if(ret+1) return ret;
	
	return ret = choose(n-1, c) + choose(n-1, c-1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    memset(mem, -1, sizeof mem);
    
    int n;
    cin >> n;
    
    double p;
    cin >> p;
    
    int tot = choose(n, 3);
    
    for(int k = 0; k <= n; k++){
    	
    	int cnt_0 = choose(n-k, 3) * choose(k, 0);
    	int cnt_1 = choose(n-k, 2) * choose(k, 1);
    	int cnt_2 = choose(n-k, 1) * choose(k, 2);
    	int cnt_3 = choose(n-k, 0) * choose(k, 3);
    	
    	double p0 = double(cnt_0)/double(tot) * 0.0;
    	double p1 = double(cnt_1)/double(tot) * 0.5;
    	double p23 = double(cnt_2 + cnt_3)/double(tot) * 1.0;
    	
    	double cp = p0+p1+p23;
    	
    	if(cp >= p){
    		cout << k << endl;
    		break;
    	}
    }
}
