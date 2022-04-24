// Problem: S - I Love Strings!!
// Contest: Virtual Judge - String Processing - Week 1 (CA GYM - Problems Week 6)
// URL: https://vjudge.net/contest/488773#problem/S
// Memory Limit: 1024 MB
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
 
const int NMAX = 1e6 + 10;

int numNode, numPat;
int child[NMAX][26];
int patId[NMAX];
int nxt[NMAX], fail[NMAX];
int id_to_pat[NMAX];

int addNode(){
	memset(child[numNode], -1, sizeof child[numNode]);
	patId[numNode] = -1;
	return numNode++;	
}

void init(){
	numNode = 0;
	addNode();
}

int insert(const string &pat, int id){
	
	int cur = 0;
	for(auto c : pat){
		int &nd = child[cur][c-'a'];
		if(nd==-1) nd = addNode();
		cur = nd;
	}	
	
	if(patId[cur] != -1){
		return patId[cur];
	}
	else{
		return patId[cur] = id;
	}
}

int nxtF(int f, char c){
	
	while(child[f][c-'a']==-1){
		f = fail[f];
	}
	
	return child[f][c-'a'];
}

int get_nxt(int u){
	if(!u) return u;
	int v = nxt[u];
	return nxt[u] = patId[v]!=-1 ? v : get_nxt(v);
}

void computeFail(){
	
	queue<int> que;
	
	fail[0] = 0;
	
	for(int i = 0; i < 26; i++){
		
		int u = child[0][i];
		
		if(u != -1){
			fail[u] = nxt[u] = 0;
			que.push(u);
		}
		else{
			child[0][i] = 0;
		}
	}
	
	while(!que.empty()){
		
		int u = que.front();
		que.pop();
		
		for(int i = 0; i < 26; i++) if(child[u][i] != -1){
			int v = child[u][i];
			fail[v] = nxt[v] = nxtF(fail[u], i+'a');
			que.push(v);
		}
	}
}

void printTrie(){
	
	for(int i = 0; i < numNode; i++){
		for(int j = 0; j < 26; j++) if(child[i][j]!=-1){
			cout << i << "," << patId[i] << ' ' << child[i][j] << "," << patId[child[i][j]] << ' ' << char(j+'a') << endl;
		}
	}	
}

vector<bool> match(const string &str){
	
	vector<bool> ret(numPat);	
	
	int cur = 0;
	for(auto c : str){
		
		cur = nxtF(cur, c);
		
		for(int p = cur; p; p = get_nxt(p)){
			
			int x = patId[p];
			if(x!=-1) ret[x] = true;
		}
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		init();
		
		string str;
		cin >> str;
		
		int m;
		cin >> m;
		
		vi names(m);
		
		for(int i = 0; i < m; i++){
			string pat;
			cin >> pat;
			int id = insert(pat, i);
			names[i] = id;
		}
		
		// printTrie();
		
		computeFail();
		
		numPat = m;
		vector<bool> res = match(str);
		
		for(int i = 0; i < m; i++){
			cout << "ny"[res[names[i]]] << endl;
		}
    }	
}
