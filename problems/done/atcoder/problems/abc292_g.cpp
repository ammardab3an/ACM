// Problem: G - Count Strictly Increasing Sequences
// Contest: AtCoder - AtCoder Beginner Contest 292
// URL: https://atcoder.jp/contests/abc292/tasks/abc292_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
const int MOD = 998244353; // 1e9 + 7;
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
 
const int NMAX = 40 + 5;

int n, m;
string arr[NMAX];
int mem[NMAX][NMAX][NMAX];
int mem2[NMAX][NMAX][NMAX][10];
int pre[10][NMAX][NMAX];
int go(int l, int r, int p);

void init(){
	
	for(int d = 0; d < 10; d++)
	for(int lvl = 0; lvl < m; lvl++)
	for(int i = 0; i < n; i++){
		
		bool gd = (arr[i][lvl]=='?') || ((arr[i][lvl]-'0')==d);
		
		if(gd){
			if(i){
				pre[d][lvl][i] = pre[d][lvl][i-1] + 1;
			}
			else{
				pre[d][lvl][i] = 1;
			}
		}
		else{
			pre[d][lvl][i] = 0;
		}
	}	
}

bool good(int l, int r, int lvl, int d){
	int sm = pre[d][lvl][r-1];
	return sm >= (r-l);
}

int calc(int p, int r, int lvl, int d){
	
	if(p==r){
		return 1;
	}
	
	if(d==10){
		return 0;
	}
	
	int &ret = mem2[p][r][lvl][d];
	if(ret+1) return ret;
	
	int ans = 0;
	
	{
		int cans = calc(p, r, lvl, d+1);
		ans = add(ans, cans);
	}
	
	int mx = (lvl==m-1) ? p+1 : r;
	
	for(int i = p; i < mx; i++){
		if(good(p, i+1, lvl, d)){
			int st_path = go(p, i+1, lvl+1);
			int nd_path = calc(i+1, r, lvl, d+1);
			ans = add(ans, mul(st_path, nd_path));
		}
	}
	
	return ret = ans;
}

int go(int l, int r, int lvl){
	
	if(lvl==m){
		return 1;
	}
	
	int &ret = mem[l][r][lvl];
	if(ret+1) return ret;
	
	int ans = calc(l, r, lvl, 0);
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    init();
    
    memset(mem, -1, sizeof mem);
    memset(mem2, -1, sizeof mem2);
    
    int ans = go(0, n, 0);
    cout << ans << endl;
}
