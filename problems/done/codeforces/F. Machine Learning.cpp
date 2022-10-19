// Problem: F. Machine Learning
// Contest: Codeforces - Codeforces Round #466 (Div. 2)
// URL: https://codeforces.com/problemset/problem/940/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 1e5 + 10;

int n, m;
int q_sz, t_sz, comp_sz; 
int arr[NMAX];
int comp[NMAX*2];
int lo[NMAX], hi[NMAX], idx[NMAX], tim[NMAX];
int uold[NMAX], unew[NMAX], uidx[NMAX];
int frq[NMAX*2];
int cnt[NMAX];
int q_ans[NMAX], ans;
bool mex[NMAX];

void compress(){
	
	sort(comp, comp+comp_sz);
	comp_sz = unique(comp, comp+comp_sz)-comp;
	
	for(int i = 0; i < n; i++){
		arr[i] = lower_bound(comp, comp+comp_sz, arr[i])-comp;
	}
	
	for(int i = 0; i < t_sz; i++){
		uold[i] = lower_bound(comp, comp+comp_sz, uold[i])-comp;
		unew[i] = lower_bound(comp, comp+comp_sz, unew[i])-comp;
	}
}

void add_mex(int i){
	mex[i] = 1;
}

void rem_mex(int i){
	mex[i] = 0;
}

int query_mex(int ln){
	for(int i = 1; (i)*(i-1)/2 <= ln; i++){
		if(!mex[i]){
			return i;
		}
	}
	assert(false);
}

void add(int i){
	
	if(cnt[frq[i]]==1){
		rem_mex(frq[i]);
	}
		
	cnt[frq[i]]--;
	frq[i]++;
	cnt[frq[i]]++;
	
	if(cnt[frq[i]]==1){
		add_mex(frq[i]);
	}
}

void rem(int i){
	
	if(cnt[frq[i]]==1){
		rem_mex(frq[i]);
	}
		
	cnt[frq[i]]--;
	frq[i]--;
	cnt[frq[i]]++;
	
	if(cnt[frq[i]]==1){
		add_mex(frq[i]);
	}
}

int l = 1, r = 0, &t = t_sz;

void update(int i){
	
	int cl = lo[i];
	int cr = hi[i];	
	int ct = tim[i];
	
	while(t < ct){
		if(l <= uidx[t] && uidx[t] <= r){
			rem(uold[t]);
			add(unew[t]);
		}
		arr[uidx[t]] = unew[t];
		t++;
	}
	
	while(ct < t){
		t--;
		if(l <= uidx[t] && uidx[t] <= r){
			rem(unew[t]);
			add(uold[t]);
		}
		arr[uidx[t]] = uold[t];
	}
	
	while(r < cr) add(arr[++r]);
	while(cl < l) add(arr[--l]);
	while(cr < r) rem(arr[r--]);
	while(l < cl) rem(arr[l++]);
	
	q_ans[i] = query_mex(r-l+1);
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
    	comp[comp_sz++] = arr[i];
    }
    
    cnt[0] = INFLL;
    
    for(int i = 0; i < m; i++){
    	
    	int k, a, b;
    	cin >> k >> a >> b;
    	
    	if(k==1){
    		lo[q_sz] = a-1;
    		hi[q_sz] = b-1;
    		tim[q_sz] = t_sz;
    		idx[q_sz] = q_sz;
    		q_sz++;
    	}
    	else{
    		uidx[t_sz] = a-1;
    		uold[t_sz] = arr[a-1];
    		unew[t_sz] = b;
    		
    		comp[comp_sz++] = b;
    		
    		arr[a-1] = b;
    		
    		t_sz++;
    	}
    }
    
	compress();
	
	int block = ceil(pow(2, 1.0/3.0) * pow(n, 2.0/3.0));
	sort(idx, idx+q_sz, [&](int i, int j){
		int ilo = lo[i]/block, ihi = hi[i]/block, itim = tim[i];
		int jlo = lo[j]/block, jhi = hi[j]/block, jtim = tim[j];
		return tie(ilo, ihi, itim) < tie(jlo, jhi, jtim);
	});
	
	for(int i = 0; i < q_sz; i++){
		update(idx[i]);
	}
	
	for(int i = 0; i < q_sz; i++){
		cout << q_ans[i] << endl;
	}
}
