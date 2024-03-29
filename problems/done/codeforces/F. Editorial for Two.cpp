// Problem: F. Editorial for Two
// Contest: Codeforces - Educational Codeforces Round 149 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1837/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

bool check(const vi &vec, int sm, int k){
	
	int n = vec.size();
	vi rm(n+1);

	{
		
		int cur_sum = 0;
		priority_queue<int> que;
		
		for(int i = 0; i <= n; i++){
	
			if(i){
				
				int ai = vec[i-1];
				
				if(cur_sum+ai <= sm){
					que.push(ai);
					cur_sum += ai;
				}
				else if(!que.empty()) if(que.top() > ai){
					cur_sum -= que.top();
					cur_sum += ai;
					que.pop();
					que.push(ai);
				}
			}
			
			rm[i] = k-que.size();
			
			if(rm[i] <= 0){
				return true;
			}
		}
	}
	
	{
		
		int cur_sum = 0;
		priority_queue<int> que;
		
		for(int i = n; i >= 0; i--){
	
			if(i < n){
				
				int ai = vec[i];
				
				if(que.size() < rm[i]){
					que.push(ai);
					cur_sum += ai;
				}
				else if(!que.empty()) if(que.top() > ai){
					cur_sum -= que.top();
					cur_sum += ai;
					que.pop();
					que.push(ai);
				}
			}
			
			if(que.size() >= rm[i]){
				if(cur_sum <= sm){
					return true;
				}
			}
		}
	}
	
	return false;
}

int go(const vi &vec, int k){
	
	int l = 0;
	int r = 1e18;
	
	int ans = -1;
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		if(check(vec, mid, k)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	
	return ans;
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

		int n, k;
		cin >> n >> k;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int ans = go(vec, k);
		cout << ans << endl;
    }	
}
