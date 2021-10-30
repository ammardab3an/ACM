// Problem: C. Crystal Caves
// Contest: Codeforces - 2021 Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103366/problem/C
// Memory Limit: 512 MB
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
 
const int NMAX = 2e3 + 10;

int n;
struct ai{
    int l, r;
} arr[NMAX];

int mem[NMAX][NMAX];

int go(int i, int rem_l){
    
    if(rem_l < 0){
        return -INFLL;
    }
    
    if(i == n){
        return rem_l==0 ? 0 : -INFLL;
    }   
    
    int &ret = mem[i][rem_l];
    if(ret+1) return ret;
    
    int rem_r = n-i-rem_l;
    int st_path = arr[i].l * ((-i) + ((rem_l-1) - rem_r)) + go(i+1, rem_l-1);
    int nd_path = arr[i].r * ((+i) + (rem_l - (rem_r-1))) + go(i+1, rem_l);
    
    return ret = max(st_path, nd_path);
}


void calc (int i, int rem_l){
    
    if(i == n){
        return;
    }   
    
    int ans = go(i, rem_l);
    
    int rem_r = n-i-rem_l;
    int st_path = arr[i].l * ((-i) + ((rem_l-1) - rem_r)) + go(i+1, rem_l-1);
    int nd_path = arr[i].r * ((+i) + (rem_l - (rem_r-1))) + go(i+1, rem_l);
    
    cout << i << ' ' << rem_l << ' ';
    
    if(st_path == ans){
        cout << arr[i].l << endl;
        calc(i+1, rem_l-1);
    }
    else if(nd_path == ans){
        cout << arr[i].r << endl;
        calc(i+1, rem_l);
    }
    else{
        assert(false);
    }
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
        cin >> arr[i].l >> arr[i].r;
    }
    
    int ans_y = 0;
    int pst_y = 0;
    for(int i = 1; i <= n; i++){
        ans_y += (i-1) * i - pst_y;
        pst_y += i;
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans_x;
    if(n%2==0){
        ans_x = go(0, n/2);
        // calc(0, n/2);
    }
    else{
        ans_x = go(0, (n+1)/2);
    }
    
    cout << ans_x+ans_y << endl;
}
