// Problem: A. Buffer Sharing in Multi-tenant Database Environment
// Contest: Codeforces - ICPC 2023 Online Spring Challenge powered by Huawei
// URL: https://codeforces.com/contest/1813/problem/A
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
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

typedef priority_queue<pii, vpii, greater<pii>> pque;
	
struct LRU{
	
	int data_sz;
	int cache_sz;
	int cnt_miss;
	pque que;
	vector<bool> in_cache;
	vector<int> frq;
	
	LRU(){}
	
	LRU(int data_sz, int cache_sz) : data_sz(data_sz), cache_sz(cache_sz) {
		
		cnt_miss = 0;
		in_cache = vector<bool>(data_sz);
		frq = vector<int>(data_sz);
		
		for(int i = 0; i < data_sz; i++){
			que.push({0, i});
		}
	}
	
	void query(int i){
		
		if(!in_cache[i]){
			
			cnt_miss++;
			
			if((int)que.size()==cache_sz){
				pii tp = que.top();
				que.pop();
				in_cache[tp.second] = false;
			}
			
			in_cache[i] = true;
			frq[i]++;	
			
			que.push({frq[i], i});
		}
	}
};

vi not_used;

struct CRP{
	
	int data_sz;
	int mn_q, mx_q;
	int cnt_miss;
	vi frq;
	vi in_cache;
	pque que;
	int water_level;
	
	CRP(){}
	
	CRP(int sz, int q0, int q1) : data_sz(sz), mn_q(q0), mx_q(q1){
		frq = vi(sz);
		in_cache = vi(sz, -1);
		water_level = 0;
	}
	
	void fix(){
		while((que.size() > mn_q) && (frq[que.top().second] <= water_level)){
			not_used.push_back(free_one());
		}	
	}
	
	void fix_one(){
		if(que.size() > mn_q){
			not_used.push_back(free_one());
		}	
	}
	
	int free_one(){
		
		assert(!que.empty());
		pii tp = que.top();
		que.pop();
		
		auto [f, i] = tp;
		int ret = in_cache[i];
		in_cache[i] = -1;
		
		if((int)que.size()+1 >= mn_q){
			assert((int)que.size() >= mn_q);
		}
		
		return ret;
	}
	
	bool test0(int i){
		
		if(in_cache[i]==-1){
			return ((int)que.size() > mn_q) || !not_used.empty();
		}
		
		return true;
	}
	
	bool test1(int i){
		
		if(in_cache[i]==-1){
			return ((int)que.size() == mx_q) || !not_used.empty();
		}
		
		return true;
	}
	
	int query(int i, int p=-1){
		
		if(in_cache[i]==-1){
			
			cnt_miss++;
			
			int np = p;
			if((int)que.size()==mx_q){
				np = free_one();
			}
			else if(!not_used.empty()){
				np = not_used.back();
				not_used.pop_back();
			}
			else if(np==-1 && ((int)que.size() > mn_q)){
				np = free_one();
			}
			else{
				assert(np != -1);
			}
			
			in_cache[i] = np;
			frq[i]++;
			que.push({frq[i]+water_level, i});
		}
		
		return in_cache[i];
	}
};

int32_t main(){    
    
	int n, q, m;
	cin >> n >> q >> m;
	
	vi vec_pri(n);
	for(auto &i : vec_pri) cin >> i;
	
	vi vec_siz(n);
	for(auto &i : vec_siz) cin >> i;
	
	vector<array<int, 3>> vec_q(n);
	for(auto &[q0, q1, q2] : vec_q){
		cin >> q0 >> q1 >> q2;
	}
	
	not_used = vi(q);
	iota(not_used.begin(), not_used.end(), 0);
	
	vector<LRU> lru(n);
	vector<CRP> crp(n);
	
	for(int i = 0; i < n; i++){
		lru[i] = LRU(vec_siz[i], vec_q[i][1]);
		crp[i] = CRP(vec_siz[i], vec_q[i][0], vec_q[i][2]);
	}
	
	auto calc_sla_rate = [&](int i)->double{
		double sla_actu = crp[i].cnt_miss;
		double sla_base = lru[i].cnt_miss;
		sla_actu = max(sla_actu, double(1));
		sla_base = max(sla_base, double(1));
		return (max(sla_actu, sla_base) - sla_base)/sla_base;
	};
	
	auto f1 = [](double x)->double{
		return double(3)*x*x;
	};
	
	auto f3 = [&](int i)->double{
		return double(vec_siz[i]-crp[i].que.size())/double(vec_siz[i]);
	};
	
	auto calc_cost = [&](int i, bool b=false)->double{
		if(b){
			return f1(calc_sla_rate(i)) * vec_pri[i];		
		}
		else{
			return f1(crp[i].cnt_miss * vec_pri[i]);
		}
	};
	
	set<pair<double, int>> st;
	vector<bool> in_st(n);
	
	auto st_add = [&](int i){
		if((int)crp[i].que.size() > crp[i].mn_q){
			st.insert({calc_cost(i), i});
			in_st[i] = true;
		}	
		else{
			in_st[i] = false;
		}
	};
	
	while(m--){
		
		int u, i;
		cin >> u >> i;
		u--, i--;
		
		int ans = -1;
		
		if(in_st[u]){
			auto p_u = st.find({calc_cost(u), u});
			auto ppu = *p_u;
			st.erase(p_u);
			in_st[u] = false;
		}
		
		lru[u].query(i);
		
		// if(!crp[u].test1(i)){
			// if(rand()%2==0){
				// crp[u].fix_one();
			// }
		// }
		
		if(crp[u].test1(i) || st.empty()){			
			ans = crp[u].query(i);
			st_add(u);
		}
		else{
			
			pii ppv = *st.begin();
			st.erase(st.begin());
			
			int p = crp[ppv.second].free_one();
			ans = crp[u].query(i, p);
			
			st_add(u);
			st_add(ppv.second);
		}
		
		// cout << ans+1 << endl << flush;
	}
	
	double sm = 0;
	for(int i = 0; i < n; i++){
		sm += calc_cost(i, true);
	}
	cout << sm << endl;
}

