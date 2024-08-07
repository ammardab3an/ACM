
// B. Bars
// https://qoj.ac/problem/5500

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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

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
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vpii tmp;
		tmp.push_back({0, 0});
		
		// dp[i] = max(dp[j] + (pi+pj)*(i-j))
		// dp[i] = max(dp[j] + pi*i + pj*j - pi*j - pj*j)
		// dp[i] = pi*i + max((dp[j]-pj*j) + pj*i - pi*j )
		
		// ans = sum((pi+pj) * (i-j))
		// pi*i + pj*i - pi*j - pj*j
		// (pi*i - pj*j) + (pj*i - pi*j)
		// first term will be canceled, the second term can be maximized acoording to:
		// Shoelace Formula
		
		auto calc = [&](const pii &a, const pii &b){
			return a.first*b.second - b.first*a.second;
		};
		
		for(int i = 0; i <= n; i++){
			
			pii cur = i < n ? (pii){vec[i], i} : (pii){0, n-1};
			
			while(tmp.size() >= 2){
				
				pii a = tmp[tmp.size()-2];
				pii b = tmp[tmp.size()-1];
				pii c = cur;
				
				if(calc(a, b) + calc(b, c) <= calc(a, c)){
					tmp.pop_back();
				}
				else{
					break;
				}
			}
			
			tmp.push_back(cur);
		}
		
		int ans = 0;
		for(int i = 1; i < tmp.size(); i++){
			ans += calc(tmp[i-1], tmp[i]);
		}
		
		cout << ans << endl;
    }	
}
