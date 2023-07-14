// Problem: D. Remove Two Letters
// Contest: Codeforces - Codeforces Round 855 (Div. 3)
// URL: https://codeforces.com/contest/1800/problem/D
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	auto is_prime = [](int x){
		for(int i = 2; i*i <= x; i++) if(x%i==0){
			return false;
		}
		return true;
	};
	
	array<int, 2> p = {rand(1e9, 2e9), rand(1e9, 2e9)};
	array<int, 2> m = {29, 31};
	
	for(int i = 0; i < 2; i++){
		while(!is_prime(p[i])) p[i]++;
	}

    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		string str;
		cin >> str;		
		
		vector<array<int, 2>> pre(n), suf(n), pow_m(n);
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < 2; j++){
			if(i){
				pow_m[i][j] = (pow_m[i-1][j] * m[j])%p[j];
			}
			else{
				pow_m[i][j] = 1;
			}
		}
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < 2; j++){
			if(i){
				pre[i][j] = (pre[i-1][j]*m[j] + (str[i]-'a'+1)) % p[j];
			}
			else{
				pre[i][j] = (str[i]-'a'+1) % p[j];
			}
		}
		
		for(int i = n-1; i >= 0; i--)
		for(int j = 0; j < 2; j++){
			if(i+1 < n){
				suf[i][j] = (suf[i+1][j] + (str[i]-'a'+1)*pow_m[n-i-1][j]) % p[j];
			}	
			else{
				suf[i][j] = (str[i]-'a'+1)%p[j];
			}
		}
		
		set<array<int, 2>> st;
		
		for(int i = 0; i+1 < n; i++){
			
			array<int, 2> hash;
			
			if(i){
				hash = pre[i-1];
				if(i+2 < n){
					for(int j = 0; j < 2; j++){
						hash[j] = (hash[j] * pow_m[n-(i+2)][j]) % p[j];
						hash[j] = (hash[j] + suf[i+2][j]) % p[j];
					}
				}	
			}
			else{
				hash = suf[i+2];
			}
			
			st.insert(hash);
		}
		
		cout << st.size() << endl;
    }	
}
