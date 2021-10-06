// Problem: F2. Complete the Projects (hard version)
// Contest: Codeforces - Codeforces Round #579 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1203/F2
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

// #define endl '\n'
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 

const int NMAX = 3e4 + 10;

int sz;
pii arr[111];
int mem[111][NMAX];

int go(int i, int r){
    
    if(i == sz) return 0;
    
    int &ret = mem[i][r];
    if(ret+1) return ret;
    
    int stPath = go(i+1, r);
    int ndPath = 0;
    
    if(arr[i].first <= r){
        ndPath = go(i+1, r-arr[i].second) + 1;
    }    
    
    return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, r;
    cin >> n >> r;
    
    vpii pos, neg;
    
    for(int i = 0; i < n; i++){
        
        int ai, bi;
        cin >> ai >> bi;
        
        if(bi >= 0){
            pos.push_back({ai, bi});
        }
        else{
            arr[sz++] = {max(ai, -bi), -bi};
        }
    }
    
    int ans = 0;
    
    sort(pos.begin(), pos.end());
    
    for(auto p : pos){
        
        int ai = p.first;
        int bi = p.second;
        
        if(ai <= r){
            r += bi;
            ans++;
        }
    }
    
    sort(arr, arr+sz, [](pii a, pii b){
        return (a.first-a.second) > (b.first-b.second);  
    });
    
    memset(mem, -1, sizeof mem);
    
    ans += go(0, r);
    
    cout << ans << endl;
}
