// K. Rainbow Subarray
// https://contest.ucup.ac/contest/1472/problem/7904

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

struct FenwickTree{
	
	int n;
	int lg_n;
	vi bit;
	
	FenwickTree(){
		assert(false);
	}
	
	FenwickTree(int m){
		
		lg_n = 0;
		while((1<<lg_n) < m){
			lg_n++;
		}
		
		n = 1<<lg_n;
		bit = vi(n);
	}
	
	int query(int i){
		int ret = 0;
		while(i >= 0){
			ret += bit[i];
			i = (i&(i+1))-1;
		}
		return ret;
	}
	
	int query(int l, int r){
		return query(r) - query(l-1);
	}
	
	void update(int i, int d){
		while(i < n){
			bit[i] += d;
			i |= i+1;
		}
	}
	
	int lower_bound(int val){
		int ptr = 0;
		for(int i = lg_n-1; i >= 0; i--){
			if(bit[ptr+(1<<i)-1] < val){
				val -= bit[ptr+(1<<i)-1];
				ptr |= 1<<i;
			}
		}
		return ptr;
	}
};

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
		for(auto &e : vec) cin >> e;
		
		for(int i = 0; i < n; i++){
			vec[i] -= i;
		}
		
		// for(auto e : vec) cout << e << ' '; cout << endl;
		
		vi tmp = vec;
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		int sz = tmp.size();
		
		vi _vec = vec;
		for(auto &e : _vec){
			e = lower_bound(tmp.begin(), tmp.end(), e)-tmp.begin();
		}
		
		FenwickTree tr_frq(sz);
		FenwickTree tr_val(sz);
		
		auto calc = [&](int k){
			
			int md_p = tr_frq.lower_bound(k);
			int md_val = tmp[md_p];
			
			int cnt_lower = tr_frq.query(0, md_p-1);
			int sm_lower = tr_val.query(0, md_p-1);
			
			int cnt_higher = tr_frq.query(md_p+1, sz-1);
			int sm_higher = tr_val.query(md_p+1, sz-1);
			
			int sm0 = sm_higher - md_val*cnt_higher;
			int sm1 = md_val*cnt_lower - sm_lower;
			int sm = sm0+sm1;
			
			return sm;
		};
		
		auto calc2 = [&]()->int{
			
			int tot = tr_frq.query(sz-1);
			
			if(tot%2==1){
				return calc((tot+1)/2);
			}	
			else{
				return min(calc(tot/2), calc(tot/2+1));
			}
		};
		
		auto update = [&](int i, int d){
			int val = vec[i];
			int p = _vec[i];
			tr_val.update(p, d*val);
			tr_frq.update(p, d);
		};
		
		int ans = 0;
		
		int j = -1;
		for(int i = 0; i < n; i++){
			
			if(i){
				update(i-1, -1);
			}	
			
			while(j+1 < n){
				
				j++;
				update(j, +1);
				
				if(calc2() > k){
					update(j, -1);
					j--;
					break;
				}
			}
			
			ans = max(ans, j-i+1);
		}
		
		cout << ans << endl;
    }	
}
