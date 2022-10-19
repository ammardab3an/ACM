// Problem: D. Rain
// Contest: Codeforces - Codeforces Round #810 (Div. 2)
// URL: https://codeforces.com/contest/1711/problem/D
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

int sz;
int tmp[NMAX];

vi pre_calc(const vector<vi> &vec){
	
	vi ret(sz);
	
	int water_lvl = 0;
	multiset<int> mst;
	int mst_sm = 0;
	
	for(int i = 0; i < sz; i++){
		
		if(i){
			int dis = tmp[i] - tmp[i-1];
			water_lvl += dis;
			mst_sm -= dis * mst.size();
			while(!mst.empty() && ((*mst.begin())-water_lvl) <= 0){
				mst_sm += water_lvl - (*mst.begin());
				mst.erase(mst.begin());
			}
		}
		
		for(auto p : vec[i]){
			mst.insert(p+water_lvl);
			mst_sm += p;
		}
		
		ret[i] = mst_sm;
	}	
	
	return ret;
}

vi suf_calc(const vector<vi> &vec){
	
	vi ret(sz);
	
	int water_lvl = 0;
	multiset<int> mst;
	int mst_sm = 0;
	
	for(int i = sz-1; i >= 0; i--){
		
		if(i!=sz-1){
			int dis = tmp[i+1] - tmp[i];
			water_lvl += dis;
			mst_sm -= dis * mst.size();
			while(!mst.empty() && ((*mst.begin())-water_lvl) <= 0){
				mst_sm += water_lvl - (*mst.begin());
				mst.erase(mst.begin());
			}
		}
		
		for(auto p : vec[i]){
			mst.insert(p+water_lvl);
			mst_sm += p;
		}
		
		ret[i] = mst_sm;
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
    
    int t; cin >> t; while(t--){
    	
		int n, m;
		cin >> n >> m;
		
		sz = 0;
		
		vpii vec(n);
		for(auto &p : vec){
			cin >> p.first >> p.second;
			tmp[sz++] = p.first;	
		}
		
		sort(tmp, tmp+sz);
		sz = unique(tmp, tmp+sz)-tmp;
		for(auto &p : vec){
			p.first = lower_bound(tmp, tmp+sz, p.first)-tmp;
		}
		
		vector<vi> nvec(sz);
		for(auto [x, p]: vec){
			nvec[x].push_back(p);
		}
		
		vi v0 = pre_calc(nvec);
		vi v1 = suf_calc(nvec);
		
		vi res(sz);
		for(int i = 0; i < sz; i++){
			res[i] =  v0[i] + v1[i];
		}
		
		for(int i = 0; i < sz; i++){
			for(auto &p : nvec[i]){
				res[i] -= p;
			}
		}
		
		for(auto &i : res) if(i <= m){
			i = -INF;
		}
		
		multiset<int> pre, suf;
		int lvl_pre = 0, lvl_suf = 0;
		
		for(int i = 0; i < sz; i++){
			int dist = tmp[i]-tmp[0];
			suf.insert(res[i]+dist);
		}
		
		vi ans(sz);
		
		for(int i = 0; i < sz; i++){
			
			if(i){			
				int dist = tmp[i]-tmp[i-1];
				lvl_pre -= dist;
				lvl_suf += dist;
				suf.erase(suf.find(res[i-1]-dist+lvl_suf));
				pre.insert(res[i-1]+dist+lvl_pre);
			}
			
			int mx_pre = pre.empty() ? 0 : (*pre.rbegin()) - lvl_pre;
			int mx_suf = suf.empty() ? 0 : (*suf.rbegin()) - lvl_suf;
			int mx = max(mx_pre, mx_suf);
			
			ans[i] = mx-m;
		}
		
		for(int i = 0; i < n; i++){
			cout << (vec[i].second >= ans[vec[i].first]);
		}
		cout << endl;
    }	
}
