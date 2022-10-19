// Problem: C. Recover an RBS
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/C
// Memory Limit: 256 MB
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

bool good(string str){
	
	int sm = 0;
	for(auto c : str){
		sm += c=='(' ? +1 : -1;
		if(sm < 0) return 0;
	}
	
	return sm==0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		string str;
		cin >> str;
		
		int n = str.size();
		
		vi cnt(2);
		for(auto c : str){
			if(c=='('){
				cnt[0]++;
			}
			else if(c==')'){
				cnt[1]++;
			}
		}
		
		vi _cnt(2);
		_cnt[0] = n/2 - cnt[0];
		_cnt[1] = n/2 - cnt[1];
		
		int p_0 = n;
		int p_1 = -1;
		
		for(int i = 0; i < n && _cnt[0]; i++){
			if(str[i]=='?'){
				str[i] = '(';
				_cnt[0]--;
				p_0 = i;
			}	
		}
		
		for(int i = n-1; i >= 0 && _cnt[1]; i--){
			if(str[i]=='?'){
				str[i] = ')';
				_cnt[1]--;
				p_1 = i;
			}
		}
		
		assert(good(str));
		
		bool ans = true;
		
		if(p_0 != n && p_1 != -1){
			swap(str[p_0], str[p_1]);
			ans &= !good(str);
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
