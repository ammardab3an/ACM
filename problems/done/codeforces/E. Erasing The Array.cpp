// Problem: E. Erasing The Array
// Contest: Codeforces - ACPC 2022
// URL: https://codeforces.com/gym/417678/problem/E
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, k, x;
	cin >> n >> k >> x;
	
	int tot_sm_l = 0;
	int tot_sm_r = 0;
	
	vi vec_l(n), vec_r(n);
	for(auto &i : vec_l) cin >> i;
	for(auto &i : vec_r) cin >> i, tot_sm_r += i;
	
	int sm_l_k = 0;
	int sm_r_k = 0;
	multiset<int> mst_l, mst_l_k, mst_r, mst_r_k;
	
	auto fix = [&](){
		
		int mn = min(mst_l_k.size(), mst_r_k.size());
		
		while(mst_l_k.size() > mn){
			sm_l_k -= *mst_l_k.begin();
			mst_l.insert(*mst_l_k.begin());
			mst_l_k.erase(mst_l_k.begin());
		}
		while(mst_r_k.size() > mn){
			sm_r_k -= *mst_r_k.begin();
			mst_r.insert(*mst_r_k.begin());
			mst_r_k.erase(mst_r_k.begin());
		}
		
		while(mst_l_k.size() < k && !mst_l.empty() && !mst_r.empty()){
			int val_l = *mst_l.rbegin();
			int val_r = *mst_r.rbegin();
			if(val_l+val_r <= x) break;
			sm_l_k += val_l;
			sm_r_k += val_r;
			mst_l_k.insert(val_l);
			mst_r_k.insert(val_r);
			mst_l.erase(mst_l.find(val_l));
			mst_r.erase(mst_r.find(val_r));
		}
		
		// cout << '-' << endl;
		// for(auto e : mst_l) cout << e << ' '; cout << endl;
		// for(auto e : mst_l_k) cout << e << ' '; cout << endl;
		// for(auto e : mst_r) cout << e << ' '; cout << endl;
		// for(auto e : mst_r_k) cout << e << ' '; cout << endl;
		// cout << '-' << endl;
		
	};
	
	for(auto e : vec_r){
		mst_r.insert(e);
	}
	
	int ans = tot_sm_r;
	
	for(int i = 0; i < n; i++){
		
		tot_sm_l += vec_l[i];
		tot_sm_r -= vec_r[i];
		
		if(!mst_l_k.empty()){
			sm_l_k += vec_l[i];
			mst_l_k.insert(vec_l[i]);
			sm_l_k -= *mst_l_k.begin();
			mst_l.insert(*mst_l_k.begin());
			mst_l_k.erase(mst_l_k.begin());
		}
		else{
			mst_l.insert(vec_l[i]);
		}
		
		{
			auto it = mst_r.find(vec_r[i]);
			if(it != mst_r.end()){
				mst_r.erase(it);
			}
			else{
				sm_r_k -= vec_r[i];
				mst_r_k.erase(mst_r_k.find(vec_r[i]));
			}
		}
		
		fix();
		assert(mst_l_k.size()==mst_r_k.size());
		
		// cout << mst_l_k.size() << ' ' << sm_l_k << ' ' << sm_r_k << endl;
		
		int cans = tot_sm_l + tot_sm_r - sm_l_k - sm_r_k + mst_l_k.size()*x;
		ans = min(ans, cans);
	}
	
	cout << ans << endl;
}
