// Problem: D. Non-zero factorial
// Contest: Codeforces - Mathforces
// URL: https://codeforces.com/gym/408650/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int NMAX = 1e6 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    vpii cnt(NMAX);
    cnt[1] = {0, 0};
    for(int i = 2; i < NMAX; i++){
    	cnt[i] = cnt[i-1];
    	int x = i;
    	while(x%2==0) cnt[i].first++, x/=2;
    	while(x%5==0) cnt[i].second++, x/=5;	
    }
    
    vi fac(NMAX);
    fac[0] = 1;
    for(int i = 1; i < NMAX; i++){
    	int x = i;
    	while(x%2==0) x /= 2;
    	while(x%5==0) x /= 5;
    	fac[i] = (fac[i-1]*1ll*x)%10;
    }
    
    auto fast_pow = [](int x, int p){
    	
    	int ret = 1;
    	
    	while(p){
    		if(p&1) ret = (ret*x)%10;
    		x = (x*x)%10;
    		p /= 2;
    	}
    	
    	return ret;
    };
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		pii tot = {0, 0};
		for(auto i : vec){
			tot.first += cnt[i].first;
			tot.second += cnt[i].second;
		}
		
		int mn = min(tot.first, tot.second);
		
		int ans = 1;
		for(auto i : vec){
			ans = (ans*fac[i])%10;
		}
		
		int p2 = fast_pow(2, tot.first-mn);
		int p5 = fast_pow(5, tot.second-mn);
		
		ans = (ans*p2)%10;
		ans = (ans*p5)%10;
		
		cout << ans << endl;
    }	
}
