// Problem: T - Substring
// Contest: Virtual Judge - String Processing - Week 1 (CA GYM - Problems Week 6)
// URL: https://vjudge.net/contest/488773#problem/T
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

int numNode;
int child[NMAX][128];
int childChars[NMAX][128], sz[NMAX];
int fail[NMAX], nxt[NMAX];
int patId[NMAX];

int n;
char ch[128];
double pro[128];

double mem[111][444];
int vis[111][444], vid;

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

double go(int rm, int id){
	
	for(int p = id; p; p = get_nxt(p)){
		if(patId[p]!=-1){
			return 0;
		}
	}
	
	if(rm==0){
		return 1;
	}	
	
	if(vis[rm][id]==vid){
		return mem[rm][id];
	}
	else{
		vis[rm][id] = vid;
	}
	
	double ans = 0;
	
	for(int i = 0; i < n; i++){
		
		char c = ch[i];
		double p = pro[i];
		
		ans += p * go(rm-1, nxtF(id, c));
	}
	
	return mem[rm][id] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int tt = 1;
    int t; cin >> t; while(t--){

		int m;
		cin >> m;
		
		init();
		
		vi names(m);
		
		for(int i = 0; i < m; i++){
			string pat;
			cin >> pat;
			names[i] = insert(pat, i);
		}
		
		computeFail();
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> ch[i] >> pro[i];
		}
		
		int l;
		cin >> l;
		
		vid++;
		
		double ans = go(l, 0);
		cout << "Case #" << tt++ << ": ";
		cout << fixed << setprecision(6) << ans << endl;
    }	
}
