// Problem: E. XOR and Favorite Number
// Contest: Codeforces - Codeforces Round #340 (Div. 2)
// URL: https://codeforces.com/problemset/problem/617/E
// Memory Limit: 256 MB
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
 
const int NMAX = 1e5 + 10;
const int MMAX = 1e5 + 10;
const int AMAX = (1<<20) + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, k;
int arr[NMAX];
struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo/BLOCK < other.lo/BLOCK;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];

int xor_pre, xor_suf, xor_tot;
int mp_pre[AMAX];
int mp_suf[AMAX];
int64_t q_ans[NMAX], ans;

void add_ri(int i){
	xor_suf ^= arr[i];
	mp_suf[xor_suf ^ arr[i]]++;
	xor_tot ^= arr[i];
	mp_pre[xor_pre ^ xor_tot]++;
	ans += mp_suf[xor_suf^k];
}
void rem_ri(int i){
	ans -= mp_suf[xor_suf^k];
	mp_suf[xor_suf ^ arr[i]]--;
	xor_suf ^= arr[i];
	mp_pre[xor_pre ^ xor_tot]--;
	xor_tot ^= arr[i];
}
void add_lf(int i){
	xor_pre ^= arr[i];
	mp_pre[xor_pre ^ arr[i]]++;
	xor_tot ^= arr[i];
	mp_suf[xor_suf ^ xor_tot]++;
	ans += mp_pre[xor_pre^k];
}
void rem_lf(int i){
	ans -= mp_pre[xor_pre^k];
	mp_pre[xor_pre ^ arr[i]]--;
	xor_pre ^= arr[i];
	mp_suf[xor_suf ^ xor_tot]--;
	xor_tot ^= arr[i];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    for(int i = 0; i < m; i++){
    	cin >> q[i].lo >> q[i].hi;
    	q[i].lo--, q[i].hi--, q[i].idx=i;
    }
    
    sort(q, q+m);
    
    int l = 1, r = 0;
    for(int i = 0; i < m; i++){
    	
    	int cl = q[i].lo;
    	int cr = q[i].hi;
    	int cidx = q[i].idx;
    	
    	while(r < cr) add_ri(++r);
    	while(cl < l) add_lf(--l);
    	while(cr < r) rem_ri(r--);
    	while(l < cl) rem_lf(l++);
    	
    	q_ans[cidx] = ans;
    }
    
    for(int i = 0; i < m; i++){
    	cout << q_ans[i] << endl;
    }
}
