// Problem: M. Restorer Distance
// Contest: Codeforces - NAM
// URL: https://codeforces.com/gym/344772/problem/M
// Memory Limit: 256 MB
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

int n, A, R, M;
int arr[NMAX];
int pre[NMAX];

int calc(int a, int d){
    if(M <= A+R){
        return a*A + d*R -min(a, d)*(A+R-M);
    }   
    else{
        return a*A + d*R;
    } 
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> A >> R >> M;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    pre[0] = arr[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + arr[i];
    
    auto f = [&](int h){
        
        int higher = 0, lower = 0;
        int a = 0, b = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] <= h){
                a += h;
                a -= arr[i];
            }
            else{
                b += arr[i];
                b -= h;
            }
        }
        
        return calc(a, b);
    };
    
    ll lo = 0 , hi = 1e9+10 , mid ; 
    ll ans = min( f(lo),f(hi) ) ; 

    while ( hi-lo > 1 ){ 
        mid = (lo+hi)/2 ; 
        ll ans1 = f(mid) , ans2 = f(mid+1) ; 
        if( ans1 > ans2 ) 
            lo = mid ,ans = min ( ans , ans2 ) ; 
        else 
            hi = mid ,ans = min ( ans , ans1 ) ; 
    }
    
    cout << ans << endl;
}
