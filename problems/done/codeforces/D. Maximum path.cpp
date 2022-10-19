// Problem: D. Maximum path
// Contest: Codeforces - Educational Codeforces Round 17
// URL: https://codeforces.com/contest/762/problem/D
// Memory Limit: 256 MB
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

int n;
int arr[3][NMAX];
int mem[3][NMAX][1<<3];
bool vis[3][NMAX][1<<3];

int go(int i, int j, int msk){
	
	if(i==2 && j==n-1){
		return 0;
	}
	
	int &ret = mem[i][j][msk];
	if(vis[i][j][msk]) return ret;
	vis[i][j][msk] = true;
	
	int ans = -1e18;
	
	if((i==0) && (msk==0b001) && (j+1<n)){
		int cans = arr[0][j+1] + arr[1][j+1] + arr[1][j] + arr[2][j] + arr[2][j+1] + go(2, j+1, 0b111);
		ans = max(ans, cans);
	}
	
	if((i==2) && (msk==0b100) && (j+1<n)){
		int cans = arr[2][j+1] + arr[1][j+1] + arr[1][j] + arr[0][j] + arr[0][j+1] + go(0, j+1, 0b111);
		ans = max(ans, cans);
	}
	
	if(j+1 < n){
		int cans = arr[i][j+1] + go(i, j+1, 1<<i);
		ans = max(ans, cans);	
	}
	
	if((i-1 >= 0) && (((msk>>(i-1))&1)==0)){
		int cans = arr[i-1][j] + go(i-1, j, msk|(1<<(i-1)));
		ans = max(ans, cans);
	}
	
	if((i+1 <= 2) && (((msk>>(i+1))&1)==0)){
		int cans = arr[i+1][j] + go(i+1, j, msk|(1<<(i+1)));
		ans = max(ans, cans);
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
    
    cin >> n;
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];
	
	int ans = arr[0][0] + go(0, 0, 0b001);
	
	cout << ans << endl;
}
