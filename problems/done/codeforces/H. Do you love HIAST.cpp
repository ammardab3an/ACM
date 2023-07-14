// Problem: H. Do you love HIAST?
// Contest: Codeforces - Al-Baath Collegiate Programming Contest 2023
// URL: https://codeforces.com/gym/104447/problem/H
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	
    int n;
    vector<int> bit;  // binary indexed tree

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
            ret ^= bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) ^ sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] ^= delta;
    }  
};

const int AMAX = 1e6 + 10;

vpii tmp[AMAX];
vpii tmp_q[AMAX];
FenwickTree bit(2*AMAX);

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	vpii pnts(n);
	for(auto &[i, j] : pnts){
		cin >> i >> j;
		i++, j++;
	}
	
	for(int i = 0; i < n; i++){
		if(pnts[i].first == pnts[(i+1)%n].first){
			int j0 = pnts[i].second;
			int j1 = pnts[(i+1)%n].second;
			if(j0 > j1) swap(j0, j1);
			tmp[pnts[i].first].push_back({j0*2+1, j1*2});
		}
	}
	
	int m;
	cin >> m;
	
	for(int k = 0; k < m; k++){
		int i, j;
		cin >> i >> j;
		i++, j++;
		tmp_q[i].push_back({j, k});
	}
	
	vi ans(m);
	
	for(int i = 1; i < AMAX; i++){
		
		for(auto [j, b] : tmp_q[i]){
			ans[b] |= bit.sum(j*2);
			ans[b] |= bit.sum(j*2+1);
		}
		
		for(auto [l, r] : tmp[i]){
			bit.add(l, 1);
			bit.add(r+1, 1);
		}
		
		for(auto [j, b] : tmp_q[i]){
			ans[b] |= bit.sum(j*2);
			ans[b] |= bit.sum(j*2+1);
		}
	}
	
	for(auto e : ans){
		cout << (e ? "YES" : "NO") << endl;
	}
}
