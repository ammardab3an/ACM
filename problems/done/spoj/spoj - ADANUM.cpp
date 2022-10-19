// Problem: Ada and Numbering
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ADANUM/en/
// Memory Limit: 1536 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, sz;
int arr[NMAX];
int tmp[NMAX];
int q_ans[NMAX];
int pos[NMAX];
int tmpo[NMAX];
int lf_pos[NMAX];
int ri_pos[NMAX];
int frq[NMAX];
int ans;

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo/BLOCK < other.lo/BLOCK;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];

void comp(){
	sort(tmp, tmp+n);
	sz = unique(tmp, tmp+n)-tmp;
	for(int i = 0; i < n; i++){
		arr[i] = lower_bound(tmp, tmp+sz, arr[i])-tmp;
	}
}

void add(int i){
	ri_pos[frq[arr[i]]]--;
	int a = arr[i], b = tmpo[ri_pos[frq[arr[i]]]];
	int pa = pos[a], pb = pos[b];
	swap(pos[a], pos[b]);
	swap(tmpo[pa], tmpo[pb]);
	frq[arr[i]]++;
	lf_pos[frq[arr[i]]]--;
	ans += sz-pos[arr[i]];
}

void rem(int i){
	int a = arr[i], b = tmpo[lf_pos[frq[arr[i]]]];
	int pa = pos[a], pb = pos[b];
	swap(pos[a], pos[b]);
	swap(tmpo[pa], tmpo[pb]);
	lf_pos[frq[arr[i]]]++;
	frq[arr[i]]--;
	ri_pos[frq[arr[i]]]++;
	ans -= sz-pos[arr[i]];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	tmp[i] = arr[i];
    }
    
    comp();
    iota(pos, pos+sz, 0);
    iota(tmpo, tmpo+sz, 0);
    lf_pos[0] = 0;
    ri_pos[0] = sz;
    for(int i = 1; i <= n; i++){
    	lf_pos[i]=ri_pos[i] = sz;	
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
    	
    	while(r < cr) add(++r);
    	while(cl < l) add(--l);
    	while(cr < r) rem(r--);
    	while(l < cl) rem(l++);
    	
    	q_ans[cidx] = ans;
    }
    
    for(int i = 0; i < m; i++){
    	cout << q_ans[i] << endl;
    }
}
