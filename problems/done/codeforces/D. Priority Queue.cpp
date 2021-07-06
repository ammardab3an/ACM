// Problem: D. Priority Queue
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/D
// Memory Limit: 512 MB
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
const int MOD = 998244353;
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, wanted;
int arr[505];
int mem[505][505];

int go(int pos, int cnt, bool b){
    
    if(b && !cnt) return 0;
    if(pos == n) return 1;
    
    int &ret = mem[pos][cnt];
    if(ret+1) return ret;
    
    if(pos == wanted){
        return ret = go(pos+1, cnt+1, 1);
    }
    
    int stPath = go(pos+1, cnt, b);
    
    int ndPath;
    if(arr[pos] == -1){
        ndPath = go(pos+1, max(cnt-1, int(0)), b);
    }
    else{
        if(!b){        
            ndPath = go(pos+1, cnt+(arr[pos]<arr[wanted]), b);
        }
        else{
            ndPath = go(pos+1, cnt+(arr[pos]<=arr[wanted]), b);
        }
    }
    
    return ret = add(stPath, ndPath);
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

        char c;
        cin >> c;
        
        if(c == '-'){
            arr[i] = -1;
        }
        else{
            cin >> arr[i];
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) if(arr[i] != -1){
        
        wanted = i;
        memset(mem, -1, sizeof mem);
        ans = add(ans, mul(arr[i], go(0, 0, 0)));
    }
    
    cout << ans << endl;
}
