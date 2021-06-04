// Problem: A - Race Against Time
// Contest: Virtual Judge - DS & DP #1
// URL: https://vjudge.net/contest/442197#problem/A
// Memory Limit: 1572 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;
const int MMAX = 5e4 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, q;
int arr[NMAX];
int comp[NMAX+MMAX], comp_sz;
int q_lo[MMAX], q_hi[MMAX], q_x[MMAX], q_tim[MMAX], q_idx[MMAX], q_sz;
int u_pos[MMAX], u_old[MMAX], u_new[MMAX], t_sz;

int tree[(NMAX+MMAX) << 2];

int ans[MMAX];

void compress(){
    
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(comp, comp+comp_sz, arr[i]) - comp;
    }
    
    for(int i = 0; i < q_sz; i++){
        q_x[i] = lower_bound(comp, comp+comp_sz, q_x[i]) - comp;
    }
    
    for(int i = 0; i < t_sz; i++){
        u_old[i] = lower_bound(comp, comp+comp_sz, u_old[i]) - comp;
        u_new[i] = lower_bound(comp, comp+comp_sz, u_new[i]) - comp;
    }
}

int base[NMAX+MMAX];
const int base_sqrt_sz = ceil(sqrt(double(NMAX+MMAX)));
int base_sqrt[base_sqrt_sz];

inline void add(int val){
    base[val] += 1;
    base_sqrt[val/base_sqrt_sz] += 1;
}
inline void rem(int val){
    base[val] -= 1;
    base_sqrt[val/base_sqrt_sz] -= 1;
}
inline int sqrt_query(int val){
    int ret = 0;
    for(int i = val/base_sqrt_sz-1; i >= 0; i--) ret += base_sqrt[i];
    for(int i = (val/base_sqrt_sz) * base_sqrt_sz; i <= val; i++) ret += base[i];
    return ret;
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

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        comp[comp_sz++] = arr[i];
    }
    
    for(int i = 0; i < q; i++){
        
        char c;
        cin >> c;
        
        if(c == 'C'){
            
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            
            q_lo[q_sz] = l;
            q_hi[q_sz] = r;
            q_x[q_sz] = x;
            q_idx[q_sz] = q_sz;
            q_tim[q_sz] = t_sz;
            
            comp[comp_sz++] = x;
            
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
    
    int block = ceil(pow(double(n), 2.0/3.0));
    
    sort(q_idx, q_idx+q_sz, [block](int i, int j){
        int ilo = q_lo[i]/block, ihi = q_hi[i]/block;
        int jlo = q_lo[j]/block, jhi = q_hi[j]/block;
        return tie(ilo, ihi, q_tim[i]) < tie(jlo, jhi, q_tim[j]);
    });
    
    for(int i = 0; i < q_sz; i++){
        query(q_idx[i]);
        ans[q_idx[i]] = sqrt_query(q_x[q_idx[i]]);
    }
    
    for(int i = 0; i < q_sz; i++){
        cout << ans[i] << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
