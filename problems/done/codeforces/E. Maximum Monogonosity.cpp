// Problem: E. Maximum Monogonosity
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/contest/1859/problem/E
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int arr[2][3003];
int mem[3003][3003][5];

int go(int i, int k, int b){
	
	if(k < 0){
		return -INFLL;
	}
	
	if(i >= n){
		return !b ? 0 : -INFLL;
	}
	
	int &ret = mem[i][k][b];
	if(ret+1) return ret;
	
	int ans = -INFLL;
	
	if(!b){
		ans = go(i+1, k, 0);	
	}
	
	if(b){
		int cans = go(i+1, k-1, b);
		ans = max(ans, cans);
	}
	
	if(!b){
		int cans = go(i+1, k-1, 0);
		cans += 2 * abs(arr[0][i] - arr[1][i]);
		ans = max(ans, cans);
	}
	
	if(!b){
		for(int j = 0; j < 4; j++){
			int cans = go(i+1, k-1, j+1);
			cans += (j&1) ? arr[0][i] : -arr[0][i];
			cans += (j&2) ? arr[1][i] : -arr[1][i];
			ans = max(ans, cans);
		}
	}
	
	if(b){
		int cans = go(i+1, k-1, 0);
		cans += ((b-1)&1) ? -arr[1][i] : arr[1][i];
		cans += ((b-1)&2) ? -arr[0][i] : arr[0][i];
		ans = max(ans, cans);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		int k;
		cin >> n >> k;
		
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++) cin >> arr[i][j];
		
		for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
		for(int l = 0; l < 5; l++){
			mem[i][j][l] = -1;
		}
		
		int ans = go(0, k, 0);
		cout << ans << endl;
    }	
}
