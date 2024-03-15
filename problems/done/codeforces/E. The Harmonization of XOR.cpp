// Problem: E. The Harmonization of XOR
// Contest: Codeforces - TypeDB Forces 2023 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1787/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

		int n, k, x;
		cin >> n >> k >> x;
		
		int tot_xor = 0;
		for(int i = 1; i <= n; i++){
			tot_xor ^= i;
		}
		
		if(((k%2==1) && (tot_xor!=x)) || ((k%2==0) && (tot_xor!=0))){
			cout << "NO" << endl;
			continue;
		}
		
		vector<vi> ans;
			
		vi tmp;
		vi vis(n+1);
		vis[0] = true;
		
		for(int i = 0; i <= n; i++){
			
			if((ans.size()<k) && (i < (i^x)) && ((i^x)<=n)){
				if(i==0) ans.push_back({x});
				else ans.push_back({i, i^x});	
				vis[i] = vis[i^x] = true;
			}
			else if(!vis[i]){
				tmp.push_back(i);
			}
		}
		
		if(ans.size() != k){
			cout << "NO" << endl;
			continue;
		}
		
		int xor_rst = 0;
		for(auto e : tmp){
			xor_rst ^= e;
			ans.back().push_back(e);
		}
		
		assert(xor_rst==0);
		
		cout << "YES" << endl;
		for(auto &v : ans){
			cout << v.size() << ' ';
			for(auto &e : v) cout << e << ' ';
			cout << endl;
		}
    }	
}
