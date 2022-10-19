// Problem: F. Keyboard Design
// Contest: Codeforces - Educational Codeforces Round 136 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1739/problem/F
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 20000 + 10;

int numNode;
int child[NMAX][128];
int childChars[NMAX][128], sz[NMAX];
int fail[NMAX], nxt[NMAX];
int patVal[NMAX]; //

int mem[NMAX][1<<12];

int addNode(){
	memset(child[numNode], -1, sizeof child[numNode]);
	patVal[numNode] = 0; // 
	sz[numNode] = 0;
	return numNode++;
}

void init(){
	numNode = 0;
	addNode();
}

void insert(const string &pat, int val){ // void ,val
	
	int cur = 0 ;
	for(auto c : pat){
		
		int &nd = child[cur][c];
		
		if(nd==-1){
			nd = addNode();
			childChars[cur][sz[cur]++] = c;
		}
		
		cur = nd;
	}
	
	patVal[cur] += val;
}

int nxtF(int u, char c){
	
	while(child[u][c]==-1){
		u = fail[u];
	}	
	
	return child[u][c];
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
			fail[v] = nxtF(fail[u], c); //
			patVal[v] += patVal[fail[v]]; // 
			que.push(v);		
		}
	}
}

int go(int id, int msk){
	
	if(!msk){
		return patVal[id];
	}
	
	int &ret = mem[id][msk];
	if(ret+1) return ret;
	
	int ans = 0;
	
	for(int i = 0; i < 12; i++) if((msk>>i)&1){
		int cans = patVal[id] + go(nxtF(id, 'a'+i), msk^(1<<i));
		ans = max(ans, cans);
	}	
	
	return ret = ans;
}

string calc_str;
void calc(int id, int msk){
	
	if(!msk){
		cout << calc_str << endl;
		return;
	}
	
	int ans = go(id, msk);
	
	for(int i = 0; i < 12; i++) if((msk>>i)&1){
		int cans = patVal[id] + go(nxtF(id, 'a'+i), msk^(1<<i));
		if(ans==cans){
			calc_str.push_back('a'+i);
			calc(nxtF(id, 'a'+i), msk^(1<<i));
			return;
		}
	}
	
	assert(false);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    init();
    
    for(int i = 0; i < n; i++){
    	
    	int ci;
    	cin >> ci;
    	
    	string pat;
    	cin >> pat;
    	
    	if(pat.size()==3 && pat.front()==pat.back()){
    		pat.pop_back();
    	}
    	
    	if(pat.size()==2){
    		insert(pat, ci);
    		reverse(pat.begin(), pat.end());
    		insert(pat, ci);
    	}
    	else{
    		
	    	vector<vi> tmp(12);
    		bool vis[12][12] = {0};
	    	
	    	int cnt = 0;
	    	for(int i = 0; i+1 < pat.size(); i++){
	    		
	    		int u = pat[i]-'a';
	    		int v = pat[i+1]-'a';
	    		
	    		if(!vis[u][v]){
	    			cnt++;
	    			vis[u][v] = true;
	    			vis[v][u] = true;
	    			tmp[u].push_back(v);
	    			tmp[v].push_back(u);
	    		}
	    	}
	    	
	    	bool bad = false;
	    	
	    	int c = -1;
	    	for(int i = 0; i < 12; i++){
	    		if(tmp[i].size()){
	    			if(tmp[i].size()==1){    				
		    			c = i;
	    			}
		    		if(tmp[i].size() > 2){
		    			bad = true;
		    			break;
		    		}
	    		}
	    	}
	    	
	    	if(bad || c==-1){
	    		continue;
	    	}
	    	
	    	string str;
	    	str.push_back('a'+c);
	    	vi used(12);
	    	
	    	while(!tmp[c].empty()){

	    		cnt--;
	    		int cc = tmp[c].back();
	    		tmp[c].pop_back();
	    		tmp[cc].erase(find(tmp[cc].begin(), tmp[cc].end(), c));
	    		
	    		if(used[cc]){
	    			bad = true;
	    			break;
	    		}
	    		
	    		used[cc] = true;
	    		str.push_back('a'+cc);
	    		c = cc;
	    	}
	    	
	    	if(bad || cnt){
	    		continue;
	    	}
	    	
	    	insert(str, ci);
	    	reverse(str.begin(), str.end());
	    	insert(str, ci);
    	}
    }
    
    computeFail();
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0, (1<<12)-1);
    calc(0, (1<<12)-1);
    
    // cout << ans << endl;
}
 