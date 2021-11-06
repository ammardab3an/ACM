// Problem: F. String Game
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
// Memory Limit: 512 MB
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

bool can(const string &a, const string &b){
    
    int i = 0, j = 0;
    
    while(i < a.size() && j < b.size()){
        
        if(a[i]==b[j]){
            i++, j++;
        }
        else{
            i++;
        }
    }
    
    return j == b.size();
}
    
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string a, b;
    cin >> a >> b;
    
    vi vec(a.size());
    for(auto &i : vec) cin >> i, --i;
    
    int l = 0;
    int r = a.size();
    
    int ans = r+1;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        vi vis(a.size());
        for(int i = 0; i < mid; i++){
            vis[vec[i]] = true;
        }
        
        string ca;
        for(int i = 0; i < a.size(); i++) if(!vis[i]){
            ca.push_back(a[i]);
        }
        
        if(can(ca, b)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    
    cout << ans << endl;
}
