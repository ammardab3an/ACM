// Problem: R - Password Suspects
// Contest: Virtual Judge - String Processing - Week 1 (CA GYM - Problems Week 6)
// URL: https://vjudge.net/contest/488773#problem/R
// Memory Limit: 1024 MB
// Time Limit: 9000 ms
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
int numNode;
int child[NMAX][26];
int nxt[NMAX], fail[NMAX];
int patId[NMAX];
int mem[33][111][1 << 11];

int newNode(){
	memset(child[numNode], -1, sizeof child[numNode]);
	patId[numNode] = -1;	
	return numNode++;
}

void init(){
	numNode = 0;
	newNode();	
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

int insert(const string &pat, int id){
	
	int cur = 0;
	for(auto c : pat){
		int &u = child[cur][c-'a'];
		if(u==-1) u = newNode();
		cur = u;
	}	
	
	if(patId[cur]!=-1){
		return patId[cur];
	}
	else{
		return patId[cur] = id;
	}
}

void computeFail(){
	
	queue<int> que;
	
	for(int i = 0; i < 26; i++){
		int &nd = child[0][i];
		if(nd!=-1){
			nxt[nd] = fail[nd] = 0;
			que.push(nd);
		}
		else{
			nd = 0;
		}
	}	
	
	while(!que.empty()){
		
		int u = que.front();
		que.pop();
		
		for(int i = 0; i < 26; i++) if(child[u][i] != -1){
			int v = child[u][i];
			nxt[v] = fail[v] = nxtF(fail[u], i+'a');
			que.push(v);
		}
	}
}

int mmsk;

int go(int rm, int id, int msk){
	
	if(rm==0){
		return msk == mmsk;
	}	
	
	int &ret = mem[rm][id][msk];
	if(ret+1) return ret;
	
	int ans = 0;
	
	for(int i = 0; i < 26; i++){
		
		int nid = nxtF(id, i+'a');
		int nmsk = msk;
		
		for(int p = nid; p; p = get_nxt(p)){
			
			if(patId[p] != -1){			
				nmsk |= 1 << patId[p];
			}
		}
		
		ans += go(rm-1, nid, nmsk);
	}
	
	return ret = ans;
}

string calc_tmp;

void calc(int rm, int id, int msk){
	
	if(!go(rm, id, msk)){
		return;
	}
	
	if(rm==0){
		cout << calc_tmp << endl;
		return;
	}	
	
	for(int i = 0; i < 26; i++){
		
		int nid = nxtF(id, i+'a');
		int nmsk = msk;
		
		for(int p = nid; p; p = get_nxt(p)){
			if(patId[p] != -1){			
				nmsk |= 1 << patId[p];
			}
		}
		
		calc_tmp.push_back(i+'a');
		calc(rm-1, nid, nmsk);
		calc_tmp.pop_back();
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int tt = 1;
    while(cin >> n >> m, n){
    	
    	cout << "Case " << tt++ << ": ";
    	
    	init();
    	
	    vi names(m);
	    
	    for(int i = 0; i < m; i++){
	    	string pat;
	    	cin >> pat;
	    	int id = insert(pat, i);
	    	names[i] = id;
	    }
	    
	    mmsk = 0;
	    for(int i = 0; i < m; i++){
	    	mmsk |= 1 << names[i];
	    }
	    
	    computeFail();
	    
	    // printTrie();
	    
	    memset(mem, -1, sizeof mem);
	    
	    int ans = go(n, 0, 0);
	    cout << ans << " suspects" << endl;
	    
	    if(ans <= 42){
		    calc(n, 0, 0);
	    }
    }
}
