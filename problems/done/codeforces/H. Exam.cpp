// Problem: H. Exam
// Contest: Codeforces - 2017-2018 ICPC Central Quarter Final of Northeastern European Regional Collegiate Programming Contest
// URL: https://codeforces.com/gym/102788/problem/H
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
const int NMAX = 1e4 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

#define uint uint64_t

int x;
int mem[NMAX];
bool flag;

int go(int n){
    
    if(flag){
        return 0;
    }
    
    if(n==1){
        return 1;
    }    
    
    int &ret = mem[n];
    if(ret+1) return ret;
    
    int st_path = go(n-1);
    int nd_path = (n > x) ? go(n-x) : 0;
    int rd_path = (n%7==0) ? go(n/7) : 0;
    
    if(st_path + nd_path < 0 || st_path + rd_path < 0 || st_path + nd_path + rd_path < 0){
        flag = true;
        return 0;
    }
    
    return ret = st_path + nd_path + rd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    
    int l = 2;
    int r = n-1;
    
    int ans = -1;
    
    while(l <= r){
        
        int mid = (l+r)/2;    
        :: x = mid;
        
        flag = false;
        memset(mem, -1, sizeof mem);
        int que = go(n);
        
        if(!flag && que == k){
            ans = mid;
            r = mid-1;
        }
        else if(flag || que > k){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
        
    }
    
    if(ans==-1) ans = 0;
    cout << ans << endl;
    
}
