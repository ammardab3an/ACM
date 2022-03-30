// Problem: D. Cross Coloring
// Contest: Codeforces - Educational Codeforces Round 123 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1644/problem/D
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
const int MOD = 998244353; //1e9 + 7;
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

		int n, m, k, q;
		cin >> n >> m >> k >> q;
		
		vpii tmp(q);
		for(auto &p : tmp){
			cin >> p.first >> p.second;
			p.first--, p.second--;
		}
		
		int cnt=0, cnt_n=0, cnt_m=0;
		vector<bool> vis_n(n), vis_m(m);
		
		for(int i = q-1; i >= 0; i--){
			
			pii p = tmp[i];
			int x = p.first;
			int y = p.second;
			
			if(vis_n[x] && vis_m[y]){
				continue;
			}
			
			cnt++;
			cnt_n += vis_n[x]==0;
			cnt_m += vis_m[y]==0;
			
			vis_n[x] = true;
			vis_m[y] = true;
			
			if(cnt_n==n || cnt_m==m){
				break;
			}
		}
		
		int ans = pow_exp(k, cnt);
		cout << ans << endl;
    }	
}
