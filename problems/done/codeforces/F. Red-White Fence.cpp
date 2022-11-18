// Problem: F. Red-White Fence
// Contest: Codeforces - Educational Codeforces Round 75 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1251/problem/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n), red(m);
    for(auto &i : vec) cin >> i;
    for(auto &i : red) cin >> i;
    
    int q;
    cin >> q;
    
    vi queries(q);
    for(auto &i : queries) cin >> i;
    
    // -------------------------------------
    
    map<int, int > mp;
    for(auto i : vec) mp[i]++;
    vpii tmp(mp.begin(), mp.end());
    
    sort(red.begin(), red.end());
    reverse(red.begin(), red.end());
    
    vector<vi> funs(tmp.size());
    
    for(int i = 0; i < tmp.size(); i++){
    	if(tmp[i].second > 1){
    		funs[i] = {1, 2, 1};
    	}
    	else{
    		funs[i] = {1, 2};
    	}
    }
    
    funs.push_back({1});
    
    vi ans(q);
    priority_queue<pii> que;
    que.push({-1, funs.size()-1});
    
    auto merge_que = [&](){
    	
    	while(que.size() > 1){
    		
    		int a = que.top().second; que.pop();
    		int b = que.top().second; que.pop();
    		
    		auto &fa = funs[a];
    		auto &fb = funs[b];
    		
    		int sz_res = fa.size() + fb.size() -1;
    		sz_res = 1 << int(ceil(log2(double(sz_res))));
    		
    		fa.resize(sz_res);
    		fb.resize(sz_res);
    		
    		fft(fa, false);
    		fft(fb, false);
    		
    		for(int i = 0; i < sz_res; i++){
    			fa[i] = mul(fa[i], fb[i]);
    		}
    		
    		fft(fa, true);
    		
    		while(!fa.back()) fa.pop_back();
    		
    		que.push({-fa.size(), a});
    		fb = vi();
    	}	
    };
    
    for(int i = 0; i <= tmp.size(); i++){
    	
    	while(!red.empty() && (i==tmp.size() || tmp[i].first >= red.back())){
    		
    		int r = red.back();
    		red.pop_back();	
    		
    		merge_que();
    		
    		auto &f = funs[que.top().second];
    		
    		for(int j = 0; j < q; j++){
    			int x = (queries[j] - 2*r -2)/2;
    			if(x < 0 || x >= f.size()) continue;
    			ans[j] = add(ans[j], f[x]);
    		}
    	}
    	
    	if(i==tmp.size()) break;
    	
    	que.push({-funs[i].size(), i});
    }
    
    for(auto i : ans) cout << i << endl;
}
