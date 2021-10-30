// Problem: E. Arena
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int MOD = 998244353 ; //1e9 + 7;
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

int n, x;
int mem[555][555];
int fpow[555][555], cho[555][555];

void init(){
    
    for(int i = 0; i < 555; i++)
    for(int j = 0; j <= i;  j++){
        
        if(i==j || j==0){
            cho[i][j] = 1;
        }
        else{
            cho[i][j] = add(cho[i-1][j-1], cho[i-1][j]);
        }
    }
    
    for(int i = 0; i < 555; i++){
        fpow[i][0] = 1;
        for(int j = 1; j < 555; j++){
            fpow[i][j] = mul(fpow[i][j-1], i);
        }
    }
}

int go(int rem, int mn_x){
    
    if(rem==0){
        return 1;
    }
    
    if(mn_x > x || rem==1){
        return 0;
    }
    
    int &ret = mem[rem][mn_x];
    if(ret+1) return ret;
    
    // mn_x <= val < mn_x+rem-1
    // mn_x <= val <= mn_x+rem-2
    // mn_x <= val <= x

    int ans = 0;
    for(int cnt = 0; cnt <= rem; cnt++){
        int cans = cho[rem][cnt];
        cans = mul(cans, fpow[min(mn_x+rem-2, x) - mn_x+1][cnt]);
        cans = mul(cans, go(rem-cnt, mn_x+rem-1));
        ans = add(ans, cans);
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
    
    init();
    
    cin >> n >> x;
    
    memset(mem, -1, sizeof mem);
    
    cout << go(n, 1) << endl;
}
