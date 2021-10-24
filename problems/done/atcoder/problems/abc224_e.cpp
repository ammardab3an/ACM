// Problem: E - Integers on Grid
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_e
// Memory Limit: 1024 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
    
    int i, j, val, id;
    
    bool operator < (const node &other){
        return val > other.val;
    }
    
} arr[NMAX];

int n, m, k;
int ans[NMAX];
map<int, int> mp[NMAX], pm[NMAX];

int go(int pos){
    
    int i = arr[pos].i;
    int j = arr[pos].j;
    int val = arr[pos].val;
    
    int ans = 0;
    
    {
        auto it = mp[i].lower_bound(val+1);
        if(it != mp[i].end()) ans = max(ans, (it->second) + 1);
    }
    
    {
        auto it = pm[j].lower_bound(val+1);
        if(it != pm[j].end()) ans = max(ans, (it->second) + 1);
    }
    
    mp[i][val] = max(mp[i][val], ans);
    pm[j][val] = max(pm[j][val], ans);
        
    return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++){
        arr[i].id = i;
        cin >> arr[i].i >> arr[i].j >> arr[i].val;
    }
    
    sort(arr, arr+k);
    
    for(int i = 0; i < k; i++){
        ans[arr[i].id] = go(i);
    }
    
    for(int i = 0; i < k; i++){
        cout << ans[i] << endl;
    }
}