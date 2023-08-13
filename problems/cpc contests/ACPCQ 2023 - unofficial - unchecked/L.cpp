
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

const int AMAX = 5e5 + 10;
int frq[AMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, x, k;
	cin >> n >> x >> k;
	
	vi vec(n);
	for(auto &e : vec) cin >> e;
	
	vi tmp;
	for(int i = 1; ; i++){
		int i_x = 1;
		for(int j = 0; j < x; j++){
			i_x *= i;
			if(i_x > AMAX) break;
		}
		if(i_x > AMAX) break;
		tmp.push_back(i_x);
	}
	
	// for(auto e : tmp) cout << e << endl;
	
	vi ans;
	ans.push_back(0);
	
	int j = 0;
	int cur = 0;
	for(int i = 0; i < n; i++){
		
		int v = vec[i];
		
		int ncnt = 0;
		
		for(auto e : tmp) if(e%v==0){
			ncnt += frq[e/v];
		}
	
		if(v==1){
			int f = frq[1];
			ncnt += f*(f-1)/2;
		}
		
		if(ncnt + cur <= k){
			cur += ncnt;
			frq[v]++;
		}
		else{
			
			cur = 0;
			for(int k = j; k < i; k++){
				frq[vec[k]]--;
			}
			
			frq[v]++;		
			ans.push_back(i);
			j = i;
		}
	}
	
	ans.push_back(n);
	
	// for(auto e : ans) cout << e << ' '; cout << endl;
	
	cout << (int)ans.size()-1 << endl;
	for(int i = 1; i < ans.size(); i++){
		cout << ans[i]-ans[i-1] << ' ';
	}
}
