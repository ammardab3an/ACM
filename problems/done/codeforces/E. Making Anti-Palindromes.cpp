// Problem: E. Making Anti-Palindromes
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/contest/1822/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		string str;
		cin >> str;
		
		if(n%2==1){
			cout << -1 << endl;
			continue;
		}
		
		int sm0 = 0, sm1 = 0;
		vi cnt0(26), cnt1(26);
		
		for(int i = 0; i < n/2; i++){
			
			if(str[i]==str[n-i-1]){
				sm0++;
				cnt0[str[i]-'a']++;	
			}
			else{
				sm1+=2;
				cnt1[str[i]-'a']++;
				cnt1[str[n-i-1]-'a']++;
			}
		}
		
		int mx0 = max_element(cnt0.begin(), cnt0.end())-cnt0.begin();
		
		if(cnt0[mx0]*2 <= sm0){
			cout << (sm0+1)/2 << endl;
		}
		else{
			
			int rm = cnt0[mx0]*2 - sm0;
			int x = sm1/2 - cnt1[mx0];
			
			if(x >= rm){
				cout << rm+(sm0-cnt0[mx0]) << endl;
			}
			else{
				cout << -1 << endl;
			}
		}
    }	
}
