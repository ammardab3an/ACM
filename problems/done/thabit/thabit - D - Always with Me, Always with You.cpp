
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

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
 
const int NMAX = 1e6 + 10;

int n, m;
int arr_a[NMAX], arr_b[NMAX], cost_a[NMAX];
int pre[NMAX];

int sz;
vector<vi> pos;
int mem[NMAX];

int go(int p, int idx){
    
    if(p == sz-1){
        int ans = pre[n-1] - pre[idx];
        return ans;
    }    
    
    int &ret = mem[idx];
    if(ret+1) return ret;
    
    auto it_lower = lower_bound(pos[p+1].begin(), pos[p+1].end(), idx);
        
    if(it_lower == pos[p+1].end()) 
        return ret = INFLL;
    
    int ans = INFLL;
    
    for(; it_lower != pos[p+1].end(); it_lower++){
        
        int nxt_idx = *it_lower;
        int cur_ans = pre[nxt_idx-1] - pre[idx] + go(p+1, nxt_idx);
        ans = min(ans, cur_ans);
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr_a[i];
    for(int i = 0; i < n; i++) cin >> cost_a[i];
    for(int i = 0; i < m; i++) cin >> arr_b[i];
    
    pre[0] = min(int(0), cost_a[0]);
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + min(int(0), cost_a[i]);
    
    map<int, vi> mp;
    for(int i = 0; i < n; i++){
        mp[arr_a[i]].push_back(i);
    }
    
    for(int i = 0; i < m; i++){
        pos.push_back(mp[arr_b[i]]);
        sort(pos.back().begin(), pos.back().end());
    }
    
    sz = pos.size();
    memset(mem, -1, sizeof mem);
    
    int ans = INFLL;
    
    for(auto p : pos[0]){
        
        int cur_ans = go(0, p);
        if(p) cur_ans += pre[p-1];
        
        ans = min(ans, cur_ans);
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
