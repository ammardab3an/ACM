// Problem: E. Prefix Function Queries
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1721/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
 
 
const int NMAX = 1e6 + 10;

string s;
int pi[NMAX];
int mem[NMAX][26];

void prefix_function() {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

int go(int i, char c){
		
	int &ret = mem[i][c-'a'];
	if(ret+1) return ret;
	
	int j = i;
	while(j && s[j] != c){
		j = go(pi[j-1], c);
	}
	
	return ret = j;
}

void prefix_function2(const string &t) {
	
    for (int i = s.size(); i < s.size()+t.size(); i++) {
    	
        int j = pi[i-1];
        
        while (j > 0 && t[i-s.size()] != (j < s.size() ? s[j] : t[j-s.size()])){
        	
        	if(j < s.size()){
        		j = go(j, t[i-s.size()]);
        	}
        	else{    		
	            j = pi[j-1];
        	}
        }
        
        if (t[i-s.size()] == (j < s.size() ? s[j] : t[j-s.size()]))
            j++;
            
        pi[i] = j;
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> s;
    prefix_function();
    
    memset(mem, -1, sizeof mem);
    
    int t; cin >> t; while(t--){
    	
    	string t;
    	cin >> t;
    	
    	prefix_function2(t);
    	
    	for(int i = 0; i < t.size(); i++){
    		cout << pi[s.size()+i] << ' ';
    	}
    	cout << endl;
    }
}
