// Problem: A. Careful Thief
// Contest: Codeforces - ACM International Collegiate Programming Contest, Amman Collegiate Programming Contest (2018)
// URL: https://codeforces.com/gym/101810/problem/A
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){
		
		int n, k;
		cin >> n >> k;
		
		vector<iii> vec(n);
		for(auto &[l, rv] : vec){
			auto &[r, v] = rv;
			cin >> l >> r >> v;
		}
		
		sort(vec.begin(), vec.end());
		
		vector<iii> tmp;
		tmp.push_back({0, {0, 0}});
		
		for(int i = 0; i < n; i++){
			if(tmp.back().second.first+1 < vec[i].first){
				tmp.push_back({tmp.back().second.first+1, {vec[i].first-1, 0}});
			}
			tmp.push_back(vec[i]);
		}
		
		int ans = 0;
		
		for(auto [l, rv] : tmp){
			auto [r, v] = rv;
			int cans = min(r-l+1, k) * v;
			ans = max(ans, cans);
		}
		
		auto calc = [&](int i){
			auto [l, rv] = tmp[i];
			auto [r, v] = rv;
			return (r-l+1);	
		};
		
		n = tmp.size();
		
		for(auto _ : {0, 1}){
			
			int j = 0;
			int sz = 0;
			int sm = 0;
			
			for(int i = 0; i < n; i++){
				
				if(i){
					sz -= calc(i-1);
					sm -= calc(i-1) * tmp[i-1].second.second;
				}
				
				while(j < n && sz+calc(j) <= k){
					sz += calc(j);
					sm += calc(j) * tmp[j].second.second;
					j++;
				}
				
				int cans = sm;
				if(j < n) cans += min(calc(j), k-sz) * tmp[j].second.second;
				ans = max(ans, cans);
			}
			
			reverse(tmp.begin(), tmp.end());
		}
		
		cout << ans << endl;
   }
}
