// Problem: Transaction
// Contest: HackerEarth - Data Structures - Advanced Data Structures - Segment Trees
// URL: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/transaction-f9f70f83/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n, q;
int arr[NMAX];
int pos[NMAX];
int ans[NMAX];
int tree[NMAX << 2];

struct query_struct{
	
	int val, idx, q_idx;
	
	bool operator < (const query_struct &other){
		return val < other.val;
	}
	
} que[NMAX];

void update(int nd, int l, int r, int p){
	
	if(p < l || r < p){
		return;
	}
	
	tree[nd] += 1;
	
	if(l==r){
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p);
	update(nd*2+1, mid+1, r, p);
}

int query(int nd, int l, int r, int p){
	
	if(l==r){
		return l;
	}	
	
	int mid = (l+r)/2;
	
	if(p < tree[nd*2]){
		return query(nd*2, l, mid, p);
	}
	else{
		return query(nd*2+1, mid+1, r, p-tree[nd*2]);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    iota(pos, pos+n, 0);
    sort(pos, pos+n, [&](int i, int j){
    	return arr[i] < arr[j];
    });
    
    for(int i = 0; i < q; i++){
    	cin >> que[i].val >> que[i].idx;
    	que[i].q_idx = i;
    }
    
    sort(que, que+q);
    
    int j = n-1;
    for(int i = q-1; i >= 0; i--){
    	
    	while(j >= 0 && arr[pos[j]] >= que[i].val){
    		update(1, 0, n-1, pos[j]);
    		j--;
    	}
    	
    	if(que[i].idx > tree[1]){
    		ans[que[i].q_idx] = -1;
    		continue;
    	}
    	
    	int cans = query(1, 0, n-1, que[i].idx-1);
    	ans[que[i].q_idx] = arr[cans];
    }
    
    for(int i = 0; i < q; i++){
    	cout << ans[i] << endl;
    }
}
