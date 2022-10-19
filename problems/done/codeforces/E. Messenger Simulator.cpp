// Contest: Codeforces - Educational Codeforces Round 80 (Rated for Div. 2)
// Problem: E. Messenger Simulator
// URL: https://codeforces.com/contest/1288/problem/E
// Memory Limit: 256 MB
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
 
const int NMAX = 3e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
};

struct FenwickTree {

    int n;
    vector<int> bit;  // binary indexed tree

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n, m, q_sz;
int arr[NMAX];
query q[NMAX];
int frq[NMAX];
int mn[NMAX];
int mx[NMAX];
int lst[NMAX];
FenwickTree pre(NMAX);
int ans;

void add(int idx, bool b=false){
	frq[arr[idx]]++;
	if(frq[arr[idx]]==1){
		ans++;
		if(b) pre.add(arr[idx], +1);
	}
}

void rem(int idx, bool b=false){
	frq[arr[idx]]--;
	if(frq[arr[idx]]==0){
		ans--;
		if(b) pre.add(arr[idx], -1);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	cin >> arr[i];
    	arr[i]--;
    }
	
	for(int i = 0; i < n; i++){
		mn[i] = i;
		mx[i] = i;
		lst[i] = -1;
	}   
	
	{
		for(int i = 0; i < m; i++){
			mn[arr[i]] = 0;
			if(frq[arr[i]]==0){
				mx[arr[i]] = arr[i]+pre.sum(arr[i], n-1);
			}
			add(i, true);
		}
		for(int i = 0; i < n; i++){
			if(frq[i]==0){
				mx[i] = i + pre.sum(i, n-1);
			}
		}
		for(int i = 0; i < m; i++){
			rem(i, true);
		}
	}
	
	for(int i = 0; i < m; i++){
		int ai = arr[i];
		if(lst[ai] != -1){
			q[q_sz].lo = lst[ai]+1;
			q[q_sz].hi = i-1;
			q[q_sz].idx = ai;
			q_sz++;
		}
		lst[ai] = i;
	}
	for(int i = 0; i < n; i++){
		lst[i] = -1;
	}
	for(int i = m-1; i >= 0; i--){
		int ai = arr[i];
		if(lst[ai]==-1){
			q[q_sz].lo = i+1;
			q[q_sz].hi = m-1;
			q[q_sz].idx = ai;
			q_sz++;
		}
		lst[ai] = i;
	}
	
	sort(q, q+m);
	
	int l = 1, r = 0;
	for(int i = 0; i < q_sz; i++){
		
		int cl = q[i].lo;
		int cr = q[i].hi;	
		int cidx = q[i].idx;
		
		while(r < cr) add(++r);
		while(cl < l) add(--l);
		while(cr < r) rem(r--);
		while(l < cl) rem(l++);
		
		mx[cidx] = max(mx[cidx], ans);
	}
	
	for(int i = 0; i < n; i++){
		cout << mn[i]+1 << ' ' << mx[i]+1 << endl;
	}
}
