// Problem: Sum of Distinct Numbers
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/XXXXXXXX/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
 
// By AmmarDab3an - Aleppo University
 
#include "bits/stdc++.h"
 
using namespace std;
 
#define int int64_t
#define lli int64_t
 
// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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
	int timp = pow_exp(n, p/2);
	return mul(timp, timp);
}
 
const int NMAX = 5e4 + 10;
const int MMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
 
int n, m, comp_sz, q_sz, t_sz;
int arr[NMAX], comp[NMAX+MMAX];
int lo[MMAX], hi[MMAX], idx[MMAX], tim[MMAX];
int uold[MMAX], unew[MMAX], uidx[MMAX];
int frq[NMAX + MMAX];
int ans[MMAX], cans;
 
void compress(){
    
    sort(comp, comp + comp_sz);
    comp_sz = unique(comp, comp + comp_sz) - comp;
    
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(comp, comp+comp_sz, arr[i]) - comp;
    }
    
    for(int i = 0; i < t_sz; i++){
        uold[i] = lower_bound(comp, comp + comp_sz, uold[i]) - comp;
        unew[i] = lower_bound(comp, comp + comp_sz, unew[i]) - comp;
    }
}
 
void add(int val){
    if(!frq[val]++)
        cans += comp[val];    
}
void rem(int val){
    if(!--frq[val])
        cans -= comp[val];   
}
 
int l = 1, r = 0, &t = t_sz;
 
void update(int q_idx){
    
    int cl = lo[q_idx];
    int cr = hi[q_idx];
    int ct = tim[q_idx];
    
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
}
 
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        comp[comp_sz++] = arr[i];
    }
    
    cin >> m; while(m--){    
        
        char c;
        int x, y;
        cin >> c >> x >> y;
        
        if(c == 'Q'){
            
            lo[q_sz] = x-1;
            hi[q_sz] = y-1;
            tim[q_sz] = t_sz;
            idx[q_sz] = q_sz;
            
            q_sz++;
        }
        else{
            
            uidx[t_sz] = x-1;
            uold[t_sz] = arr[x-1];
            unew[t_sz] = y;
            
            comp[comp_sz++] = y;
            
            arr[x-1] = y;
            
            t_sz++;
        }
           
    }
    
    compress();
    
    int block = ceil(pow(n, 2.0/3.0));
    sort(idx, idx + q_sz, [block](int i, int j){
        int ilo = lo[i]/block, ihi = hi[i]/block, itim = tim[i];
        int jlo = lo[j]/block, jhi = hi[j]/block, jtim = tim[j];
        return tie(ilo, ihi, itim) < tie(jlo, jhi, jtim);
    });
    
    for(int i = 0; i < q_sz; i++){
        update(idx[i]);
        ans[idx[i]] = cans;
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