// Problem: C. Shooting Gallery
// Contest: Codeforces - Codeforces Beta Round #30 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/30/C
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
struct trg{
    
    int x, y, t;
    double p;
    
    bool operator < (const trg &other){
        return t < other.t;
    }
    
} target[NMAX];

int dist(int i, int j){
    return pow(target[i].x - target[j].x, 2) + pow(target[i].y - target[j].y, 2);
}

double mem[NMAX];
bool vis[NMAX];

double go(int i){
    
    if(vis[i]){
        return mem[i];
    }
    else{    
        vis[i] = true;
    }
    
    double ans = 0;
    
    for(int j = i+1; j < n; j++){
        if(dist(i, j) <= pow(target[j].t-target[i].t, 2)){
            double cans = target[j].p + go(j);
            ans = max(ans, cans);
        }    
    }
    
    return mem[i] = ans;
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
        cin >> target[i].x >> target[i].y >> target[i].t >> target[i].p;
    }
    
    sort(target, target+n);
    
    double ans = 0;
    for(int i = 0; i < n; i++) 
        ans = max(ans, target[i].p + go(i));
    
    cout << fixed << setprecision(10) << ans << endl;
}

