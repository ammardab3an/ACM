// A - Artwork
// https://codeforces.com/gym/101550/problem/A

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
 
const int NMAX = 1e3 + 10;
const int QMAX = 1e4 + 10;

int n, m, q;
bool grid[NMAX][NMAX];
int black[NMAX][NMAX];
bool vis[NMAX][NMAX];
pair<pii, pii> queries[QMAX];
pii par[NMAX][NMAX];
int tot;

pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;	
}

pii get_par(pii u){
	
	int i = u.first;
	int j = u.second;
	
	if(par[i][j] == (pii){i, j}){
		return {i, j};
	}	
	else{
		return par[i][j] = get_par(par[i][j]);
	}
}

void init(){
	
	tot = n*m;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		par[i][j] = {i, j};
	}	
}

bool merge(pii u, pii v){
	
	u = get_par(u);
	v = get_par(v);
	
	if(u==v){
		return false;
	}	
	
	if(rand()&1){
		swap(u, v);
	}
	
	par[u.first][u.second] = v;
	
	tot--;
	
	return true;
}

void dfs(int i, int j){
	
	vis[i][j] = true;
	for(auto p : mvArr){
		int ni = i + p.first;
		int nj = j + p.second;
		if(in(ni, nj) && !black[ni][nj] && !vis[ni][nj]){
			merge({i, j}, {ni, nj});
			dfs(ni, nj);
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
    
    cin >> n >> m >> q;
    
    init();
    
    for(int i = 0; i < q; i++){
    	
    	int x0, y0, x1, y1;
    	cin >> x0 >> y0 >> x1 >> y1;
    	x0--, y0--, x1--, y1--;
    	
    	if(x0 > x1) swap(x0, x1);
    	if(y0 > y1) swap(y0, y1);
    	
    	queries[i] = {{x0, y0}, {x1, y1}};
    	
    	for(int i = x0; i <= x1; i++)
    	for(int j = y0; j <= y1; j++){
    		if(!black[i][j]) tot--;
    		black[i][j]++;
    	}
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(!black[i][j] && !vis[i][j]){
    	dfs(i, j);
    }
    
    vi ans(q);
    for(int qq = q-1; qq >= 0; qq--){
    	
    	ans[qq] = tot;
    	
    	int x0 = queries[qq].first.first;
    	int y0 = queries[qq].first.second;
    	int x1 = queries[qq].second.first;
    	int y1 = queries[qq].second.second;
    	
    	for(int i = x0; i <= x1; i++)
    	for(int j = y0; j <= y1; j++){
    		
    		black[i][j]--;
    		
    		if(!black[i][j]){
    			
    			tot++;
    				
	    		for(auto p : mvArr){
	    			
	    			int ni = i + p.first;
	    			int nj = j + p.second;
	    			
	    			if(in(ni, nj) && !black[ni][nj]){
	    				merge({i, j}, {ni, nj});
	    			}
	    		}	
    		}
    	}	
    }
    
    for(auto i : ans){
    	cout << i << endl;
    }
}
