// Problem: D. Maximum Product Strikes Back
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/contest/1660/problem/D
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

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vector< pair<int, vi> > v;
		v.push_back({-1, {}});
		
		for(int i = 0; i < n; i++){
			
			if(vec[i]==0){
				v.push_back({-1, {}});
				continue;
			}	
			
			if(v.back().first==-1){
				v.back().first = i;
			}
			
			v.back().second.push_back(vec[i]);
		}
		
		int ans = 0;
		pii ans_del = {n, 0};
		
		for(int k = 0; k < v.size(); k++){
			
			int cur_i = v[k].first;
			vi cur_v = v[k].second;
			
			int cnt = 0;
			int sign = 0;
			
			for(int i = 0; i < (int)cur_v.size(); i++){
				
				if(cur_v[i] == 2 || cur_v[i] == -2){
					cnt++;
				}
				if(cur_v[i] < 0){
					sign ^= 1;
				}
				
				if(!sign && cnt > ans){
					ans = cnt;
					ans_del.first = cur_i;
					ans_del.second = n - (i+cur_i+1);
				}
			}
			
			reverse(cur_v.begin(), cur_v.end());
			
			cnt = sign = 0;
			
			for(int i = 0; i < (int)cur_v.size(); i++){
				
				if(cur_v[i] == 2 || cur_v[i] == -2){
					cnt++;
				}
				if(cur_v[i] < 0){
					sign ^= 1;
				}
				
				if(!sign && cnt > ans){
					ans = cnt;
					ans_del.first = cur_i + (int)cur_v.size()-i-1;
					ans_del.second = n - cur_i - (int)cur_v.size();
				}
			}
		}
		
		// cout << ans << endl;
		cout << ans_del.first << ' ' << ans_del.second << endl;
    }	
}
