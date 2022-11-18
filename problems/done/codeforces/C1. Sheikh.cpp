// Problem: C1. Sheikh (Easy version)
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforces.com/contest/1732/problem/C1
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
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
    
    int t; cin >> t; while(t--){

		int n, q;
		cin >> n >> q;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vpii queries(q);
		for(auto &[l, r] : queries){
			cin >> l >> r;
			l--, r--;
		}
		
		vector<vi> pre(30, vi(n));
		for(int i = 0; i < 30; i++){
			pre[i][0] = (vec[0]>>i)&1;
			for(int j = 1; j < n; j++){
				pre[i][j] = pre[i][j-1] + ((vec[j]>>i)&1);
			}
		}
		
		vi _xor(n);
		_xor[0] = vec[0];
		for(int i = 1; i < n; i++){
			_xor[i] = _xor[i-1] ^ vec[i];
		}
		
		int ans = INF;
		pii ans_rng = {-1, -1};
		
		for(int i = 0; i < n; i++){
			
			int l = i;
			int r = n-1;
			
			int ans_bs = -1;
			
			vi tot(30);
			for(int j = 0; j < 30; j++){
				tot[j] = pre[j][n-1];
				if(tot[j]&1) tot[j]--;
			}
			
			while(l <= r){
				
				int mid = (l+r)/2;
				
				bool good = true;
				for(int j = 0; j < 30; j++){
					int cc = pre[j][mid]-pre[j][i]+((vec[i]>>j)&1);
					if(cc < tot[j]){
						good = false;
						break;
					}
				}
				
				if(good){
					ans_bs = mid;
					r = mid-1;
				}
				else{
					l = mid+1;
				}
			}
			
			if(ans_bs != -1){
				int cans = ans_bs-i+1;
				if(cans < ans){
					ans = ans_bs-i+1;
					ans_rng = {i, ans_bs};
				}
			}
		}
		
		auto [l, r] = ans_rng;
		cout << l+1 << ' ' << r+1 << endl;
    }	
}
