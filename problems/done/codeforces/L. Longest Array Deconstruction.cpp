// Problem: L. Longest Array Deconstruction
// Contest: Codeforces - COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1575/L
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

int tree[NMAX << 2];

void update(int nd, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l == r){
		tree[nd] = val;
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return max(st_path, nd_path);
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
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vpii new_vec;
    for(int i = 0; i < n; i++){
    	int d = (i+1)-vec[i];
    	if(d < 0) continue;
    	new_vec.push_back({d, vec[i]});
    }
    
    sort(new_vec.begin(), new_vec.end());
    
    for(auto p: new_vec){
    	int cans = query(1, 0, n, 0, p.second-1)+1;
    	update(1, 0, n, p.second, cans);
    }
    
    int ans = query(1, 0, n, 0, n);
    cout << ans << endl;
}

/*

conditions that must be fulfilled:

1 - (i+1) < (j+1)
2 - ai < aj
3 - di <= dj : di=(i+1)-ai
4 - (i+1)-di < (j+1)-dj

if the second and third conditiotns were true:

(1)... ai < aj
(2)... (i+1)-ai <= (j+1)-aj

=> 
	(2)... (i+1) <= (j+1) - (aj-ai)
	becasue (ai < aj): (aj-ai > 0)
	=> i+1 < j+1
	and the first condition is fulfilled

=>
	(1)... ai = aj
	       ai+(i+1)-(i+1) < aj+(j+1)-(j+1)
	       (i+1)-((i+1)-ai) = (j+1)-((j+1)-aj)
        => (i+1)-di < (j+1)-dj
	and the fourth condition is fulfilled
	
in conclusion:
we only need to find a longest increasing subsequence that full filles the ..
second and third conditions, so we can consider di as the new index of the ..
element a[i], and keep a[i] as the value of it, and then simple run a nlogn ..
dp solution with the help of the segment tree datastructure.

*/