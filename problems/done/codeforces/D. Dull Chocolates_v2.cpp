// Problem: D. Dull Chocolates
// Contest: Codeforces - 2018 Arab Collegiate Programming Contest (ACPC 2018)
// URL: https://codeforces.com/gym/101991/problem/D
// Memory Limit: 1024 MB
// Time Limit: 9000 ms
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

int calc(int n, int m, vpii vec){
	
	vector<vi> pre(n, vi(m));
	
	for(auto [i, j] : vec){
		pre[i-1][j-1]++;
	}	
	
	int ans = 0;
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		
		if(i) pre[i][j] += pre[i-1][j];
		if(j) pre[i][j] += pre[i][j-1];
		if(i&&j) pre[i][j] -= pre[i-1][j-1];
		
		ans += pre[i][j]%2==1;
	}
	
	return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, m, k;
		cin >> n >> m >> k;
		
		vpii vec(k);
		for(auto &[i, j] : vec){
			cin >> i >> j;
		}
		
		// cout << calc(n, m, vec) << endl;
		
		int sz_x, sz_y;
		vi comp_x, comp_y;
		{
			for(auto [i, j] : vec){
				comp_x.push_back(i);
				comp_y.push_back(j);
			}
			
			comp_x.push_back(0);
			comp_y.push_back(0);
			comp_x.push_back(1);
			comp_y.push_back(1);
			comp_x.push_back(n+1);
			comp_y.push_back(m+1);
			
			sort(comp_x.begin(), comp_x.end());
			comp_x.resize(unique(comp_x.begin(), comp_x.end())-comp_x.begin());
			
			sort(comp_y.begin(), comp_y.end());
			comp_y.resize(unique(comp_y.begin(), comp_y.end())-comp_y.begin());
			
			for(auto &[i, j] : vec){
				i = lower_bound(comp_x.begin(), comp_x.end(), i)-comp_x.begin();
				j = lower_bound(comp_y.begin(), comp_y.end(), j)-comp_y.begin();
			}
			
			sz_x = comp_x.size();
			sz_y = comp_y.size();
		}	 
		
		vector<vi> pre(sz_x, vi(sz_y));
		
		for(auto [i, j] : vec){
			pre[i][j] ^= 1;
		}
		
		for(int i = 0; i < sz_x; i++)
		for(int j = 0; j < sz_y; j++){
			if(i) pre[i][j] ^= pre[i-1][j];
			if(j) pre[i][j] ^= pre[i][j-1];
			if(i&&j) pre[i][j] ^= pre[i-1][j-1];
		}
		
		int ans = 0;
		
		for(int i = 0; i < sz_x-1; i++)
		for(int j = 0; j < sz_y-1; j++) if(pre[i][j]){
			
			int x0 = comp_x[i];
			int y0 = comp_y[j];
			
			int x1 = comp_x[i+1];
			int y1 = comp_y[j+1];
			
			ans += (x1-x0) * (y1-y0);
		}
		
		cout << ans << ' ' << n*m-ans << endl;
    }
}
