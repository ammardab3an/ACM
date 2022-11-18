// Problem: C2. Sheikh (Hard Version)
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforces.com/contest/1732/problem/C2
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
		
		vector<vi> pos(30);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 30; j++) if((vec[i]>>j)&1){
				pos[j].push_back(i);
			}
		}
		
		
		for(auto [l, r] : queries){
			
			int ans = INFLL;
			pii ans_rng = {l, r};
			
			int cl = r;
			int cr = l;
			
			vpii later;
			
			for(int i = 0; i < 30; i++){
				
				auto it_l = lower_bound(pos[i].begin(), pos[i].end(), l);
				auto it_r = upper_bound(pos[i].begin(), pos[i].end(), r);
				
				if(it_l != pos[i].end() && *it_l <= r){
					
					it_r--;
					int cnt = it_r-it_l+1;
					
					if(cnt < 2) continue;
					
					if(cnt%2==0){
						cl = min(cl, *it_l);
						cr = max(cr, *it_r);
					}
					else {
						cl = min(cl, *(it_l+1));
						cr = max(cr, *(it_r-1));
						later.push_back({*it_l, *it_r});
					}
				}
			}
			
			// cout << cl << ' ' << cr << endl;
			// for(auto [l, r] : later){
				// cout << l << ' ' << r << endl;
			// }
			// cout << endl;
			
			vpii tmp;
			int cnt = 0;
			for(auto [a, b] : later){
				bool take = true;
				if(cl <= a && a <= cr){
					take = false;
				}
				else if(cl <= b && b <= cr){
					take = false;
				}
				if(take){
					tmp.push_back({a, cnt});
					tmp.push_back({b, cnt});
					cnt++;
				}
			}
			
			
			// cout << ' ' << l << ' ' << r << endl;
			// cout << cl << ' ' << cr << endl;
			// for(auto [l, r] : tmp){
				// cout << l << ' ' << r << endl;
			// }
			// cout << endl;
			// cout << flush;
			
			if(tmp.empty()){
				ans = cr-cl+1;
				ans_rng = {cl, cr};
			}
			
			vi frq(cnt);
			sort(tmp.begin(), tmp.end());
			int cc = 0;
			
			int j = 0;
			for(int i = 0; i < tmp.size(); i++){
				
				if(i){
					if(--frq[tmp[i-1].second]==0){
						cc--;
					}
				}
				
				while(j < tmp.size() && cc < cnt){
					if(++frq[tmp[j].second]==1){
						cc++;
					}
					j++;
				}
				
				if(cc==cnt){
					
					int cur_l = min(cl, tmp[i].first);
					int cur_r = max(cr, tmp[j-1].first);
					
					// cout << '-' << ' ' << cur_l << ' ' << cur_r << endl;
					
					int cans = cur_r-cur_l+1;
					if(cans < ans){
						ans = cans;
						ans_rng = {cur_l, cur_r};
					}
				}
			}
			
			{
				auto [l, r] = ans_rng;
				if(l > r) l = r;
				cout << l+1 << ' ' << r+1 << endl;
			}
		}
    }	
}
