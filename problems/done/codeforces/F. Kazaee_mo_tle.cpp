// Problem: F. Kazaee
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
 
const int NMAX = 3e5 + 10;

int n, m;
int arr[NMAX];
int ans[NMAX];

int comp[NMAX*2], comp_sz;
int q_lo[NMAX], q_hi[NMAX], q_k[NMAX], q_tim[NMAX], q_idx[NMAX], q_sz;
int u_pos[NMAX], u_old[NMAX], u_new[NMAX], t_sz;

int frq[NMAX];
int tree[NMAX << 2];
int tree_cnt[NMAX];

void update_seg(int nd, int l, int r, int p, int val){
		
	if(p < l || r < p){
		return;
	}	
	
	if(l==r){
		tree_cnt[p] += val;
		tree[nd] = tree_cnt[p] ? p : 0;
		return;
	}
	
	int mid = (l+r)/2;
	update_seg(nd*2, l, mid, p, val);
	update_seg(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = __gcd(tree[nd*2], tree[nd*2+1]);
}

void compress(){
    
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(comp, comp+comp_sz, arr[i]) - comp;
    }
    
    for(int i = 0; i < t_sz; i++){
        u_old[i] = lower_bound(comp, comp+comp_sz, u_old[i]) - comp;
        u_new[i] = lower_bound(comp, comp+comp_sz, u_new[i]) - comp;
    }
}

void add_fac(int x){
	if(!x) return;
	update_seg(1, 1, n, x, +1);
}
void rem_fac(int x){
	if(!x) return;
	update_seg(1, 1, n, x, -1);
}
bool query_fac(int x){
	return tree[1]%x==0;
}

void add(int x){
	rem_fac(frq[x]);
	add_fac(++frq[x]);
}
void rem(int x){
	rem_fac(frq[x]);
	add_fac(--frq[x]);
}

int l = 1, r = 0, &t = t_sz;
void query(int q_idx){
    
    int cl = q_lo[q_idx];
    int cr = q_hi[q_idx];
    int ct = q_tim[q_idx];
    
    while(t < ct){
        
        int p = u_pos[t];
        
        if(l <= p && p <= r){
            rem(u_old[t]);
            add(u_new[t]);
        }
        
        arr[p] = u_new[t];
        t++;
    }   
    
    while(ct < t){
        
        t--;
        int p = u_pos[t];
        
        if(l <= p && p <= r){
            rem(u_new[t]);
            add(u_old[t]);
        }
        
        arr[p] = u_old[t];
    }
    
    while(r < cr) add(arr[++r]);
    while(cl < l) add(arr[--l]);
    while(cr < r) rem(arr[r--]);
    while(l < cl) rem(arr[l++]);
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
    
    for(int i = 0; i < m; i++){
        
        int c;
        cin >> c;
        
        if(c == 2){
            
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            
            q_lo[q_sz] = l;
            q_hi[q_sz] = r;
            q_k[q_sz] = k;
            q_idx[q_sz] = q_sz;
            q_tim[q_sz] = t_sz;
               
            q_sz++;
        }
        else{
            
            int i, x;
            cin >> i >> x;
            i--;
            
            u_pos[t_sz] = i;
            u_old[t_sz] = arr[i];
            u_new[t_sz] = x;
            
            arr[i] = x;
            
            comp[comp_sz++] = x;
            
            t_sz++;
        }
    }
    
    compress();
    
	const int block = ceil(pow(double(NMAX), 2.0/3.0));
    
    sort(q_idx, q_idx+q_sz, [block](int i, int j){
        int ilo = q_lo[i]/block, ihi = q_hi[i]/block;
        int jlo = q_lo[j]/block, jhi = q_hi[j]/block;
        return tie(ilo, ihi, q_tim[i]) < tie(jlo, jhi, q_tim[j]);
    });
    
      
    for(int i = 0; i < q_sz; i++){
        query(q_idx[i]);
        ans[q_idx[i]] = query_fac(q_k[q_idx[i]]);
    }
    
    for(int i = 0; i < q_sz; i++){
        cout << (ans[i] ? "YES" : "NO") << endl;
    }
}
