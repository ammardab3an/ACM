// Problem: H. SBC's Hangar
// Contest: Codeforces - 2020-2021 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/102861/problem/H
// Memory Limit: 1024 MB
// Time Limit: 250 ms
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

int n, k;
int arr[50];

int lb(int val){
    
    int l = 0;
    int r = (1ll << n)-1;
    
    int ans = r+1;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        bool good = false;
        
        int sm = 0;
        for(int i = 0; i < n; i++) if((mid>>i)&1){
            sm += arr[i];    
            if(sm >= val){
                good = true;
                break;
            }
        }   
         
        if(good){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }    
    
    return ans;
}

int val;
int mem[55][55][2];

int go(int i, int rem_k, bool b_lower){
    
    if(rem_k==-1){
        return 0;
    }
    
    if(i==-1){
        return rem_k==0;
    }    
    
    int &ret = mem[i][rem_k][b_lower];
    if(ret+1) return ret;
    
    int st_path = go(i-1, rem_k, b_lower || ((val>>i)&1));
    int nd_path = 0;
    
    if(b_lower){
        nd_path = go(i-1, rem_k-1, 1);
    }
    else if((val>>i)&1){
        nd_path = go(i-1, rem_k-1, 0);
    }
    
    return ret = st_path + nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    int A, B;
    cin >> A >> B;
    
    int l = lb(A);
    int r = lb(B+1)-1;
    
    if(l > r){
        cout << 0 << endl;
        return 0;
    }
    
    ::val = r;
    memset(mem, -1, sizeof mem);
    int ans = go(n-1, k, 0);
    
    :: val = l-1;
    memset(mem, -1, sizeof mem);
    ans -= go(n-1, k, 0);
    
    cout << ans << endl;
}
