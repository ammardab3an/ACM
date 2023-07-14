// Problem: D. Destiny
// Contest: Codeforces - Codeforces Round #429 (Div. 1)
// URL: https://codeforces.com/contest/840/problem/D
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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
// const ll INFLL = 0x3f3f3f3f3f3f3f3f;
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

const int NMAX = 3e5 + 10;
const int MMAX = 3e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{

	node* nxt[2];
	bool is_leaf;
	int leaf_val;
	int frq;
	
	node(){
		nxt[0]=nxt[1] = 0;
		is_leaf = false;
		leaf_val = 0;
		frq = 0;
	}

	node(int val, int f=1) : node(){
		is_leaf = true;
		leaf_val = val;
		frq = f;
	}
	
	~node(){
	    delete nxt[0];
		delete nxt[1];
	}
	
	void insert(int lvl, int val){
		
		frq++;
		
		if(is_leaf && leaf_val==val){
			return;
		}
		
		if(is_leaf){	
			bool lb = (leaf_val>>lvl)&1;
			nxt[lb] = new node(leaf_val, frq-1);
			is_leaf = false, leaf_val = 0;
		}
		
		bool b = (val>>lvl)&1;
		
		if(!nxt[b]){
			nxt[b] = new node(val);
		}
		else{
			nxt[b]->insert(lvl-1, val);
		}
	}
	
	void erase(int lvl, int val){
		
		frq--;
		
		if(is_leaf){
			assert(leaf_val==val);
			return;
		}
		
		bool b = (val>>lvl)&1;
		nxt[b]->erase(lvl-1, val);
		
		if(nxt[b]->frq==0){
			delete(nxt[b]);
			nxt[b] = nullptr;
		}
	}
	
	void print(){
		
		if(is_leaf){
			cout << " - " << leaf_val << ' ' << frq << endl;
		}
		else{
			if(nxt[0]){
				nxt[0]->print();
			}
			if(nxt[1]){
				nxt[1]->print();
			}
		}
	}
};

struct ds{

	node root;
	int size = 0;
	
	void insert(int x){
		// cout << this << ' ' << "insert " << x << endl << flush;
		size++;
		root.insert(30, x);
		assert(root.frq==size);
	}

	void erase(int x){
		// cout << this << ' ' << "erase " << x << endl << flush;
		size--;
		root.erase(30, x);
		assert(root.frq==size);
	}
	
	int query(int x){
		
		// cout << this << ' ' << "query" << endl << flush;
		// root.print();
		// cout << flush;
		
		if(size==0) return INF;
		
		node *cur = &root;

		for(int i = 30; i >= 0; i--){

			if(cur->is_leaf){
				break;
			}
			
			bool b = (x>>i)&1;
			
			if(cur->nxt[!b]){
				cur = cur->nxt[!b];
			}
			else{
				cur = cur->nxt[b];
			}
		}

		assert(cur);
		return x^(cur->leaf_val);
	}
	
	int min(){
		return query(unsigned(-1)) ^ unsigned(-1);
	}
};

struct query{
    int lo, hi, k, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];

int n;
int arr[NMAX];
int ans[MMAX];
int frq[NMAX];
ds tmp[NMAX];
ds mn_block[NMAX/BLOCK+1];

void add(int idx){
	
	int val = arr[idx];
	tmp[frq[val]].erase(val);
	tmp[++frq[val]].insert(val);
	
	int f = frq[val];
	
	if(f%BLOCK==0){
		mn_block[(f-1)/BLOCK].erase(val);
		mn_block[f/BLOCK].insert(val);
	}
}

void rem(int idx){
	
	int val = arr[idx];
	tmp[frq[val]].erase(val);
	tmp[--frq[val]].insert(val);
	
	int f = frq[val];
	if((f+1)%BLOCK==0){
		mn_block[(f+1)/BLOCK].erase(val);
		mn_block[f/BLOCK].insert(val);
	}
}

int get_ans(int _l, int _r, int k){
	
	int ret = INF;
	
	int l = (_r-_l+1+k-1)/k + ((_r-_l+1)%k==0);
	int r = n;
	
	// cout << _l << ' ' << _r << ' ' << k << endl;
	
	int i;
	for(i = l; (i <= r) && (i/BLOCK==l/BLOCK); i++){
		// cout << ' ' << i << endl;
		ret = min(ret, tmp[i].min());
	}
	
	for(i = l/BLOCK+1; i < r/BLOCK; i++){
		ret = min(ret, mn_block[i].min());
	}
	
	for(i = i*BLOCK; i <= r; i++){
		ret = min(ret, tmp[i].min());
	}
	
	if(ret==INF) ret = -1;
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    {
	    set<int> st(arr, arr+n);
	    for(auto i : st){
	    	tmp[0].insert(i);
	    	mn_block[0].insert(i);
	    }
    }
    
    for(int i = 0; i < m; i++) {
        cin >> q[i].lo >> q[i].hi >> q[i].k;
        q[i].lo--, q[i].hi--, q[i].idx = i;
    }

    sort(q, q+m);

    int l = 1, r = 0;

    for(int i = 0; i < m; i++){

        int cl = q[i].lo;
        int cr = q[i].hi;
        int ci = q[i].idx;
		int ck = q[i].k;
		
        while(r < cr) add(++r);
        while(cl < l) add(--l);
        while(cr < r) rem(r--);
        while(l < cl) rem(l++);

        ans[ci] = get_ans(cl, cr, ck);
    }

	for(int i = 0; i < m; i++){
		cout << ans[i] << endl;
	}
}
