// Problem: C. Vladik and Memorable Trip
// Contest: Codeforces - Codeforces Round #416 (Div. 2)
// URL: https://codeforces.com/contest/811/problem/C
// Memory Limit: 256 MB
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
 
const int NMAX = 5050+ 10;
// const int LOG_MAX = ceil(log2(double(NMAX)));

int n;
int arr[NMAX];
int mem[NMAX];
int lf[NMAX], ri[NMAX];
int arr_lf[NMAX], arr_ri[NMAX];

struct sparse_table_mx{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table_mx(){};
    
    sparse_table_mx(int n, int arr[]){
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = i;
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            if(arr[st[i][j-1]] > arr[st[i+(1<<(j-1))][j-1]]){
                st[i][j] = st[i][j-1];
            }
            else{
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        if(arr[st[l][j]] > arr[st[r-(1<<j)+1][j]]){
            return st[l][j];
        }
        else{
            return st[r-(1<<j)+1][j];
        }
    }
    
} mx_r;

struct sparse_table_mn{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table_mn(){};
    
    sparse_table_mn(int n, int arr[]){
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = i;
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            if(arr[st[i][j-1]] < arr[st[i+(1<<(j-1))][j-1]]){
                st[i][j] = st[i][j-1];
            }
            else{
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        if(arr[st[l][j]] < arr[st[r-(1<<j)+1][j]]){
            return st[l][j];
        }
        else{
            return st[r-(1<<j)+1][j];
        }
    }
    
} mn_l;

int go(int i){
    
    if(i == n){
        return 0;
    }    
    
    int &ret = mem[i];
    if(ret+1) return ret;
    
    int st_path = go(i+1);
    int nd_path = 0;
    
    int l = arr_lf[i];
    int r = arr_ri[i];
    
    int m_l = arr_lf[mn_l.query_range(l, r)];
    int m_r = arr_ri[mx_r.query_range(l, r)];
    
    if(m_l == i){    
        
        set<int> st;
        for(int i = m_l; i <= m_r; i++){
            st.insert(arr[i]);
        }
        
        int _xor = 0;
        for(auto i : st) _xor ^= i;
        
        nd_path = _xor + go(m_r+1);
    }
    
    return ret = max(st_path, nd_path);
}

void calc(int i){
    
    if(i == n){
        return;
    }
    
    if(go(i) == go(i+1)){
        calc(i+1);
        return;
    }
    
    int l = arr_lf[i];
    int r = arr_ri[i];
    
    int m_l = arr_lf[mn_l.query_range(l, r)];
    int m_r = arr_ri[mx_r.query_range(l, r)];
    
    calc(m_r+1);     
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    for(int i = 0; i < 5050; i++){
        lf[i] = INFLL;
        ri[i] = -INFLL;
    }
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        lf[arr[i]] = min(lf[arr[i]], i);
        ri[arr[i]] = max(ri[arr[i]], i);
    }
    
    for(int i = 0; i < n; i++){
        arr_lf[i] = lf[arr[i]];
        arr_ri[i] = ri[arr[i]];
    }
    
    mn_l = sparse_table_mn(n, arr_lf);
    mx_r = sparse_table_mx(n, arr_ri);
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0);
    cout << ans << endl;
    // calc(0);
}
