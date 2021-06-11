// Problem: E. Skyline Photo
// Contest: Codeforces - Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int a[NMAX], b[NMAX];
int nxt[NMAX];

int mem[NMAX];
int tree[NMAX << 2];

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p) return;
    
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
    
    if(l > q_r || q_l > r) return -INFLL;
    
    if(q_l <= l && r <= q_r) return tree[nd];
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return max(stPath, ndPath);
}

int go(int pos){
    
    if(pos == -1) return 0;
    
    int &ret = mem[pos];
    if(ret+1) return ret;
    
    go(pos-1);
    
    int ans;
    
    if(nxt[pos] == pos){
        ans = b[pos];
        ans = max(ans, query(1, 0, n-1, 0, pos-1) + b[pos]);
    }
    else{
        ans = go(nxt[pos]);
        ans = max(ans, query(1, 0, n-1, nxt[pos], pos-1) + b[pos]);
    }
    
    update(1, 0, n-1, pos, ans);
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(st.size() && a[st.top()] > a[i]) st.pop();
        nxt[i] = st.size() ? st.top() : i;
        st.push(i);
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(n-1) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
