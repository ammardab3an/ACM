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

void add(int idx){
	frq[arr[idx]]++;
}

void rem(int idx){
	frq[arr[idx]]--;
}

int get_ans(int l, int r, int k){
	
	int ret = INF;
	int kk = (r-l+1+k-1)/k + ((r-l+1)%k==0);
	double p = double((r-l+1)-kk)/(r-l+1);

	double pp = 1;
	// cout << l << ' ' << r << ' ' << k << ' ' << kk << ' ' << p << endl << flush;
	
	do {
		
		pp *= p;
		int val = arr[rand(l, r)];
		
		if(frq[val] >= kk){
			ret = min(ret, val);
		}
		
		
	} while(pp > 1e-7);
	
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
