// Problem: C. Dora and Search
// Contest: Codeforces - Codeforces Round #852 (Div. 2)
// URL: https://codeforces.com/contest/1793/problem/C
// Memory Limit: 256 MB
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

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		set<int> good;
		stack<pii> mn, mx;
		
		mn.push({vec.back(), n-1});
		mx.push({vec.back(), n-1});
		
		vi cnt(n, 2);
		set<pii> st_mn, st_mx;
		
		st_mn.insert({-vec.back(), n-1});
		st_mx.insert({vec.back(), n-1});
		
		bool found = false;
		
		for(int i = n-2; i >= 0; i--){
			
			int ai = vec[i];
			while(mn.size() && mn.top().first > ai){
				mn.pop();
			}
			while(mx.size() && mx.top().first < ai){
				mx.pop();
			}
			
			int j = i;
			if(mn.size()){
				j = max(j, mn.top().second);
			}
			else{
				j = n;
			}
			if(mx.size()){
				j = max(j, mx.top().second);
			}
			else{
				j = n;
			}
			
			while(st_mn.size() && -(st_mn.begin()->first) > ai){
				pii p = *st_mn.begin();
				st_mn.erase(st_mn.begin());
				if(--cnt[p.second]==0){
					good.insert(p.second);
					// cout << "mn " << p.second << endl;
				}
			}
			
			while(st_mx.size() && st_mx.begin()->first < ai){
				pii p = *st_mx.begin();
				st_mx.erase(st_mx.begin());
				if(--cnt[p.second]==0){
					good.insert(p.second);
					// cout << "mx " << p.second << endl;
				}
			}
			
			// cout << i << ' ' << j << endl;
			// for(auto i : cnt) cout << i << ' '; cout << endl;
			
			auto it = good.upper_bound(j);
			if(it != good.end()){
				found = true;
				cout << i+1 << ' ' << (*it)+1 << endl;
				break;
			}
			
			mn.push({ai, i});
			mx.push({ai, i});
			
			st_mn.insert({-ai, i});
			st_mx.insert({ai, i});
		}
		
		// for(auto [v, i] : st_mn) cout << i+1 << ' '; cout << endl;
		// for(auto [v, i] : st_mx) cout << i+1 << ' '; cout << endl;
		
		if(!found){
			cout << -1 << endl;
		}
    }	
}
