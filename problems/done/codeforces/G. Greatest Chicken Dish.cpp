// Problem: G. Greatest Chicken Dish
// Contest: Codeforces - 2018 Arab Collegiate Programming Contest (ACPC 2018)
// URL: https://codeforces.com/gym/101991/problem/G
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
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

struct sparse_table{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table(){};
    
    sparse_table(const vi &vec){
        
        int n = vec.size();
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = vec[i];
        }

        for (int j = 1; j <= k; j++){
	        for (int i = 0; i + (1 << j) <= n; i++){
	        	st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	        }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        return __gcd(st[l][j], st[r-(1<<j)+1][j]);
    }
};

struct node{
	
	ll sm = 0;
	int lazy = 0;
	node *lf, *ri;	
	
	node(){
		sm = 0;
		lazy = 0;
		lf = ri = nullptr;
	}
	
	~node(){
		delete lf;
		delete ri;
	}
	
	void push(int l, int r){
		if(!lazy) return;
		sm += lazy *1ll* (r-l+1);
		if(l != r){
			if(!lf) lf = new node();
			if(!ri) ri = new node();
			lf->lazy += lazy;
			ri->lazy += lazy;
		}	
		lazy = 0;
	}
	
	void update(int l, int r, int q_l, int q_r){
		
		push(l, r);
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			lazy = 1;
			push(l, r);
			return;
		}
		
		int mid = (l+r)/2;
		if(!lf) lf = new node();
		if(!ri) ri = new node();
		lf->update(l, mid, q_l, q_r);
		ri->update(mid+1, r, q_l, q_r);
		
		sm = lf->sm + ri->sm;
	}
	
	ll query(int l, int r, int q_l, int q_r){
		
		push(l, r);
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return sm;
		}
		
		int mid = (l+r)/2;
		ll st_path = !lf ? 0 : lf->query(l, mid, q_l, q_r);
		ll nd_path = !ri ? 0 : ri->query(mid+1, r, q_l, q_r);
		
		return st_path + nd_path;
	}
};

int32_t main(){
    
    fastIO;

    freopen("gcdrng.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		if(n==0){
			n = 1e5;
			vec = vi(n, 1);
			srand(0);
			for(auto &e : vec) e = 1ll << (std::rand()%30);
		}
		
		map<int, vector<iii>> mp_queries;
		
		for(int i = 0; i < m; i++){
			int l, r, d;
			cin >> l >> r >> d;
			l--, r--;
			mp_queries[d].push_back({r, {l, i}});
		}
		
		map<int, vector<iii>> mp;
		
		{
			sparse_table st(vec);
			for(int i = 0; i < n; i++){
				
				int j = i;
				int old_j = i;
				int g = 0;
				
				while(j >= 0){
					
					old_j = j;
					g = st.query_range(j, i);
					
					int l = 0;
					int r = i;
					while(l <= r){
						int mid = (l+r)/2;
						if(st.query_range(mid, i) >= g){
							j = mid;
							r = mid-1;
						}
						else{
							l = mid+1;
						}
					}
					
					mp[g].push_back({i, {j, old_j}});
					j--;
				}
			}
		}
		
		vl ans(m);
		
		for(auto &[d, v] : mp_queries){
			
			node st;
			auto &v_updates = mp[d];
			
			sort(v.begin(), v.end());
			sort(v_updates.begin(), v_updates.end());
			
			assert(v_updates.size() <= n);
			
			int j = 0;
			
			for(auto e : v){
				
				int r = e.first;
				int l = e.second.first;
				int q_idx = e.second.second;
				
				while(j < v_updates.size() && v_updates[j].first <= r){
					auto [l, r] = v_updates[j].second;
					st.update(0, n-1, l, r);
					j++;
				}
				
				ans[q_idx] = st.query(0, n-1, l, r);
			}
		}
		
		for(auto e : ans){
			cout << e << endl;
		}
    }	
}
