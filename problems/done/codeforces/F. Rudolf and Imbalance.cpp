// Problem: F. Rudolf and Imbalance
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/contest/1941/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n, m, k;
		cin >> n >> m >> k;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi tmp0(m);
		for(auto &i : tmp0) cin >> i;
		
		vi tmp1(k);
		for(auto &i : tmp1) cin >> i;
		
		sort(vec.begin(), vec.end());
		sort(tmp0.begin(), tmp0.end());
		sort(tmp1.begin(), tmp1.end());
		
		int mx = vec[1]-vec[0];
		int mx_i = 1;
		int mx_c = 1;
		
		for(int i = 2; i < n; i++){
			if(vec[i]-vec[i-1] > mx){
				mx = vec[i]-vec[i-1];
				mx_i = i;
				mx_c = 1;
			}
			else if(vec[i]-vec[i-1] == mx){
				mx_c++;
			}
		}
		
		if(mx_c > 1){
			cout << mx << endl;
			continue;
		}
		
		int mx0 = mx;
		int mx1 = 0;
		
		for(int i = 1; i < n; i++){
			int dif = vec[i]-vec[i-1];
			if(dif < mx0) mx1 = max(mx1, dif);
		}
		
		int a = vec[mx_i];
		int b = vec[mx_i-1];
		int dif = b-a;
		int x0 = (a+b)/2;
		int x1 = (a+b+1)/2;
		
		int ans = mx0;
		
		{
			int j = k-1;
			int mx_x = 0;
			
			for(int i = 0; i < m; i++){
				
				while(j >= 0 && tmp0[i]+tmp1[j] > x0){
					j--;
				}
				
				if(j >= 0){
					mx_x = max(mx_x, tmp0[i]+tmp1[j]);
				}
			}
			
			int cur = max(a-mx_x, mx_x-b);
			int cur_ans = max(cur, mx1);
			ans = min(ans, cur_ans);
		}
		
		{
			
			int mn_x = INFLL;
			
			int j = 0;
			while(j < k && tmp0[0]+tmp1[j] < x1){
				j++;
			}
			
			for(int i = 0; i < m; i++){
				
				while(j-1 >= 0 && tmp0[i]+tmp1[j-1] >= x1){
					j--;
				}	
				
				if(j < k){
					mn_x = min(mn_x, tmp0[i]+tmp1[j]);
				}
			}
			
			int cur = max(a-mn_x, mn_x-b);
			int cur_ans = max(cur, mx1);
			ans = min(ans, cur_ans);
		}
		
		cout << ans << endl;
    }	
}
