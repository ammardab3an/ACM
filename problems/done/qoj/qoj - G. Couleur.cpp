
// G. Couleur
// https://qoj.ac/contest/1339/problem/7108

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

struct FenwickTree {
    
    int n;
    vector<int> bit;  // binary indexed tree

	FenwickTree(){}
	
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

deque<int> compress(const vi &vec){
	
	vi tmp = vec;
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	deque<int> ret(vec.begin(), vec.end());
	for(auto &e : ret){
		e = lower_bound(tmp.begin(), tmp.end(), e) - tmp.begin();
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
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi per(n);
		for(auto &i : per) cin >> i;
		
		// if(n==0){
			// n = 1e6;
			// vec = vi(n);
			// per = vi(n);
			// iota(vec.begin(), vec.end(), 0);
			// iota(per.begin(), per.end(), 0);
			// random_shuffle(vec.begin(), vec.end());
			// random_shuffle(per.begin(), per.end());
		// }
		
		struct s_data{
			int frq_cnt = 0;
			FenwickTree st;
			deque<int> elements;
		};
		
		vector<s_data> data;
		set<pair<pii, int>> st;
		multiset<int> mx;
		
		auto calc = [&](int l, int r){
			
			if(l > r){
				return;
			}
			
			s_data tmp;
			int sz = r-l+1;
			tmp.st = FenwickTree(sz);
			tmp.elements = compress(vi(vec.begin()+l, vec.begin()+r+1));
			
			for(int i = sz-1; i >= 0; i--){
				tmp.frq_cnt += tmp.st.sum(0, tmp.elements[i]-1);
				tmp.st.add(tmp.elements[i], 1);
			}
			
			mx.insert(tmp.frq_cnt);
			st.insert({{l, r}, data.size()});
			data.emplace_back(tmp);
		};
		
		calc(0, n-1);
		
		for(auto p : per){
			
			cout << (*mx.rbegin()) << ' ';
			
			int i = (p ^ (*mx.rbegin())) - 1;
			// int i = p;
			
			auto it = st.upper_bound({{i, INFLL}, INFLL});
			assert(it != st.begin());
			it--;
			
			auto [l, r] = it->first;
			int d_idx = it->second;
			
			st.erase(it);
			
			// pii st = {l, i-1};
			// pii nd = {i+1, r};
			
			int sz = r-l+1;
			int sz_st = (i-1)-l+1;
			int sz_nd = r-(i+1)+1;
			
			if(sz_st <= sz_nd){
				
				auto &d = data[d_idx];
				mx.erase(mx.find(d.frq_cnt));
				
				while(sz > sz_nd){
					sz--;
					d.frq_cnt -= d.st.sum(0, d.elements.front()-1);
					d.st.add(d.elements.front(), -1);
					d.elements.pop_front();
				}
				
				if(i+1 <= r){
					mx.insert(d.frq_cnt);
					st.insert({{i+1, r}, d_idx});
				}
				
				calc(l, i-1);
			}
			else{
				
				auto &d = data[d_idx];
				mx.erase(mx.find(d.frq_cnt));
				
				while(sz > sz_st){
					sz--;
					d.frq_cnt -= d.st.sum(d.elements.back()+1, d.st.n-1);
					d.st.add(d.elements.back(), -1);
					d.elements.pop_back();
				}
				
				if(l <= i-1){
					mx.insert(d.frq_cnt);
					st.insert({{l, i-1}, d_idx});
				}
				
				calc(i+1, r);
			}
		}
		
		cout << endl;
    }	
}
