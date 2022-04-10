// Problem: Swap Game
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1670
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

int dist[9][9][9][9][9][9][9][9];

void set_dist(const vector<vi> &vec, int d){
	dist[vec[0][0]][vec[0][1]][vec[0][2]][vec[1][0]][vec[1][1]][vec[1][2]][vec[2][0]][vec[2][1]] = d;	
}

int get_dist(const vector<vi> &vec){
	return dist[vec[0][0]][vec[0][1]][vec[0][2]][vec[1][0]][vec[1][1]][vec[1][2]][vec[2][0]][vec[2][1]];	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    // freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    vector<vi> vec(3, vi(3));
    
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
    	cin >> vec[i][j];
    	vec[i][j]--;
    }
    
    priority_queue<pair<int, vector<vi>>> que;
    
    memset(dist, INF, sizeof dist);
    
    set_dist(vec, 0);
    que.push({0, vec});
    
    while(!que.empty()){
    	
    	auto tp = que.top();
    	que.pop();
    	
    	int cd = -tp.first;
    	vector<vi> grid = tp.second;
    	
    	if(get_dist(grid) < cd) continue;
    	
    	for(int i = 0; i < 2; i++)
    	for(int j = 0; j < 3; j++){
    		swap(grid[i][j], grid[i+1][j]);
    		if(get_dist(grid) > cd+1){
    			set_dist(grid, cd+1);
    			que.push({-(cd+1), grid});
    		}
    		swap(grid[i][j], grid[i+1][j]);
    	}
    	
    	for(int i = 0; i < 3; i++)
    	for(int j = 0; j < 2; j++){
    		swap(grid[i][j], grid[i][j+1]);
    		if(get_dist(grid) > cd+1){
    			set_dist(grid, cd+1);
    			que.push({-(cd+1), grid});
    		}
    		swap(grid[i][j], grid[i][j+1]);
    	}
    }
    
    int ans = get_dist((vector<vi>){{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
    cout << ans << endl;
}
