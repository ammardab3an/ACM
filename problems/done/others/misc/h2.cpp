
// By AmmarDab3an 

#include <bits/stdc++.h>

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	
	
	int n;
	cin >> n;
	
	vector<int> vec(n);
	for(auto &e : vec){
		cin >> e;
	}
	
	
	auto check_sorted = [&](vector<int> &vec, int p){
		
		int lst = -1;
		for(int i = 0; i < n; i++) if(i != p){
			if(vec[i] <= lst){
				return false;
			}
			else{
				lst = vec[i];
			}
		}
		
		return true;
	};
	
	int ans = -1;
	for(int i = 0; i < n; i++){
		if(check_sorted(vec, i)){
			if(ans==-1){
				ans = vec[i];
			}
			else{
				ans = min(ans, vec[i]);
			}
		}
	}
	
	cout << ans << endl;
}

/*
Given an array of integers, the task is to remove an element from the 
array to make the array sorted (either ascending or descending).
1.	If the array is sorted already, return the smallest element of the array
2.	If the array is not sorted, 
a)	If removing one of its elements makes it sorted, return this element; 
if multiple solutions exist, return the smallest element of the solutions
b)	If no any solutions, return -1

Input:
1st line: an integer between 2 and 200 (2 and 200 are included) which is the 
length of an array 
2nd line: all elements of the array, each element is in the range of [0.200] 

Output:
An integer returned

Example1:
Input:
3
1 3 5
Output:
1

Example2:
Input:
3
2 1 4
Output:
1

Example3:
Input:
5
2 3 1 5 4
Output:
-1

*/