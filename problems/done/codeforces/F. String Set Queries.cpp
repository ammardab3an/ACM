// Problem: F. String Set Queries
// Contest: Codeforces - Educational Codeforces Round 16
// URL: https://codeforces.com/contest/710/problem/F
// Memory Limit: 768 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

// #define endl '\n'
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

struct aho{
	
	int numNode, tot_size;
	vector<array<int, 128>> child;
	vector<array<int, 128>> childChars;
	vi sz, fail, nxt, patId;
	vector<string> tmp_pats;
	
	aho(){
		init();	
	}
	
	aho(const vector<string> &pats){
		init();
		for(auto s : pats) insert(s);
		computeFail();
	}
	
	int size(){
		return tot_size;
	}
	
	int addNode(){
		
		child.push_back(array<int, 128>());
		childChars.push_back(array<int, 128>());
		sz.push_back(0);
		fail.push_back(0);
		nxt.push_back(0);
		patId.push_back(0);
		
		fill(child[numNode].begin(), child[numNode].end(), -1);
		patId[numNode] = -1;
		sz[numNode] = 0;
		
		return numNode++;
	}
	
	void init(){
		numNode = 0;
		addNode();
	}
	
	int insert(const string &pat, int id=0){
		
		tot_size += pat.size();
		tmp_pats.push_back(pat);
		
		int cur = 0 ;
		for(auto c : pat){
			
			int nd = child[cur][c];
			
			if(nd==-1){
				nd = child[cur][c] = addNode();
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
	
	int query(const string &str, bool debug=false){
		
		int nd = 0;
		int ret = 0;
		
		for(auto c : str){
			
			nd = nxtF(nd, c);
			
			for(int p = nd; p; p = get_nxt(p)){
				if(patId[p] != -1){
					ret++;
				}
			}
		}
		
		return ret;
	}
};

vector<aho> ahos;
vector<int> aho_vec[2][33];

void fix(bool b){
	
	for(int i = 0; i < 30; i++){
		if(aho_vec[b][i].size() > 1){
			
			assert(aho_vec[b][i].size()==2);
			
			int id0 = aho_vec[b][i][0];
			int id1 = aho_vec[b][i][1];
			
			int id = ahos.size();
			ahos.push_back(aho());
			for(auto s : ahos[id0].tmp_pats) ahos[id].insert(s);
			for(auto s : ahos[id1].tmp_pats) ahos[id].insert(s);
			ahos[id].computeFail();
			
			ahos[id0] = aho();
			ahos[id1] = aho();
			
			aho_vec[b][i].clear();
			aho_vec[b][i+1].push_back(id);
		}
	}
}

void insert(const string &s, bool b){
	int id = ahos.size();
	ahos.push_back(aho(vector<string>(1, s)));
	aho_vec[b][0].push_back(id);
	fix(b);
}

int query(const string &s){
	int ret = 0;
	for(int i = 0; i < 30; i++){
		
		for(auto id : aho_vec[0][i]){
			ret += ahos[id].query(s, true);
		}
		for(auto id : aho_vec[1][i]){
			ret -= ahos[id].query(s);
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
    
    int q; cin >> q; while(q--){
    	
    	int k;
    	cin >> k;
    	
    	string str;
    	cin >> str;
    	
    	if(k==1){
    		insert(str, 0);
    	}	
    	else if(k==2){
    		insert(str, 1);
    	}
    	else{
    		int ans = query(str);
    		cout << ans << endl;
    	}
    }
}
