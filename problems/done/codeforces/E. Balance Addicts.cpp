// Problem: E. Balance Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int MOD = 998244353 ; //1e9 + 7;
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

int fac[NMAX], ifac[NMAX];

void init(){
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		if(n==1){
			cout << 1 << endl;
			continue;
		}
		
		int sm = 0;
		for(auto i : vec) sm += i;
		
		int sm_pre=0, sm_suf=0;
		map<int, int> mp_pre, mp_suf;
		
		for(int i = 0; i < n; i++){
			sm_pre += vec[i];
			if(sm_pre*2 > sm) break;
			mp_pre[sm_pre]++;
		}
		
		for(int i = n-1; i >= 0; i--){
			sm_suf += vec[i];
			if(sm_suf*2 > sm) break;
			mp_suf[sm_suf]++;
		}
		
		vpii pre(mp_pre.rbegin(), mp_pre.rend());
		vpii suf(mp_suf.rbegin(), mp_suf.rend());
		
		int ans = 1;
		
		// cout << "pre" << endl;
		// for(auto [a, b] : pre){
			// cout << a << ' ' << b << endl;
		// }
		// cout << "suf" << endl;
		// for(auto [a, b] : suf){
			// cout << a << ' ' << b << endl;
		// }
		
		while(!pre.empty() && !suf.empty()){
			
			if(pre.back().first < suf.back().first){
				swap(pre, suf);
			}
			
			if(pre.back().first != suf.back().first){
				suf.pop_back();
				continue;	
			}
			
			pii p = pre.back();
			pii s = suf.back();
			pre.pop_back();
			suf.pop_back();
			
			if(p.first*2==sm){
				if(p.second==1){
					int cans = 2;
					ans = mul(ans, cans);
				}
				else{
					int cans = pow_exp(2, p.second - (p.second==n));
					ans = mul(ans, cans);
				}
				continue;
			}
			
			int mn = min(p.second, s.second);
			
			// cout << p.second << ' ' << s.second << ' ' << mn << endl;
			
			int cans = 0;
			for(int i = 0; i <= mn; i++){
				cans = add(cans, mul(choose(p.second, i), choose(s.second, i)));
			}
			
			ans = mul(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
