// Problem: Array Transform
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/ARRAYTRM
// Memory Limit: 256 MB
// Time Limit: 423 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		map<int, int> mp;
		
		vi vec(n);
		for(auto &i : vec){
			cin >> i;
			mp[i%(k+1)]++;	
		}
		
		bool ans = false;
		
		for(auto p : mp){
			if(p.second >= n-1){
				ans = true;
				break;
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}

/*

	let m be the total number of operation done to the array to transform all elements into zeros, then for each element there is a combination of operations (-1, +k) of size m that makes that element equal to zero:
	
	A[i] = a*k -b
	where a+b = m
	=> b = m-a
	=> A[i] = a*k -(m-a) = a*k - m + a = a(k+1)-m
	=> a = (m+A[i])/(k+1)
	
	then (m+A[i]) have to me a multiple of (k+1), so we simple have to find (n-1) elements with the same %(k+1) value.

*/