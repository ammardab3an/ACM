// Problem: Shift The String
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/TASHIFT
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

vector<int> computePrefix(string pat){
	
	int sz = pat.size();
	
	vector<int> longestPrefix(sz);
	
	for(int i = 1, k = 0; i < sz; i++){
	
		while(k > 0 && pat[k] != pat[i])
			k = longestPrefix[k-1];
	
		if(pat[k] == pat[i]) 
			longestPrefix[i] = ++k;
		else
			longestPrefix[i] = k;
	}
	
	return longestPrefix;
}

int KMP(string str, string pat){
	
	int ret_sz = 0;
	int ret_pos = 0;
	
	int szStr = str.size();
	int szPat = pat.size();
	
	vector<int> longestPrefix = computePrefix(pat);
	
	for(int i = 0, k = 0; i < szStr; i++){
	
		while(k > 0 && pat[k] != str[i]){
			
			if(k > ret_sz){
				ret_sz = k;
				ret_pos = i-k;
			}
			
			k = longestPrefix[k-1];
		}
		
		if(pat[k] == str[i])
			k++;
			
		if(k == szPat){
			return i-szPat+1;
			k = longestPrefix[k-1];
		}
	}
	
	return ret_pos;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    string a, b;
    cin >> a >> b;
    
    int ans = KMP(b+b, a);
    
    cout << ans << endl;
}
