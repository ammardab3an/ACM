
// J. Jacked Tickets
// https://codeforces.com/gym/101856/problem/j

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

int arr[505];
int mem[505][505];
int vis[505][505], vid;

int go(int n, int m){
    
    if(m == 1) return arr[n];
    
    if(vis[n][m] == vid) 
        return mem[n][m];
    vis[n][m] = vid;    
    
    int l = 1;
    int r = n-m+1;
    
    auto f = [&](int i){
        return go(n-i, m-1) + arr[i];
    };
    
    int ans = min(f(l), f(r));
    
    while(r-l > 1){
        
        int mid = (l+r)/2;
        int ans1 = f(mid), ans2 = f(mid+1);
        if(ans1 > ans2){
            l = mid, ans = min(ans, ans2);
        }
        else{
            r = mid, ans = min(ans, ans1);
        }
    }
    
    return mem[n][m] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("jacking.in", "r", stdin);
    
    int tt = 0;
    int t; cin >> t; while(t--){
        
        cout << "Case " << ++tt << ": " << endl;

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        
        vid++;
        int q; cin >> q; while(q--){
            
            int a, b;
            cin >> a >> b;
            
            if(a < b){
                cout << "impossible" << endl;
                continue;
            }
            
            int ans = go(a, b);
            cout << ans << endl;
        }
    }	
}
