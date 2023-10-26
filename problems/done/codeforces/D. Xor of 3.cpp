// Problem: D. Xor of 3
// Contest: Codeforces - Codeforces Round 743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/D
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

		int n;
		cin >> n;
		
		int sm = 0;
		
		vi vec(n);
		for(auto &i : vec) cin >> i, sm += i;
		
		if((sm%2==1) || (sm==n) || (sm==2 && n > 3 && n%2==0 && vec.front()==vec.back() && vec.front()==1)){
			cout << "NO" << endl;
			continue;
		}
		
		vi ans;
		bool bad = false;
		
		for(int i = 0; i < n; i++) if(vec[i]){
			
			int j = i;
			int cnt = 1;
			while(j+1 < n && vec[j+1]) j++, cnt++;
			
			while(cnt%2==1){
				if(j+2 < n && !vec[j+1] && !vec[j+2]){
					ans.push_back(j);
					vec[j+1] = vec[j+2] = 1;
					while(j+1 < n && vec[j+1]) j++, cnt++;
				}
				else if(j+2 < n && vec[j+2]){
					ans.push_back(j);
					vec[j] = vec[j+1] = vec[j+2] = 0;
					cnt -= 1;
					j -= 1;
				}
				else{
					assert(false);
				}
			}
				
			if(cnt){
				
				assert(cnt%2==0);
				
				if(i){
					for(int k = i-1; k < j; k+=2){
						ans.push_back(k);
						vec[k] = vec[k+1] = vec[k+2] = 0;
					}
				}
				else if(j+1 < n){
					for(int k = j+1; k > i; k -= 2){
						ans.push_back(k-2);
						vec[k] = vec[k-1] = vec[k-2] = 0;
					}
				}
				else{
					bad = true;
					break;
				}
			}	
		}
		
		if(bad){
			cout << "NO" << endl;
			continue;
		}
		
		// for(auto e : vec) assert(!e);
		// for(auto e : vec) cout << e << ' '; cout << endl;
		
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(auto e : ans) cout << e+1 << ' '; cout << endl;
    }	
}
