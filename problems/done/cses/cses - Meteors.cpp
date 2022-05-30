// Problem: Meteors
// Contest: CSES - IOI-leiri 2017
// URL: https://cses.fi/ioi17/task/945
// Memory Limit: 128 MB
// Time Limit: 3000 ms
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

struct FenwickTree {

    int n;
    vector<int> bit;  // binary indexed tree

	FenwickTree(){}

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    void update(int l, int r, int x){
        update(r, x);
        if(l-1 >= 0) update(l-1, -x);
    }

    void update(int r, int x) {
        for (; r >= 0; r = (r & (r + 1)) - 1)
            bit[r] += x;
    }

    int query(int idx) {
        int ret = 0;
        for (; idx < n; idx = idx | (idx + 1))
            ret += bit[idx];
        return ret;
    }
};

const int NMAX = 3e5 + 10;

int n, m;
int val[NMAX];
int queries[NMAX][3];
vi tmp[NMAX];
int ans[NMAX];
FenwickTree tree;

void init_bit(){
    tree = FenwickTree(n);
}

void update_query(int l, int r, int x){

    if(l <= r){
        tree.update(l, r, x);
    }
    else{
        tree.update(l, n-1, x);
        tree.update(0, r, x);
    }
}

int query_pos(int p){
    return tree.query(p);
}

int32_t main(){

    fastIO;
    // #undef endl

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

	cin >> m >> n;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        c--;
        tmp[c].push_back(i);
    }

    for(int i = 0; i < m; i++){
        cin >> val[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--, r--;
    	queries[i][0] = l;
    	queries[i][1] = r;
    	queries[i][2] = x;
    }

    queue<pair<pii, vi>> que;
    que.push({{0, q}, vi(m)});
    iota(que.front().second.begin(), que.front().second.end(), 0);

    int cur = INF;

    while(!que.empty()){

    	auto fr = que.front();
    	que.pop();

    	int l = fr.first.first;
    	int r = fr.first.second;
    	auto &v = fr.second;

    	// cout << l << ' ' << r << ' ' << (l+r)/2 << endl;
    	// for(auto i : v) cout << i << ' '; cout << endl;

    	if(l==r){
    		for(auto i : v) ans[i] = l;
    		continue;
    	}

    	int mid = (l+r)/2;

    	if(cur <= mid){
    		for(int i = cur+1; i <= mid; i++){
    			update_query(queries[i][0], queries[i][1], queries[i][2]);
    		}
    	}
    	else{
            init_bit();
    		for(int i = 0; i <= mid; i++){
    			update_query(queries[i][0], queries[i][1], queries[i][2]);
    		}
    	}

    	cur = mid;

		vi lf, ri;
    	for(auto i : v){

    		int tot = 0;
    		for(auto p : tmp[i]){
    			tot += query_pos(p);
    			if(tot > val[i]) break;
    		}

    		if(val[i] <= tot){
    			lf.push_back(i);
    		}
    		else{
    			ri.push_back(i);
    		}
    	}

    	if(!lf.empty()) que.push({{l, mid}, lf});
    	if(!ri.empty()) que.push({{mid+1, r}, ri});
    }

	for(int i = 0; i < m; i++){

		if(ans[i] < q){
			cout << ans[i]+1 << endl;
		}
		else{
			cout << "NIE" << endl;
		}
    }
}
