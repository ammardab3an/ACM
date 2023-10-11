#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Problem: D. Bear and Cavalry
// Contest: Codeforces - Codeforces Round 318 [RussianCodeCup Thanks-Round] (Div. 1)
// URL: https://codeforces.com/contest/573/problem/D?f0a28=1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int NMAX = 3e4 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
int arr[2][NMAX];
int32_t pos[2][NMAX];
int32_t _pos[2][NMAX];
int dp[NMAX];

int32_t main(){
    
    fastIO;
    
    cin >> n >> m;
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    for(int i = 0; i < 2; i++){	
    	
    	iota(pos[i], pos[i]+n, 0);
    	
    	sort(pos[i], pos[i]+n, [&](int p, int q){
    		return arr[i][p] < arr[i][q];
    	});
    	
    	for(int j = 0; j < n; j++){
    		_pos[i][pos[i][j]] = j;
    	}
	}
	
    while(m--){
    	
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    		
		swap(arr[1][l], arr[1][r]);
    	swap(pos[1][_pos[1][l]], pos[1][_pos[1][r]]);
    	swap(_pos[1][l], _pos[1][r]);
	    
	    for(int j = 1; j <= n; j++){
	    	
	    	int i = j-1;
	    	int ans = -INFLL;
	    	
	    	{
				int i0 = pos[0][i];
				int i1 = pos[1][i];
				
				if(i0 != i1){
					int cans = (arr[0][i0]*arr[1][i1]) + dp[j-1];
					ans = max(ans, cans);	
				}
	    	}
			
			if(i-1 >= 0) {
				
				int i0 = pos[0][i];
				int i1 = pos[1][i];
				int j0 = pos[0][i-1];
				int j1 = pos[1][i-1];
				
				if(i0==i1 || j0==j1) swap(i1, j1);
				
				int cans = (arr[0][i0]*arr[1][i1] + arr[0][j0]*arr[1][j1]) + dp[j-2];
				ans = max(ans, cans);
			}
			
			if(i-2 >= 0){
				
				int i0 = pos[0][i];
				int i1 = pos[1][i];
				int j0 = pos[0][i-1];
				int j1 = pos[1][i-1];
				int k0 = pos[0][i-2];
				int k1 = pos[1][i-2];
				
				if(i0 != j1){
					swap(i1, j1);
					bool b = false;
					if(j0==j1 || k0==k1) swap(j1, k1), b = true;
					int cans = (arr[0][i0]*arr[1][i1] + arr[0][j0]*arr[1][j1] + arr[0][k0]*arr[1][k1]) + dp[j-3];
					ans = max(ans, cans);
					if(b) swap(j1, k1);
					swap(i1, j1);
				}
				
				if(i0 != k1){
					swap(i1, k1);
					swap(j1, k1);
					if(j0==j1 || k0==k1) swap(j1, k1);
					int cans = (arr[0][i0]*arr[1][i1] + arr[0][j0]*arr[1][j1] + arr[0][k0]*arr[1][k1]) + dp[j-3];
					ans = max(ans, cans);
				}
			}
	    	
	    	dp[j] = ans;
	    }
	    
	    cout << dp[n] << endl;
    }
}
