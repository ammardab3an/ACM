// Problem: D. Robot Cleaner Revisit
// Contest: Codeforces - Codeforces Round #763 (Div. 2)
// URL: https://codeforces.com/contest/1623/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
		
		int i0, j0, i1, j1;
		cin >> i0 >> j0 >> i1 >> j1;
		i0--, j0--, i1--, j1--;
		
		int p, q;
		cin >> p;
		q = 100-p;
		
		int _100 = pow_exp(100, MOD-2);
		p = mul(p, _100);
		q = mul(q, _100);
		
		vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(3, vector<bool>(3))));
		
		vi pre;
		int cnt = 0;
		
		int i = i0, j = j0;
		int di = 1, dj = 1;
		while(true){
			
			if(i+di==-1 || i+di==n) di *= -1;
			if(j+dj==-1 || j+dj==m) dj *= -1;
			if(vis[i][j][di+1][dj+1]) break;
			vis[i][j][di+1][dj+1] = true;
			
			if(i==i1 || j==j1){
				pre.push_back(cnt);
				cnt = 0;
			}
			cnt++;
			
			i += di;
			j += dj;
		}
		
		if(pre.empty()){
			cout << 0 << endl;
			continue;
		}
		
		for(int i = 1; i < pre.size(); i++){
			pre[i] += pre[i-1];
		}
		
		int sm = 0;
		int cp = p, cq = 1;
		for(auto i : pre){
			sm = add(sm, mul(mul(cp, cq), i));
			cq = mul(cq, q);
		}
		
		sm = add(sm, mul(cq, add(pre.back(), cnt)));
		
		int ans = mul(sm, pow_exp(add(1, mul(-1, cq)), MOD-2));
		cout << ans << endl;
    }	
}

/*
ex = p*(pre[0]) + q*p(pre[1]) + q*q*p(pre[2]) + ... q^(n-1)*p*(pre[n]) + q^n*(pre[n]+cnt+ex)
ex = 1/(1-q^n) * (p*(pre[0]) + q*p(pre[1]) + ... + q^(n-1)*p*pre[n] + q^n*(pre[n]+cnt))
*/