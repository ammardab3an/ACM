// Problem: M. Tomb Hater
// Contest: Codeforces - 2021-2022 ICPC East Central North America Regional Contest (ECNA 2021)
// URL: https://codeforces.com/gym/104196/problem/M
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 50*50 + 10;

int numNode;
int child[NMAX][128];
int childChars[NMAX][128], sz[NMAX];
int fail[NMAX], nxt[NMAX];
int patId[NMAX];

int addNode(){
	memset(child[numNode], -1, sizeof child[numNode]);
	patId[numNode] = -1;
	sz[numNode] = 0;
	return numNode++;
}

void init(){
	numNode = 0;
	addNode();
}

int insert(const string &pat, int id){
	
	int cur = 0 ;
	for(auto c : pat){
		
		int &nd = child[cur][c];
			
		if(nd==-1){
			nd = addNode();
			childChars[cur][sz[cur]++] = c;
		}
		
		cur = nd;
	}
	return patId[cur]!=-1 ? patId[cur] : (patId[cur] = id);
}

int nxtF(int u, char c){
	
	while(child[u][c]==-1){
		u = fail[u];
	}	
	
	return child[u][c];
}

int get_nxt(int u){
	if(!u) return u;
	int v = nxt[u];
	return nxt[u] = patId[v]!=-1 ? v : get_nxt(v);
}

void computeFail(){
	
	queue<int> que;
	
	for(int i = 0; i < 128; i++){
		int &u = child[0][i];
		if(u != -1){
			nxt[u] = fail[u] = 0;
			que.push(u);
		}
		else{
			u = 0;
		}
	}
	
	while(!que.empty()){
		
		int u = que.front();
		que.pop();
		
		for(int i = 0; i < sz[u]; i++){
			char c = childChars[u][i];
			int v = child[u][c];
			nxt[v] = fail[v] = nxtF(fail[u], c);
			que.push(v);		
		}
	}
}

int n, m;
char grid[55][55];
int mem[55][55][3][55*55];

int go(int i, int j, int dir, int id){
	
	// cout << i << ' ' << j << ' ' << dir << ' ' << id << endl;
	
	if(i==n){
		return patId[id]!=-1 ? 0 : INF;
	}
	
	int &ret = mem[i][j][dir+1][id];
	if(ret+1) return ret;
	
	int ans = INF;
	
	if(patId[id] != -1){
		int cans = go(i, j, dir, 0);
		ans = min(ans, cans);
	}
	
	int nid = child[id][grid[i][j]];
	
	if(nid != -1 && nid != 0){
		
		if((dir != 0) && (j > 0)){
			int cans = 1 + go(i, j-1, 1, nid);
			ans = min(ans, cans);
		}
		
		if((dir != 1) && (j+1 < m)){
			int cans = 1 + go(i, j+1, 0, nid);
			ans = min(ans, cans);
		}
		
		{
			int cans = 1 + go(i+1, j, -1, nid);
			ans = min(ans, cans);
		}
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int k;
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		cin >> grid[i][j];
	}
	
	init();
	
	for(int i = 0; i < k; i++){
		string str;
		cin >> str;
		insert(str, i);
	}
	
	computeFail();
	
	// for(int i = 0; i < numNode; i++){
		// cout << i << ' ' << patId[i] << endl;
	// }
	
	// for(int i = 'A'; i <= 'Z'; i++){
		// cout << child[0][i] << ' ';
	// }
	// cout << endl;
	
	int ans = INF;
	
	memset(mem, -1, sizeof mem);
	
	for(int i = 0; i < m; i++){
		ans = min(ans, go(0, i, -1, 0));
	}
	
	if(ans<INF){
		cout << ans << endl;
	}
	else{
		cout << "impossible" << endl;
	}
}
