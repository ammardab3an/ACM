// Problem: Calculate The Cost
// Contest: Virtual Judge - SPOJ
// URL: https://vjudge.net/problem/SPOJ-CCOST
// Memory Limit: 1536 MB
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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
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

		int n;
		cin >> n;
		
		vi tmp;
		
		vector<iii> vec(n);
		for(auto &[v, xy] : vec){
			auto &[x, y] = xy;
			cin >> x >> y >> v;
			tmp.push_back(x);
			tmp.push_back(y);
		}
		
		int q;
		cin >> q;
		vector<pair<pii, pii>> queries(q);
		
		for(auto &[xy0, xy1] : queries){
			auto &[x0, y0] = xy0;
			auto &[x1, y1] = xy1;
			cin >> x0 >> y0 >> x1 >> y1;
			tmp.push_back(x0);
			tmp.push_back(y0);
			tmp.push_back(x1);
			tmp.push_back(y1);
		}
		
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		
		vector<vpii> tmp_pnt(tmp.size());
		vector<vpii> tmp_que(tmp.size());
		
		for(auto &[v, xy] : vec){
			
			auto &[x, y] = xy;
			
			x = lower_bound(tmp.begin(), tmp.end(), x)-tmp.begin();
			y = lower_bound(tmp.begin(), tmp.end(), y)-tmp.begin();
			
			tmp_pnt[x].push_back({y, v});
		}
		
		for(int i = 0; i < q; i++){
			
			auto &[x0, y0] = queries[i].first;
			auto &[x1, y1] = queries[i].second;
			
			x0 = lower_bound(tmp.begin(), tmp.end(), x0)-tmp.begin();
			y0 = lower_bound(tmp.begin(), tmp.end(), y0)-tmp.begin();
			x1 = lower_bound(tmp.begin(), tmp.end(), x1)-tmp.begin();
			y1 = lower_bound(tmp.begin(), tmp.end(), y1)-tmp.begin();
			
			tmp_que[x1].push_back({i, +1});
			if(x0) tmp_que[x0-1].push_back({i, -1});
		}
		
		vi ans(q);
		FenwickTree bit(tmp.size());
		
		for(int i = 0; i < tmp.size(); i++){
			
			for(auto [y, v] : tmp_pnt[i]){
				bit.add(y, v);
			}
			
			for(auto [j, d] : tmp_que[i]){
				int y0 = queries[j].first.second;
				int y1 = queries[j].second.second;
				ans[j] += d * bit.sum(y0, y1);
			}
		}
		
		for(auto i : ans){
			cout << i << endl;
		}
    }	
}
