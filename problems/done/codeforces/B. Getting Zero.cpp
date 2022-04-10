// Problem: B. Getting Zero
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/B
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

const int mod = 32768;
int dist[NMAX];
int par[NMAX];

void bfs(){
	
	memset(dist, -1, sizeof dist);
	
	queue<int> que;
	que.push(0);
	dist[0] = 0;
	
	while(!que.empty()){
		
		int fr = que.front();
		que.pop();
		
		int x = fr;
		
		{
			int nx = (x-1+mod)%mod;
			
			if(dist[nx] == -1){
				dist[nx] = dist[x]+1;
				par[nx] = x;
				que.push(nx);
			}
		}
		
		if(x%2==0){
			
			{
				int nx = x/2;
				if(dist[nx] == -1){
					dist[nx] = dist[x]+1;
					par[nx] = x;
					que.push(nx);
				}
			}
			{
				int nx = (mod+x)/2;
				if(dist[nx] == -1){
					dist[nx] = dist[x]+1;
					par[nx] = x;
					que.push(nx);
					
				}
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
    
    bfs();
    
    // {
    	// int x = 10240;
    	// while(x != 0){
    		// cout << x << endl;
    		// x = par[x];		
    	// }
    	// cout << x << endl;
//     	
    	// return 0;
    // }
    
	int n;
	cin >> n;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	for(auto i : vec) cout << dist[i] << ' '; cout << endl;
}
