// Problem: D. Make a Power of Two
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/D
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

int match(const string &a, const string &b){
    
    int n = a.size();
    int m = b.size();
    
    int i = 0;
    for(int j = 0; j < n && i < m; j++){
        if(a[j] == b[i]){
            i++;
        }
    }
    
    if(i == m) return n-m;
    
    return n-i + m-i;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    vector<string> vec;
    for(int i = 0; i < 61; i++){
        string str;
        int num = 1ll << i;
        while(num) str.push_back('0' + num%10), num /= 10;
        reverse(str.begin(), str.end());
        vec.push_back(str);
        // cout << str << endl;
    }
    
    // cout << match("687194767", "268435456") << endl;
    
    int t; cin >> t; while(t--){

        string num;
        cin >> num;
        
        int ans = 1e3;
        
        for(auto &str : vec){
            ans = min(ans, match(num, str));
        }
        
        cout << ans << endl;
    }	
}
