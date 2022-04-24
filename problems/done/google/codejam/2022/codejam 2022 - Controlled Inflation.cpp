// Problem: Controlled Inflation
// Contest: Google Coding Competitions - Round 1B 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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

int n, m;
int arr[NMAX][2];
int mem[NMAX][2];

int go(int i, bool lst){
	
	if(i==n){
		return 0;
	}	
	
	int &ret = mem[i][lst];
	if(ret+1) return ret;
	
	if(i==0){
		int st_path = 2*arr[0][1]-arr[0][0] + go(1, 0);
		int nd_path = arr[0][1] + go(1, 1);
		return ret = min(st_path, nd_path);
	}
	
	int st_path = abs(arr[i-1][lst] - arr[i][0]) + (arr[i][1] - arr[i][0]) + go(i+1, 1);
	int nd_path = abs(arr[i-1][lst] - arr[i][1]) + (arr[i][1] - arr[i][0]) + go(i+1, 0);
	
	return ret = min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int tt = 1;
    int t; cin >> t; while(t--){

		cout << "Case #" << tt++ << ": ";
		
		cin >> n >> m;
		
		for(int i = 0; i < n; i++){
			
			vi vec(m);
			for(auto &i : vec) cin >> i;
			
			int mn = *min_element(vec.begin(), vec.end());
			int mx = *max_element(vec.begin(), vec.end());
			
			arr[i][0] = mn;
			arr[i][1] = mx;
		}
		
		memset(mem, -1, sizeof mem);
		
		int ans = go(0, 0);
		cout << ans << endl;
    }	
}
