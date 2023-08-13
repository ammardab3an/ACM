// D. Master of Both III
// https://qoj.ac/contest/1221/problem/6397

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
const int MOD = 998244353; // 1e9 + 7;
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

int n;
int arr[55];
int pow2[55];
int dist[1<<22];

int32_t main(){
    
    fastIO;
    
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	pow2[0] = 1;
	for(int i = 1; i < n; i++){
		pow2[i] = (pow2[i-1] * 2) % MOD;
	}
	
	memset(dist, INF, sizeof dist);
	
	priority_queue<pii, vpii, greater<pii>> que;
	
	dist[1] = 0;
	que.push({0, 1});
	
	while(!que.empty()){
		
		auto [cur_d, msk] = que.top();
		que.pop();
		
		if(cur_d > dist[msk]) continue;
		
		// cout << bitset<4>(msk) << ' ' << dist[msk] << endl;
		
		for(int i = 1; i < n; i++) if((msk>>i)&1){
			int nmsk = msk ^ (1<<i);
			if(dist[nmsk] > cur_d){
				dist[nmsk] = cur_d;
				que.push({cur_d, nmsk});
			}
		}
		
		for(int i = 1; i < n; i++){
			
			int nmsk = msk | (msk << i);
			nmsk |= (nmsk >> n);
			nmsk &= (1<<n)-1;
			
			int nd = cur_d + arr[i];
			
			if(dist[nmsk] > nd){
				dist[nmsk] = nd;
				que.push({nd, nmsk});
			}
		}
	}
	
	int ans = 0;
	
	for(int msk = 0; msk < (1<<n); msk++){
		
		int cur_msk = 1;
		int sm_pow2 = 0;
		for(int i = 0; i < n; i++) if((msk>>i)&1){
			if(i) cur_msk |= 1 << (n-i);
			sm_pow2 = add(sm_pow2, pow2[i]);
		}
		
		// cout << bitset<5>(cur_msk) << ' ' << dist[cur_msk] << ' ' << sm_pow2 << endl;
		
		int cans = mul(dist[cur_msk], sm_pow2);
		ans = add(ans, cans);	
	}
	
	cout << ans << endl;
}

