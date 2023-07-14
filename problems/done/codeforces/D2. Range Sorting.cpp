// Problem: D2. Range Sorting (Hard Version)
// Contest: Codeforces - Codeforces Round 873 (Div. 2)
// URL: https://codeforces.com/contest/1828/problem/D2
// Memory Limit: 256 MB
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

int inv(int x){
	return pow_exp(x, MOD-2);
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
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi nxt_mn(n), pre_mx(n), pre_mn(n);
		{
			stack<pii> st;
			for(int i = n-1; i >= 0; i--){
				
				while(!st.empty() && st.top().first > vec[i]){
					st.pop();
				}
				
				if(!st.empty()){
					nxt_mn[i] = st.top().second;
				}
				else{
					nxt_mn[i] = n;
				}
				
				st.push({vec[i], i});
			}
		}
		{
			stack<pii> st;
			for(int i = 0; i < n; i++){
				
				while(!st.empty() && st.top().first < vec[i]){
					st.pop();
				}
				
				if(!st.empty()){
					pre_mx[i] = st.top().second;
				}
				else{
					pre_mx[i] = -1;
				}
				
				st.push({vec[i], i});
			}
		}
		{
			stack<pii> st;
			for(int i = 0; i < n; i++){
				
				while(!st.empty() && st.top().first > vec[i]){
					st.pop();
				}
				
				if(!st.empty()){
					pre_mn[i] = st.top().second;
				}
				else{
					pre_mn[i] = -1;
				}
				
				st.push({vec[i], i});
			}
		}
		
		int log_n = ceil(log2(double(n)));
		vector<vi> fst_pre_mx(n, vi(log_n, -1));
		
		for(int i = 1; i < n; i++){
			fst_pre_mx[i][0] = pre_mx[i];
			for(int j = 1; j < log_n; j++){
				if(fst_pre_mx[i][j-1]==-1) break;
				fst_pre_mx[i][j] = fst_pre_mx[fst_pre_mx[i][j-1]][j-1];
			}
		}
		
		
		int ans = 0;
		
		// 1*(n-1) + 2*(n-2) + 3*(n-3) + ..
		for(int i = 1; i < n; i++){
			ans += i*(n-i);
		}
		
		for(int i = 1; i < n; i++) if(pre_mn[i]!=-1) {
			
			int k = pre_mn[i];
			int y = nxt_mn[i];
			int x = k;
			
			for(int j = log_n-1; j >= 0; j--){
				if(x==-1) break;
				if(fst_pre_mx[x][j]==-1) continue;
				if(vec[fst_pre_mx[x][j]] < vec[i]){
					x = fst_pre_mx[x][j];
				}
			}
			
			if(x!=-1){
				x = fst_pre_mx[x][0];
			}
			
			ans -= (k-x)*(y-i);
		}
		
		cout << ans << endl;
    }	
}