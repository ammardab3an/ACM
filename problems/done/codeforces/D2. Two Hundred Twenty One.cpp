// Problem: D1. Two Hundred Twenty One (easy version)
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1562/D1
// Memory Limit: 512 MB
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

		int n, q;
		cin >> n >> q;
		
		string str;
		cin >> str;
		
		vi pre(n), val(n);
		pre[0] = str[0]=='-' ? -1 : +1;
		val[0] = pre[0];
		for(int i = 1; i < n; i++){
			val[i] = (str[i] == "-+"[i%2]) ? -1 : +1;
			pre[i] = pre[i-1] + val[i];	
		}
		
		vector<vpii> tmp(n);
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			tmp[r-1].push_back({l-1, i});
		}
		
		int water_level = 0;
		multiset<pii> mst;
		
		vector<vi> ans(q);
		
		for(int r = 0; r < n; r++){
			
			water_level += val[r];	
			mst.insert({val[r] - water_level, -r});
					
			for(auto [l, q_idx] : tmp[r]){
	
				int sm = pre[r];
				if(l) sm -= pre[l-1];
				
				if(sm==0){
					continue;
				}
				
				if(abs(sm)%2==1){
					int _sm = sm >= 0 ? (sm+1)/2 : (sm-1)/2;
					auto it = mst.lower_bound({_sm - water_level, -INF});
					assert((water_level+it->first) == _sm);
					ans[q_idx].push_back(1-it->second);
				}
				else{
					sm -= val[r];
					water_level -= val[r];
					int _sm = sm >= 0 ? (sm+1)/2 : (sm-1)/2;
					auto it = mst.lower_bound({_sm - water_level, -INF});
					assert((water_level+it->first) == _sm);
					ans[q_idx].push_back(r+1);
					ans[q_idx].push_back(1-it->second);
					water_level += val[r];
				}
			}
		}
		
		for(auto v : ans){
			cout << v.size() << endl;
			if(v.size()){			
				for(auto i : v) 
					cout << i << ' '; 
				cout << endl;
			}
		}
    }	
}
