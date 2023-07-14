// Problem: C. Sequence Master
// Contest: Codeforces - Codeforces Round 858 (Div. 2)
// URL: https://codeforces.com/contest/1806/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

		int n;
		cin >> n;
		
		int m = n;
		n *= 2;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		sort(vec.begin(), vec.end());
		
		vi pre(n);
		pre[0] = vec[0];
		for(int i = 1; i < n; i++){
			pre[i] = pre[i-1] + vec[i];
		}
		
		int ans = INFLL;
		
		{
			int i = 0;
			int p = lower_bound(vec.begin(), vec.end(), i)-vec.begin();
			
			int pr = p==0 ? 0 : pre[p-1];
			int sf = pre[n-1] - pr;
			
			int cans = (p*i - pr) + (sf - (n-p)*i);
			
			ans = min(ans, cans);
		}
		
		if(m==1){
			ans = min(ans, vec.back()-vec.front());	
		}
		
		if(m >= 2){
			
			int i = round(pow(double(10), (log10(m)/double(m-1))));
			
			double a = log(m);
			double b = log(i)*(m-1);
			
			if(abs(a-b) < 1e-7){
				
				int p = lower_bound(vec.begin(), vec.end(), i)-vec.begin();
				
				int pr = p==0 ? 0 : pre[p-1];
				int sf = pre[n-1] - pr;
				
				int cans = (p*i - pr) + (sf - (n-p)*i);
				
				ans = min(ans, cans);
			}
		}
		
		if(m >= 2 && m%2==0){
			
			int i = -1;	
			int p = lower_bound(vec.begin(), vec.end(), i)-vec.begin();
			int pr = p==0 ? 0 : pre[p-1];
			int sf = pre[n-1] - pr;
			int cans = (p*i - pr) + (sf - (n-p)*i);
			
			cans -= abs(vec.back()+1);
			cans += abs(vec.back()-m);
			
			ans = min(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
