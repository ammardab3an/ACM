// Problem: H. Banquet Preparations 2
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/H
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    
    // fastIO;
    #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
	
		int n;
		cin >> n;
		
		vector<vi> vec(n, vi(3));
		
		for(auto &v : vec) for(auto &i : v) cin >> i;
		
		vi pos(n);
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&](int i, int j){
			return vec[i][0]+vec[i][1]-vec[i][2] < vec[j][0]+vec[j][1]-vec[j][2];
		});
		
		int ans_cnt = 0;
		vector<vi> ans(n, vi(2));
		
		while(!pos.empty()){
			
			vector<pair<int, vi> > tmp;

			int p = pos.back();
			int sm = vec[p][0] + vec[p][1] - vec[p][2];
			
			while(!pos.empty()){
				int p = pos.back();
				int csum = vec[p][0] + vec[p][1] - vec[p][2];
				if(csum != sm) break;
				tmp.push_back({p, vec[p]});
				pos.pop_back();
			}	
			
			multiset<iii> mst, tsm;
			
			for(auto [p, v] : tmp){
				
				int l = v[0] - (min(v[0], v[2]));
				int r = v[0] - (v[2] - min(v[1], v[2]));
				
				mst.insert({l, {p, r}});
				tsm.insert({r, {p, l}});	
			}
			
			while(!mst.empty()){
				
				ans_cnt++;
				
				iii mn = *tsm.begin();
				
				int p = mn.second.first;
				int st = mn.first;
				int nd = vec[p][1] - (vec[p][2] - (vec[p][0] - mn.first));
				
				while(!mst.empty() && ((mst.begin()->first) <= mn.first)){
					iii t = *mst.begin();
					mst.erase(mst.begin());
					tsm.erase(tsm.find({t.second.second, {t.second.first, t.first}}));
					int cp = t.second.first;
					ans[cp][0] = vec[cp][0] - st;
					ans[cp][1] = vec[cp][1] - nd;
				}
			}
		}
		
		cout << ans_cnt << endl;
		for(auto v : ans){
			for(auto i : v) cout << i << ' ' ; cout << endl;
		}
    }	
}
