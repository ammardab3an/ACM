// Problem: E. Best Pair
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		
		vpii bad_pairs(m);
		for(auto &p : bad_pairs){
			cin >> p.first >> p.second;
		}
		
		vi tmp = vec;
		for(auto p : bad_pairs){
			tmp.push_back(p.first);
			tmp.push_back(p.second);
		}
		sort(tmp.begin(), tmp.end());
		tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
		
		for(auto &i : vec){
			i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
		}
		
		vector<vi> adj(tmp.size());
		
		for(auto &p : bad_pairs){
			p.first = lower_bound(tmp.begin(), tmp.end(), p.first) - tmp.begin();
			p.second = lower_bound(tmp.begin(), tmp.end(), p.second) - tmp.begin();
			adj[p.first].push_back(p.second);
			adj[p.second].push_back(p.first);
		}
		
		for(auto &v : adj){
			sort(v.begin(), v.end());
			v.resize(unique(v.begin(), v.end()) - v.begin());
		}
			
		vi cnt(tmp.size());
		for(auto i : vec){
			cnt[i]++;
		}
		
		map<int, vi> _mx;
		for(auto i : vec){
			_mx[cnt[i]].push_back(i);
		}
		for(auto &p : _mx){
			auto &v = p.second;
			sort(v.begin(), v.end());
			v.resize(unique(v.begin(), v.end()) - v.begin());
		}
		
		vector<pair<int, vi>> mx;
		for(auto p : _mx){
			mx.push_back(p);
		}
		
		int ans = 0;
		
		for(int _k = 0; _k < mx.size(); _k++){
			
			int cur_mx = 0;
			auto &v = mx[_k].second;
			
			for(int i = v.size()-1; i >= 0; i--)
			for(int j = i-1; j >= 0; j--) if(v[i] != v[j]){
				
				int cans = tmp[v[i]]+tmp[v[j]];
				if(cans < cur_mx) break;
				
				auto it = lower_bound(adj[v[i]].begin(), adj[v[i]].end(), v[j]);
				if((it != adj[v[i]].end()) && (*it==v[j])) continue;
				
				cur_mx = cans;
				break;
			}
			
			ans = max(ans, cur_mx * (mx[_k].first*2));
		}
		
		for(int k0 = 0; k0 < mx.size(); k0++) if(mx[k0].second.size())
		for(int k1 = k0+1; k1 < mx.size(); k1++) if(mx[k1].second.size()){
			
			int cur_mx = 0;
			auto &v0 = mx[k0].second;
			auto &v1 = mx[k1].second;
			
			for(int i = v0.size()-1; i >= 0; i--)
			for(int j = v1.size()-1; j >= 0; j--) if(v0[i] != v1[j]){
				
				int cans = tmp[v0[i]]+tmp[v1[j]];
				if(cans < cur_mx) break;
				
				auto it = lower_bound(adj[v0[i]].begin(), adj[v0[i]].end(), v1[j]);
				if((it != adj[v0[i]].end()) && *it == v1[j]) continue;
				
				cur_mx = cans;
				break;
			}
			
			ans = max(ans, cur_mx * (mx[k0].first+mx[k1].first));
		}
		
		cout << ans << endl;
    }	
}
