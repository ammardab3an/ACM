// Problem: M. Minimum LCM
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/M
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
		
		vi factors;
		
		for(int i = 1; i*i <= n; i++) if(n%i==0){
			factors.push_back(i);
			if(n/i != i) factors.push_back(i);
		}
		
		int mn = INFLL;
		pii ans = {1, n-1};
		
		for(auto f : factors){
			
			int f0 = n/f;
			int f1 = f;
			
			int p = f0;
			for(int i = 2; i*i <= n; i++) if(f0%i==0){
				p = i;
				break;
			}
			
			int y = p-1;
			int x = f0/p;
			
			int a = x*f1;
			int b = x*y*f1;
			
			int cans = a*b/__gcd(a, b);
			
			// cout << ' ' << f0 << ' ' << f1 << ' ' << p << endl;
			// cout << a << ' ' << b << ' ' << cans << endl;
			
			if(cans < mn){
				mn = cans;
				ans = {a, b};
			}
		}
		
		auto [a, b] = ans;
		cout << a << ' ' << b << endl;
    }	
}