// Problem: F. Four Column Hanoi Tower
// Contest: Codeforces - 2021 Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103366/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

string big_add(const string &a, const string &b){
    
    string res;
    
    int car = 0;
    
    int i = a.size()-1, j = b.size()-1;
    
    for(; i >= 0 && j >= 0; i--, j--){
        
        int cur = (a[i]-'0')+(b[j]-'0')+car;
        car = cur/10;
        cur = cur%10;
        
        res.push_back('0' + cur);
    }
    
    while(i >= 0){
        
        int cur = (a[i--]-'0')+car;
        car = cur/10;
        cur = cur%10;
        
        res.push_back('0' + cur);
    }
    
    while(j >= 0){
        
        int cur = (b[j--]-'0')+car;
        car = cur/10;
        cur = cur%10;
        
        res.push_back('0' + cur);
    }
    
    res.push_back('0' + car);
    
    while(res.size() > 1 && res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    
    return res;
}


string big_mul(const string &a, int b){
    
    string res;
    
    int car = 0;
    for(int i = a.size()-1; i >= 0; i--){
        
        int cur = (a[i]-'0')*b+car;
        car = cur/10;
        cur = cur%10;
        
        res.push_back('0' + cur);
    }
    
    res.push_back('0' + car);
    
    while(res.size() > 1 && res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    
    return res;
}

string mem[10000 + 10];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string ans = "0";
    string tmp = "1";
    
    for ( ll ind=1, i=1 ; ind <= 10000; i ++ ){
        for ( ll  j=0 ; j < i && ind <= 10000; j ++ ){
            ans = big_add(ans, tmp);
            mem[ind] = ans;
            ind ++ ;
        }
        tmp = big_mul(tmp, 2);
    }
    
    int t; cin >> t; while(t--){
        int n;
        cin >> n;
        cout << mem[n] << endl;
    }	
}
