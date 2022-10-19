// Problem: C - XX to XXX
// Contest: AtCoder - AtCoder Beginner Contest 259
// URL: https://atcoder.jp/contests/abc259/tasks/abc259_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
    
    string str_a, str_b;
    cin >> str_a >> str_b;
    
    swap(str_a, str_b);
    
    reverse(str_a.begin(), str_a.end());
    reverse(str_b.begin(), str_b.end());
    
    bool ans = true;
    
    while(!str_a.empty() && !str_b.empty()){
    	
    	if(str_a.back() != str_b.back()){
    		ans = false;
    		break;
    	}
    	
    	int cnt_a = 0;
    	for(int i = str_a.size()-1; i >= 0; i--){
    		if(str_a[i] != str_a.back()) break;
    		cnt_a++;
    	}
    	
    	int cnt_b = 0;
    	for(int i = str_b.size()-1; i >= 0; i--){
    		if(str_b[i] != str_b.back()) break;
    		cnt_b++;
    	}
    	
    	bool b0 = cnt_b > cnt_a;
    	bool b1 = (cnt_b == 1) && (cnt_a > cnt_b);
    	
    	while(cnt_a--) str_a.pop_back();
    	while(cnt_b--) str_b.pop_back();
    	
    	if(b0 || b1){
    		ans = false;
    		break;
    	}
    }
    
    ans &= str_a.empty() && str_b.empty();
    
    cout << (ans ? "Yes" : "No") << endl;
}
