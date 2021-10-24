// Problem: C. GukiZ hates Boxes
// Contest: Codeforces - Codeforces Round #307 (Div. 2)
// URL: https://codeforces.com/problemset/problem/551/C
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

int n, m;
int arr[NMAX];
vi vec;

bool can(int t){
    
    int lst = vec.size() -1;
    int lst_rst = 0;
    
    int mm = m; while(mm-- && lst >= 0){
        
        int tt = t;
        
        tt -= vec[lst] + 1;
        
        if(tt < 0){
            return false;
        }
        
        if(lst_rst){
            int mn = min(tt, lst_rst);
            tt -= mn;
            lst_rst -= mn;
            if(!lst_rst) lst--;
        }
        
        while(lst >= 0 && tt > 0){
            if(arr[vec[lst]] <= tt){
                tt -= arr[vec[lst]];
                lst--;
            }    
            else{
                lst_rst = arr[vec[lst]] - tt;
                tt = 0;
            }
        }
    }
    
    return lst == -1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        
        cin >> arr[i];
        
        if(arr[i]){
            vec.push_back(i);    
        }
    }
    
    int l = 0;
    int r = INFLL;
    
    int ans = -1;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        if(can(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    cout << ans << endl;
}
