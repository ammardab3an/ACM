// Problem: G. Current Objective: Survive
// Contest: Codeforces - UTPC Contest 03-25-22 Div 1. (Advanced)
// URL: https://codeforces.com/gym/103625/problem/G
// Memory Limit: 512 MB
// Time Limit: 7500 ms
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

const int LCM = 480;

int n, m, k;
pii dir[26];
bool grid[LCM][100][100];
int dist[LCM][100][100];
pii mvArr[] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m; 	
}

void fill_grid(int i, int j, int t, int k, int rem_k, pii mv){
	
	if(t == LCM){
		return;
	}
	
	assert(in(i, j));
	
	grid[t][i][j] = 0;
	
	if(k==1){
		fill_grid(i, j, t+1, k, k, mv);
		return;	
	}
	
	if(rem_k==1){
		mv.first *= -1;
		mv.second *= -1;	
		rem_k = k;
	}
	
	int ni = i + mv.first;
	int nj = j + mv.second;
	fill_grid(ni, nj, t+1, k, rem_k-1, mv);
}

int bfs(){
	
	memset(dist, -1, sizeof dist);
	
	queue<iii> que;
	que.push({0, {0, 0}});
	dist[0][0][0] = 0;
	
	while(!que.empty()){
		
		auto fr = que.front();
		que.pop();
		
		int t = fr.first;
		int i = fr.second.first;
		int j = fr.second.second;
		
		if(i==n-1 && j==m-1) break;
		
		for(auto p : mvArr){
			
			int nt = (t+1)%LCM;	
			int ni = i + p.first;
			int nj = j + p.second;
			
			if(!in(ni, nj) || !grid[nt][ni][nj] || dist[nt][ni][nj]!=-1) continue;
			
			dist[nt][ni][nj] = dist[t][i][j] + 1;
			que.push({nt, {ni, nj}});
		}
	}
	
	int ret = INFLL;
	for(int t = 0; t < LCM; t++) if(dist[t][n-1][m-1]!=-1){
		ret = min(ret, dist[t][n-1][m-1]);
	}
	
	return (ret==INFLL ? -1 : ret);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
    	string str;
    	cin >> str;
    	for(int j = 0; j < m; j++){
    		grid[0][i][j] = str[j]=='.';
    	}	
    }
    
    for(int t = 1; t < LCM; t++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
    	grid[t][i][j] = grid[0][i][j];
    }
    
    dir['N' - 'A'] = {-1, 0};
    dir['S' - 'A'] = {1, 0};
    dir['E' - 'A'] = {0, 1};
    dir['W' - 'A'] = {0, -1};
    
    while(k--){
    	
    	int i, j, x;
    	char c;
    	
    	cin >> i >> j >> x >> c;
    	i--, j--;
    	
    	fill_grid(i, j, 0, x, x, dir[c-'A']);
    }
    
    cout << bfs() << endl;
}
