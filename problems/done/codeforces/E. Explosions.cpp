// Problem: E. Explosions?
// Contest: Codeforces - Educational Codeforces Round 143 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1795/problem/E
// Memory Limit: 256 MB
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

vi go(int n, const vi &vec){
	
	vi ret(n);
	vi pre = vec;
	for(int i = 1; i < n; i++){
		pre[i] += pre[i-1];
	}
	
	stack<pii> st;
	for(int i = n-1; i >= 0; i--){
		
		while(!st.empty() && (vec[i]+i < st.top().first)){
			st.pop();
		}
		
		int l = i;
		int r = n-1;
		int cans = 0;
		
		if(!st.empty()){
			r = st.top().second-1;
			cans += ret[st.top().second];
		}	
		
		int cnt = r-l+1;
		cnt = min(cnt, vec[i]);
		int st_path = pre[r]-pre[l]+vec[l];
		int nd_path = vec[i]*cnt - ((cnt*(cnt-1))/2);
		cans += st_path-nd_path;
		
		ret[i] = cans;
		st.push({vec[i]+i, i});
	}	
	
	return ret;
}

void test(int n, const vi &vec){
	
	for(int i = 0; i < n; i++){
		
		int h = vec[i];
		int ans = 0;
		
		for(int j = i+1; j < n; j++){
			
			h--;
			if(vec[j] <= h){
				h = vec[j];
			}
			else{
				ans += vec[j]-h;
			}
		}
		
		cout << ans << ' ';
	}	
	
	cout << endl;
}

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
		
		vi ans0 = go(n, vec);
		// for(auto i : ans0) cout << i << ' ' ; cout << endl;
		
		reverse(vec.begin(), vec.end());
		vi ans1 = go(n, vec);
		reverse(vec.begin(), vec.end());
		reverse(ans1.begin(), ans1.end());
		// for(auto i : ans1) cout << i << ' ' ; cout << endl;
// 			
		vi ans(n);
		for(int i = 0; i < n; i++){
			ans[i] = ans0[i] + ans1[i] + vec[i];
		}
		
		// for(auto i : ans) cout << i << ' '; cout << endl;
		
		int mn = *min_element(ans.begin(), ans.end());
		cout << mn << endl;
    }	
}
