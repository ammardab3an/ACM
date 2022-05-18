// Problem: G. Banquet Preparations 1
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/G
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
		
		vector<vi> vec(n, vi(2));
		
		for(auto &v : vec){
			cin >> v[0] >> v[1];
		}
		
		int ans_dif = INFLL;
		vector<vi> ans(n, vi(2));
		
		for(auto b : {0, 1}){
			
			vpii tmp;
			int cans_dif = 0;
			vector<vi> cans(n, vi(2));
			
			for(int i = 0; i < n; i++){
				
				int mn = min(vec[i][b], m);
				int rm = m-mn;
				
				cans[i][b] += mn;
				cans[i][!b] += rm;
				
				int k = min(mn, vec[i][!b]-rm);
				if(k) tmp.push_back({k, i});
				
				cans_dif += vec[i][!b] - rm;
				cans_dif -= vec[i][b] - mn;
			}
			
			if(cans_dif < 0) continue;
			
			sort(tmp.begin(), tmp.end());
			
			while(!tmp.empty() && (cans_dif > 1)){
				
				int mn = min(cans_dif/2, tmp.back().first);
				
				cans_dif -= mn*2;
				
				int p = tmp.back().second;
				cans[p][b] -= mn;
				cans[p][!b] += mn;
				
				tmp.pop_back();	
			}
			
			if(cans_dif < ans_dif){
				ans_dif = cans_dif;
				ans = cans;
			}
		}
		
		cout << ans_dif << endl;
		for(auto v : ans){
			for(auto i : v) cout << i << ' ';
			cout << endl;
		}
    }	
}
