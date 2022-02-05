// Problem: C. K-th Sum
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 5
// URL: https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/C
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    vi a(n), b(n);
    for(auto &i : a) cin >> i;    
    for(auto &i : b) cin >> i;    
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    auto calc = [&](int m){
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            
            int l = 1; 
            int r = n;
            
            int ans = 0;
            
            while(l <= r){
                
                int mid = (l+r)/2;
                
                if(a[i-1]+b[mid-1] <= m){
                    ans = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            
            cnt += ans;
        }
        
        return cnt;
    };
    
    int l = 0;
    int r = a.back() + b.back();
    
    int ans = 0;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        if(calc(mid) >= k){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    cout << ans << endl;
}
