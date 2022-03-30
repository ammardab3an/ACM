// Problem: D. Big Brush
// Contest: Codeforces - Codeforces Round #771 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1638/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int n, m;
int grid[1010][1010];
bool vis[1010][1010];
bool spe[1010][1010];
int tmp[1010][1010];

void test(vector<pair<pii, int>> ans){
	
	for(auto p : ans){
		
		int i = p.first.first;
		int j = p.first.second;
		int c = p.second;
		
		if(!(0 <= i && i < n-1 && 0 <= j && j < m-1)){
			return;
		}
		
		tmp[i][j] = tmp[i+1][j] = tmp[i][j+1] = tmp[i+1][j+1] = c;
	}	
	
	for(int i = 0; i < n; i++){	
		for(int j = 0; j < m; j++)
			cout << tmp[i][j] << ' ';
		cout << endl;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
    
    queue<pii> que;
    vector<pair<pii, int>> ans;
    
    for(int i = 0; i < n-1; i++)
    for(int j = 0; j < m-1; j++){
    	
    	if(grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i+1][j+1]){
    		vis[i][j] = true;
    		que.push({i, j});
    		ans.push_back({{i, j}, grid[i][j]});
    		spe[i][j] = spe[i+1][j] = spe[i][j+1] = spe[i+1][j+1] = true;
    	}
    }
    
    while(!que.empty()){
    	
    	pii fr = que.front();
    	que.pop();
    	
    	int i = fr.first;
    	int j = fr.second;
		
    	for(int ni = i-1; ni <= i+1; ni++)
    	for(int nj = j-1; nj <= j+1; nj++){
    		if(0 <= ni && ni < n-1 && 0 <= nj && nj < m-1 && !vis[ni][nj]){
    			
    			set<int> st;
    			if(!spe[ni][nj]) st.insert(grid[ni][nj]);
    			if(!spe[ni+1][nj]) st.insert(grid[ni+1][nj]);
    			if(!spe[ni][nj+1]) st.insert(grid[ni][nj+1]);
    			if(!spe[ni+1][nj+1]) st.insert(grid[ni+1][nj+1]);
    			
    			
    			if(st.size() == 1){
    				
    				vis[ni][nj] = true;
    				que.push({ni, nj});
    				
    				if(!st.empty()){
	    				ans.push_back({{ni, nj}, *st.begin()});
	    				spe[ni][nj] = spe[ni+1][nj] = spe[ni][nj+1] = spe[ni+1][nj+1] = true;
    				}
    			}
    		}
    	}
    }
    
    bool good = true;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) good &= spe[i][j];
    
    if(!good){
    	cout << -1 << endl;
    	return 0;
    }
    
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto p : ans){
    	cout << p.first.first+1 << ' ' << p.first.second+1 << ' ' << p.second << endl;
    }
    
	// test(ans);   
}
