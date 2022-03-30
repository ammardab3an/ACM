// Problem: C. Weight of the System of Nested Segments
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/contest/1650/problem/C
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
		
		vpii vec(m);
		for(auto &p : vec){
			cin >> p.first >> p.second;
		}
		
		vi pos(m);
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&](int i, int j){
			return vec[i].first < vec[j].first;
		});
		
		vi pre(m), suf(m);
		
		{
			int sm = 0;		
			multiset<int> mst;
			for(int i = 0; i < n-1; i++){
				sm += vec[pos[i]].second;
				mst.insert(-vec[pos[i]].second);
			}
			
			for(int i = n-1; i < m; i++){
				sm += vec[pos[i]].second;
				mst.insert(-vec[pos[i]].second);
				if(mst.size() > n){
					sm += *mst.begin();				
					mst.erase(mst.begin());
				}
				pre[i] = sm;
			}
		}
		{
			int sm = 0;
			multiset<int> mst;
			for(int i = 0; i < n-1; i++){
				sm += vec[pos[m-i-1]].second;
				mst.insert(-vec[pos[m-i-1]].second);
			}
			
			for(int i = m-n; i >= 0; i--){
				sm += vec[pos[i]].second;
				mst.insert(-vec[pos[i]].second);
				if(mst.size() > n){
					sm += *mst.begin();
					mst.erase(mst.begin());
				}
				suf[i] = sm;
			}
		}
		
		int mn_sm = INF;
		int mn_pos = -1;
		
		for(int i = n; i <= m-n; i++){
			int cur = pre[i-1] + suf[i];
			if(cur < mn_sm){
				mn_sm = cur;
				mn_pos = i;
			}
		}
		
		cout << mn_sm << endl;
		
		multiset<pii> mst_pre, mst_suf;
		
		for(int i = 0; i < mn_pos; i++){
			mst_pre.insert({-vec[pos[i]].second, pos[i]});
			if(mst_pre.size() > n) mst_pre.erase(mst_pre.begin());
		}
		
		for(int i = m-1; i >= mn_pos; i--){
			mst_suf.insert({-vec[pos[i]].second, pos[i]});
			if(mst_suf.size() > n) mst_suf.erase(mst_suf.begin());
		}
		
		vi tmp;
		for(auto p : mst_pre){
			tmp.push_back(p.second);
		}
		for(auto p : mst_suf){
			tmp.push_back(p.second);
		}
		
		sort(tmp.begin(), tmp.end(), [&](int i, int j){
			return vec[i].first < vec[j].first;
		});
		
		for(int i = 0; i < n; i++){
			// cout << vec[tmp[i]].first << ' ' << vec[tmp[2*n-i-1]].first << endl;
			cout << tmp[i]+1 << ' ' << tmp[2*n-i-1]+1 << endl;
		}
		cout << endl;
    }	
}
