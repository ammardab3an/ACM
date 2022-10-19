// Problem: D - Root M Leaper
// Contest: AtCoder - AtCoder Beginner Contest 272
// URL: https://atcoder.jp/contests/abc272/tasks/abc272_d
// Memory Limit: 1024 MB
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi tmp;
    for(int i = 0; i*i <= m; i++){
    	tmp.push_back(i*i);
    }
    
    vpii mv;
    for(auto i : tmp) if(binary_search(tmp.begin(), tmp.end(), m-i)){
    	int si = sqrt(i);
    	int sj = sqrt(m-i);
    	for(int j = 0; j < 4; j++){
    		mv.push_back({(j&1) ? si : -si, (j&2) ? sj : -sj});
    	}
    }
    
    // for(auto [x, y] : mv){
    	// cout << x << ' ' << y << endl;
    // }
    
    vector<vi> dist(n, vi(n, -1));
    
    queue<pii> que;
    que.push({0, 0});
    dist[0][0] = 0;
    
    while(!que.empty()){
    	
    	auto [i, j] = que.front();
    	que.pop();
    	
    	for(auto [x, y] : mv){
    		
    		int ni = i+x;
    		int nj = j+y;
    		
    		if(ni >= 0 && ni < n && nj >= 0 && nj < n){
    			if(dist[ni][nj]==-1){
    				dist[ni][nj] = dist[i][j]+1;
    				que.push({ni, nj});
    			}
    		}
    	}
    }
    
    for(auto r : dist){
    	for(auto e : r) cout << e << ' ';
    	cout << endl;
    }
}