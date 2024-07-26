// Problem: D. Swap Dilemma
// Contest: Codeforces - Codeforces Round #956 (Div. 2) and ByteRace 2024
// URL: https://codeforces.com/contest/1983/problem/D
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


struct FenwickTree{
	
	int n;
	int sz;
	int lg_n;
	vector<int> bit;
	
	FenwickTree(){
		assert(false);
	}
	
	FenwickTree(int n) : n(n){
		lg_n = int(ceil(log2(double(n))));
		sz = 1 << lg_n;
		bit.resize(sz, 0);
	}
	
	FenwickTree(const vector<int> &vec) : FenwickTree(vec.size()){
		
		for(int i = 0; i < n; i++){
			bit[i] += vec[i];
		}
		
		for(int i = 0; i < sz; i++){
			int r = i | (i+1);
			if(r < sz) bit[r] += bit[i];
		}
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
		int ret = query(r) - query(l-1);
		return ret;
	}
	
	void update(int i, int d){
		while(i < sz){
			bit[i] += d;
			i |= i+1;
		}
	}
	
	int lower_bound(int val){
		int ptr = 0;
		for(int i = lg_n-1; i >= 0; i--){
			if(val-bit[ptr+(1<<i)-1] > 0){	
				val -= bit[ptr+(1<<i)-1];
				ptr += (1<<i);
			}
		}
		return ptr;
	}
};


int calc(const vi &vec){
	
	int ret = 0;
	int n = vec.size();
	FenwickTree st(n);
	for(int i = 0; i < n; i++){
		ret += st.query(vec[i], n-1);
		st.update(vec[i], +1);
	}
	
	return ret;
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
		
		vi vec_a(n);
		for(auto &e : vec_a) cin >> e;
		
		vi vec_b(n);
		for(auto &e : vec_b) cin >> e;
		
		vi tmp_a = vec_a;
		vi tmp_b = vec_b;
		sort(tmp_a.begin(), tmp_a.end());
		sort(tmp_b.begin(), tmp_b.end());
		
		if(vec_a == vec_b){
			cout << "YES" << endl;
			continue;
		}
		else if(tmp_a != tmp_b){
			cout << "NO" << endl;
			continue;
		}
		
		bool ans = false;
		
		map<int, int> conv;
		for(int i = 0; i < n; i++){
			conv[vec_b[i]] = i;
		}
		for(int i = 0; i < n; i++){
			vec_a[i] = conv[vec_a[i]];
		}
		
		ans = calc(vec_a)%2==0;
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
