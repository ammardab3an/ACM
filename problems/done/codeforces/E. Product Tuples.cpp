// Problem: E. Product Tuples
// Contest: Codeforces - Bubble Cup 12 - Finals [Online Mirror, unrated, Div. 1]
// URL: https://codeforces.com/contest/1218/problem/E
// Memory Limit: 128 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
const int MOD = 998244353; //1e9 + 7;
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

const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = pow_exp (n, mod-2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

int calc(int k, int q, const vi &vec){
	
	int n = vec.size();
	vector<vi> tmp(n);
	for(int i = 0; i < n; i++){
		tmp[i] = {1, q-vec[i]};
	}
	
	priority_queue<pii> que;
	for(int i = 0; i < n; i++){
		que.push({-tmp[i].size(), i});
	}
	
	while(que.size() > 1){
		
		int a = que.top().second; que.pop();
		int b = que.top().second; que.pop();
		
		int res_sz = tmp[a].size()+tmp[b].size()-1;
		res_sz = 1 << int(ceil(log2(double(res_sz))));
		
		vi &fa = tmp[a];
		vi &fb = tmp[b];
		
		fa.resize(res_sz);
		fb.resize(res_sz);
		
		fft(fa, false);
		fft(fb, false);
		
		for(int i = 0; i < res_sz; i++){
			fa[i] = mul(fa[i], fb[i]);
		}
		
		fft(fa, true);
		
		while(fa.back()==0) fa.pop_back();
		fb = vi();
		
		que.push({-fa.size(), a});
	}
	
	return add(0, tmp[que.top().second][k]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    int q; cin >> q; while(q--){
    	
    	int ty;
    	cin >> ty;
    	
    	if(ty==1){
    		
    		int q, i, d;
    		cin >> q >> i >> d;
    		i--;
    		
    		swap(vec[i], d);
    		cout << calc(k, q, vec) << endl;
    		swap(vec[i], d);
    	}
    	else{
    		
    		int q, l, r, d;
    		cin >> q >> l >> r >> d;
    		l--, r--;
    		
    		for(int i = l; i <= r; i++){
    			vec[i] += d;
    		}
    		
    		cout << calc(k, q, vec) << endl;
    		
    		for(int i = l; i <= r; i++){
    			vec[i] -= d;
    		}
    	}
    }
}
