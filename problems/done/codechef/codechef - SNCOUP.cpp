	// Problem: Snakes and their coup against The mongoose
	// Contest: CodeChef - Practice
	// URL: https://www.codechef.com/problems/SNCOUP
	// Memory Limit: 256 MB
	// Time Limit: 1000 ms
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
	
	int32_t main(){
	    
	    fastIO;
	    
	#ifdef LOCAL
	    freopenI;
	    freopenO;
	#endif
	
	    // freopen("name.in", "r", stdin);
	    
	    int t; cin >> t; while(t--){
	
			int n;
			cin >> n;
			
			string a, b;
			cin >> a >> b;
			
			int st_path = 1;
			int nd_path = INF;
			
			bool lst_a = 0;
			bool lst_b = 0;
			
			bool found = false;
			
			for(int i = 0; i < n; i++){
				
				if(a[i]=='*' && b[i]=='*'){
					if(lst_a || lst_b){					
						st_path++;
					}
					lst_a = lst_b = 1;
					found = true;
				}
				else if(a[i]=='*'){
					if(lst_a){
						st_path++;
						lst_a = 1;
						lst_b = 0;
					}
					else{
						lst_a = 1;
					}
				}
				else if(b[i]=='*'){
					if(lst_b){
						st_path++;
						lst_a = 0;
						lst_b = 1;
					}
					else{
						lst_b = 1;
					}
				}
			}
			
			if(!found){
				int cnt = 0;
				for(int i = 0; i < n; i++){
					cnt += a[i]=='*';
					cnt += b[i]=='*';
				}	
				nd_path = max(int(0), cnt-1);
			}
			
			cout << min(st_path, nd_path) << endl;
	    }	
	}
	