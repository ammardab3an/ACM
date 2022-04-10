// TLE

// Problem: E. MinimizOR
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/E
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct query{
    
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
    
};

struct node{
	
	int cnt;
	node *nxt[2];
	
	node(){
		cnt = 0;
		nxt[0] = nxt[1] = nullptr;
	}
	
	void clear(){
		if(nxt[0]) nxt[0]->clear();
		if(nxt[1]) nxt[1]->clear();
		if(nxt[0]) delete nxt[0];
		if(nxt[1]) delete nxt[1];
		nxt[0] = nxt[1] = nullptr;
	}	
};

int n;
int vec[NMAX];

struct trie{
	
	node *root;
	
	trie(){
		root = new node();
	}
	
	~trie(){
		root->clear();
		delete root;
	}
	
	void update(int val, int c){
		
		node *cur = root;
		
		for(int i = 30; i >= 0; i--){
			
			int b = (val>>i)&1;
			if(!cur->nxt[b]) cur->nxt[b] = new node();
			
			cur->nxt[b]->cnt += c;
			cur = cur->nxt[b];
		}	
	}
	
	int go(node *a, node *b, int i, int val){
		
		if(i==-1){
			return val;
		}
		
		if(a==b){
			if(a->nxt[0] && a->nxt[0]->cnt){
				if(a->nxt[0]->cnt >= 2){
					return go(a->nxt[0], b->nxt[0], i-1, val);
				}	
				else{
					if(a->nxt[1]->cnt >= 2){
						int st_path = go(a->nxt[0], b->nxt[1], i-1, val^(1<<i));
						int nd_path = go(a->nxt[1], b->nxt[1], i-1, val^(1<<i));
						return min(st_path, nd_path);
					}
					else{
						return go(a->nxt[0], b->nxt[1], i-1, val^(1<<i));
					}
				}
			}
			else{
				return go(a->nxt[1], b->nxt[1], i-1, val^(1<<i));
			}
		}
		else{
			if(a->nxt[0] && b->nxt[0] && a->nxt[0]->cnt && b->nxt[0]->cnt){
				return go(a->nxt[0], b->nxt[0], i-1, val);
			}
			else if(!(a->nxt[0] && a->nxt[0]->cnt) && !(b->nxt[0] && b->nxt[0]->cnt)){
				return go(a->nxt[1], b->nxt[1], i-1, val^(1<<i));
			}
			else if(a->nxt[0] && a->nxt[1] && a->nxt[0]->cnt && a->nxt[1]->cnt && b->nxt[1] && b->nxt[1]->cnt){
				int st_path = go(a->nxt[0], b->nxt[1], i-1, val^(1<<i));
				int nd_path = go(a->nxt[1], b->nxt[1], i-1, val^(1<<i));
				return min(st_path, nd_path);
			}
			else if(b->nxt[0] && b->nxt[1] && b->nxt[0]->cnt && b->nxt[1]->cnt && a->nxt[1] && a->nxt[1]->cnt){
				int st_path = go(a->nxt[1], b->nxt[0], i-1, val^(1<<i));
				int nd_path = go(a->nxt[1], b->nxt[1], i-1, val^(1<<i));
				return min(st_path, nd_path);
			}
			else if(a->nxt[1] && a->nxt[1]->cnt){
				return go(a->nxt[1], b->nxt[0], i-1, val^(1<<i));
			}
			else{
				return go(a->nxt[0], b->nxt[1], i-1, val^(1<<i));
			}
		}
	}
	
	int get_ans(){
		return go(root, root, 30, 0);
	}
	
	void add(int i){
		// cout << vec[i] << endl;
		update(vec[i], 1);
	}	
	void rem(int i){
		update(vec[i], -1);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> vec[i];
		}
		
		int q;
		cin >> q;
		
		vector<query> queries(q);
		
		for(int i = 0; i < q; i++){
		
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			queries[i].lo = l;
			queries[i].hi = r;
			queries[i].idx = i;
		}
		
        sort(queries.begin(), queries.end());

		vi ans(q);
		
		trie tree;
		
        int l = 1, r = 0;
        for(int i = 0; i < q; i++){

            int cl = queries[i].lo;
            int cr = queries[i].hi;
            int ci = queries[i].idx;

            while(r < cr) tree.add(++r);
            while(cl < l) tree.add(--l);
            while(cr < r) tree.rem(r--);
            while(l < cl) tree.rem(l++);

            ans[ci] = tree.get_ans();
        }
        
        for(int i = 0; i < q; i++){
        	cout << ans[i] << endl;
        }
    }	
}
