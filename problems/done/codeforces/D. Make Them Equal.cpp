// Problem: D. Make Them Equal
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1633/problem/D
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
 
const int NMAX = 1e3 + 10;
const int KMAX = 1e6 + 10;
const int AMAX = 1e3 + 10;

int n, k;
int arr_b[NMAX];
int arr_c[NMAX];
int dist[AMAX];

void init(){
	
	memset(dist, -1, sizeof dist);
	
	dist[1] = 0;
	queue<int> que;
	que.push(1);
	
	while(!que.empty()){
		
		int fr = que.front();
		que.pop();
		
		if(fr > 1e3){		
			continue;
		}
		
		for(int i = 1; i <= fr; i++){
			int nxt = fr + fr/i;
			if(dist[nxt]==-1){
				dist[nxt] = dist[fr]+1;
				que.push(nxt);
			}
		}
	}	
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

		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> arr_b[i];
		for(int i = 0; i < n; i++) cin >> arr_c[i];
		
		int sm = 0;
		for(int i = 0; i < n; i++) sm += arr_c[i];
		
		if(k > n*15){
			cout << sm << endl;
			continue;
		}
		
		vi dp(k+1);
		
		for(int i = 0; i < n; i++){
			
			int cost_i = dist[arr_b[i]];
			int tmp = arr_c[i];
			
			for(int j = k; j >= cost_i; j--){
				dp[j] = max(dp[j], dp[j-cost_i]+tmp);
			}
		}
		
		cout << dp[k] << endl;
    }	
}
