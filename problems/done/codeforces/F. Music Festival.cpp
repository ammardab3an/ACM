// Problem: F. Music Festival
// Contest: Codeforces - 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/101908/problem/F
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

int n, sz;
pair<pii, pii> arr[1010];

int mem[1010][1 << 10];

int go(int i, int msk){
    
    if(i == sz){
        if(msk+1 == (1<<n)) return 0;
        else return -INF;
    }
    
    int &ret = mem[i][msk];
    if(ret+1) return ret;
    
    int st_path = go(i+1, msk);
    
    int it = lower_bound(arr+i, arr+sz, (pair<pii,pii>){{arr[i].first.second, 0}, {0, 0}}) - arr;
    int nmsk = msk | (1 << (arr[i].second.second));
    int nd_path = go(it, nmsk) + arr[i].second.first;
    
    return ret = max(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        while(m--){
            int l, r, v;
            cin >> l >> r >> v;
            arr[sz++] = {{l, r}, {v, i}};
        }
    }
    
    sort(arr, arr+sz);
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0, 0);
    if(ans <= 0) ans = -1;
    cout << ans << endl;
}
