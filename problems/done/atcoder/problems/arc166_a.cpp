// Problem: A - Replace C or Swap AB
// Contest: AtCoder - AtCoder Regular Contest 166
// URL: https://atcoder.jp/contests/arc166/tasks/arc166_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
		
		string str_a, str_b;
		cin >> str_a >> str_b;
		
		vector<vi> cnt_a(3);
		vector<vi> cnt_b(3);
		bool ans = true;
		
		auto check = [&](){
			
			if(cnt_a[0].size() > cnt_b[0].size()) return false;
			if(cnt_a[1].size() > cnt_b[1].size()) return false;
			
			while(cnt_a[1].size() < cnt_b[1].size()){
				cnt_a[1].push_back(cnt_a[2].back());
				cnt_a[2].pop_back();
			}
			
			while(cnt_a[0].size() < cnt_b[0].size()){
				cnt_a[0].push_back(cnt_a[2].back());
				cnt_a[2].pop_back();
			}
			
			sort(cnt_a[0].begin(), cnt_a[0].end());
			sort(cnt_a[1].begin(), cnt_a[1].end());
			
			assert(cnt_a[0].size() == cnt_b[0].size());
			assert(cnt_a[1].size() == cnt_b[1].size());
			
			// for(auto e : cnt_a[1]) cout << e << ' '; cout << endl;
			// for(auto e : cnt_b[1]) cout << e << ' '; cout << endl;
			
			int sz = cnt_a[1].size();
			for(int i = 0; i < sz; i++){
				if(cnt_a[1][i] < cnt_b[1][i]){
					return false;
				}
			}
			
			return true;
		};
		
		for(int i = 0; i < n; i++){
			
			if(str_b[i]=='C'){
				if(str_a[i] != 'C' || !check()){
					ans = false;
					break;
				}
				else{
					cnt_a = cnt_b = vector<vi>(3);
				}
			}
			else{
				cnt_a[str_a[i]-'A'].push_back(i);
				cnt_b[str_b[i]-'A'].push_back(i);
			}
		}
		
		if(ans) ans &= check();
		cout << (ans ? "Yes" : "No") << endl;
    }	
}










