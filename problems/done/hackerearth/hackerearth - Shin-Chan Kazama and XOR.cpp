// Problem: Shin-Chan Kazama and XOR
// Contest: HackerEarth - Data Structures - Advanced Data Structures - Trie (Keyword Tree)
// URL: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/shin-chan-kazama-and-xor-2/
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int NMAX = 1e6 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{

	vi vec;
	node *nxt[2];
	
	~node(){
		if(nxt[0]) delete nxt[0];
		if(nxt[1]) delete nxt[1];	
		nxt[0] = nxt[1] = nullptr;
	}
	
	node(){
		nxt[0] = nxt[1] = nullptr;
	}
};

struct TrieXOR{

	node root;

	void insert(int val, int idx){

		node *cur = &root;

		for(int i = 30; i >= 0; i--){

			bool b = (val>>i)&1;

			if(!cur->nxt[b]){
				cur->nxt[b] = new node();
			}

			cur = cur->nxt[b];
			
			if(i!=0) cur->vec.clear();
			cur->vec.push_back(idx);
		}
	}

	pii query(int val, int idx){

		int ret = 0;
		int cnt = 0;
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){

			bool b = (val>>i)&1;

			if((cur->nxt[b]) && (cur->nxt[b]->vec.back()>=idx)){
				cur = cur->nxt[b];
			}
			else{
				ret ^= (1 << i);
				cur = cur->nxt[!b];
			}
			
			if(i == 0){
				auto &v = cur->vec;
				cnt = v.end() - lower_bound(v.begin(), v.end(), idx);
			}
		}

		return {ret, cnt};
	}

};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    // freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    int q;
    cin >> q;
    
    vpii ans(q);
    vector<vector<iii>> queries(n);
    
    for(int i = 0; i < q; i++){
    	
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--, r--;
    	
    	queries[r].push_back({x, {l, i}});
    }
    
    TrieXOR tree;
    
    for(int i = 0; i < n; i++){
    	
    	tree.insert(vec[i], i);
    
    	for(auto p : queries[i]){
    		
    		int x = p.first;
    		int l = p.second.first;
    		int q_idx = p.second.second;
    		
    		ans[q_idx] = tree.query(x, l);
    		ans[q_idx].first ^= x;
    	}	
    }
    
    for(int i = 0; i < q; i++){
    	cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}
