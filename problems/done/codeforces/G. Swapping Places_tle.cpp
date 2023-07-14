// Problem: G. Swapping Places
// Contest: Codeforces - 2019-2020 ICPC Southwestern European Regional Programming Contest (SWERC 2019-20)
// URL: https://codeforces.com/gym/102501/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	
	vector<int> vals;
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
        vals.resize(n);
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
    	vals[idx] += delta;
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    
    void turn_on(int idx){
    	if(!vals[idx]){
    		add(idx, 1);
    	}
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int s, m, n;
    cin >> s >> m >> n;
    
	vector<string> vec(s);
	for(auto &s : vec) cin >> s;
	
	sort(vec.begin(), vec.end());
	
	vector<vector<bool>> rel(s, vector<bool>(s));
	
	for(int i = 0; i < s; i++){
		rel[i][i] = true;
	}
	
	for(int i = 0; i < m; i++){
		string s0, s1;
		cin >> s0 >> s1;
		int p0 = lower_bound(vec.begin(), vec.end(), s0)-vec.begin();
		int p1 = lower_bound(vec.begin(), vec.end(), s1)-vec.begin();
		rel[p0][p1] = rel[p1][p0] = true;
	}
	
	vector<string> lst(n);
	for(auto &s : lst) cin >> s;
	
	vi ans(n);
	for(int i = 0; i < n; i++){
		ans[i] = lower_bound(vec.begin(), vec.end(), lst[i])-vec.begin();
	}
	
	vector<vi> frq(s);
	vector<FenwickTree> bit(s, FenwickTree(n));
	
	for(int i = 0; i < s; i++)
	for(int j = 0; j < n; j++) if(rel[i][ans[j]]){
		bit[i].turn_on(j);
		if(ans[j]==i) frq[i].push_back(j);
	}
	
	for(auto &v : frq){
		reverse(v.begin(), v.end());
	}
	
	auto bs = [&](int i, int j){
		
		int l = 0;
		int r = j;
		
		int ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			int sm = bit[i].sum(mid, j);
			
			if(sm==(j-mid+1)){
				ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		assert(ans != -1);
		
		return ans;
	};
	
	vector<vi> dp(s, vi(n, -1));
	
	auto bs2 = [&](int i, int j){
		
		int &p = dp[i][j];
		
		if(p==-1){
			return p = bs(i, j);
		}
		else if(p && bit[i].vals[p-1]){
			return p = bs(i, p-1);
		}
		else{
			return p;
		}
	};
	
	vi nans(n);
	FenwickTree foo(n);
	
	for(int i = 0; i < n; i++){
		
		bool found = false;
		
		for(int j = 0; j < s; j++) if(!frq[j].empty()){
			
			int l = bs2(j, frq[j].back());
			l += foo.sum(l, n-1);
			
			if(l <= i){
				
				int p = frq[j].back();
				frq[j].pop_back();
				
				for(int k = 0; k < s; k++){
					bit[k].turn_on(p);
				}
				
				nans[i] = j;
				found = true;
				foo.turn_on(p);
				
				break;
			}
		}	
		
		assert(found);
	}
	
	for(auto i : nans) cout << vec[i] << ' '; cout << endl;
}
