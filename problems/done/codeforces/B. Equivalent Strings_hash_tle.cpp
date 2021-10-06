// Problem: B. Equivalent Strings
// Contest: Codeforces - Codeforces Round #313 (Div. 1)
// URL: https://codeforces.com/problemset/problem/559/B
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
char str[2][NMAX];

int p[2], md[2];
int pre[2][2][NMAX];
int ppo[2][NMAX];

void hash_init(){
    
    p[0] = 29;
    p[1] = 31;
    
    md[0] = 1e9 + 7;
    md[1] = 1e9 + 9;
    
    ppo[0][0] = ppo[1][0] = 1;
    
    for(int k = 0; k < 2; k++)
    for(int i = 1; i < NMAX; i++){
        ppo[k][i] = (ppo[k][i-1] * p[k])%md[k];
    }
    
    pre[0][0][0] = str[0][0]-'a'+1;
    pre[0][1][0] = str[0][0]-'a'+1;
    pre[1][0][0] = str[1][0]-'a'+1;
    pre[1][1][0] = str[1][0]-'a'+1;
    
    for(int s = 0; s < 2; s++)
    for(int k = 0; k < 2; k++)
    for(int i = 1; i < n; i++){
        pre[s][k][i] = ((pre[s][k][i-1] * p[k])%md[k] + (str[s][i]-'a'+1))%md[k];
    }
}

int hash_sub(int s, int k, int l, int r){
    
    int h = pre[s][k][r];
    
    if(l){
        int d = (pre[s][k][l-1]*ppo[k][r-l+1])%md[k];
        h = (h-d)%md[k];
        h = (h+md[k])%md[k];
    }    
    
    return h;
}

bool go(int l, int r, int i, int j){
    
    if(l > r){
        return true;
    }
    
    int h0 = hash_sub(0, 0, l, r);
    int h1 = hash_sub(0, 1, l, r);
    int h2 = hash_sub(1, 0, i, j);
    int h3 = hash_sub(1, 1, i, j);
    
    bool st_path = (h0==h2) && (h1==h3);
    
    if(st_path || ((r-l+1)%2==1)){
        return st_path;
    }
    
    int mid = (r-l)/2;
    bool nd_path = go(l, l+mid, i, i+mid) && go(l+mid+1, r, i+mid+1, j);
    if(nd_path) return true;
    bool rd_path = go(l, l+mid, i+mid+1, j) && go(l+mid+1, r, i, i+mid);
    if(rd_path) return true;
    return false;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> str[0] >> str[1];
    n = strlen(str[0]);
    
    hash_init();
    
    bool ans = go(0, n-1, 0, n-1);
    cout << (ans ? "YES" : "NO") << endl;
}
