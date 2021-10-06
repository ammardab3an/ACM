// Problem: B. A Lot of Games
// Contest: Codeforces - Codeforces Round #260 (Div. 1)
// URL: https://codeforces.com/contest/455/problem/B
// Memory Limit: 256 MB
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

struct node{
	
	bool val;
	int nxt[26];
	
	node(){
		val = 0;
		memset(nxt, 0, sizeof nxt);	
	}
	
};

int ID = 1;
const int ID_MAX = 2e5 + 10;
node nds[ID_MAX];

void trie_add(string &str, int id){
	
	for(auto _c : str){
		
		int c = _c-'a';
		
		if(!nds[id].nxt[c]){
			nds[id].nxt[c] = ID++;
		}	
		
		id = nds[id].nxt[c];
	}	
	
	nds[id].val = true;
}

string dfs_tmp;
void dfs(int id){
	
	if(nds[id].val){
		cout << dfs_tmp << endl;
	}
	
	for(int i = 0; i < 26; i++){
		if(nds[id].nxt[i]){
			dfs_tmp.push_back('a'+i);
			dfs(nds[id].nxt[i]);
			dfs_tmp.pop_back();
		}
	}
}

int go_win(int id){
	
	for(int i = 0; i < 26; i++){
		if(nds[id].nxt[i]){
			if(!go_win(nds[id].nxt[i])){
				return true;
			}
		}
	}
	
	return false;
}

int go_loose(int id){
	
	bool found = false;
	
	for(int i = 0; i < 26; i++){
		if(nds[id].nxt[i]){
			found = true;
			if(!go_loose(nds[id].nxt[i])){
				return true;
			}
		}
	}
	
	return found ? false : true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    int root = 0;
    nds[root] = node();
    
    for(int i = 0; i < n; i++){
    	string str;
    	cin >> str;
    	trie_add(str, root);
    }
    
    // dfs(root);
    
    bool can_win = go_win(root);
    bool can_loose = go_loose(root);
    
    // cout << can_win << ' ' << can_loose << endl;
    
    if(can_win && !can_loose){
    	cout << (k%2==1 ? "First" : "Second") << endl;
    }
    else if(!can_win && can_loose){
    	cout << "Second" << endl;
    }
    else if(!can_win && !can_loose){
    	cout << "Second" << endl;
    }
    else{
    	cout << "First" << endl;
    }
}