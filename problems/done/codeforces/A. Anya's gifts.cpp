// Problem: A. Anya's gifts
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103708/problem/A
// Memory Limit: 256 MB
// Time Limit: 500 ms
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

const int BMAX = 50 + 1;

int n;
int arr[NMAX];
int frq[BMAX];
int basis[BMAX], sz;

void insertVector(int v){
	for(int i = BMAX-1; i >= 0; i--){
		if((v>>i)&1){
			if(!basis[i]){
				basis[i] = v;
				sz++;
				return;
			}
			else{
				v ^= basis[i];
			}
		}
	}	
}

int getMax(){
	
	int v = 0;
	for(int i = BMAX-1; i >= 0; i--){
		if(basis[i]){
			if(!((v>>i)&1)){
				v ^= basis[i];
			}
		}
	}
	
	return v;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	for(int j = 0; j < BMAX; j++){
    		frq[j] += (arr[i]>>j)&1;
    	}
    }
    
    int ans0 = 0;
    for(int i = 0; i < BMAX; i++){
    	if(frq[i] && (frq[i]%2==1)){
    		ans0 |= 1ll << i;
    	}
    }
    
    for(int i = 0; i < n; i++){
    	arr[i] &= ~ans0;
    	insertVector(arr[i]);
    }
    
    int ans1 = getMax();
    
    int ans = ans0 + ans1*2;
    cout << ans << endl;
    
}

/*

	arr = a + b
	ans = max(xor(a) + xor(b))
	ans = max(xor(a) + xor(arr)^xor(a))
	st_path = xor(a), nd_path = xor(arr)^xor(a)
	
	for all bits that occure odd number of times in arr:
		at can only add it to the answer for one time,
		let it be b, then:
			xor(arr)[b] = 1
			now if xor(a)[b] = 1 -> nd_path[b] = 0
			or  if xor(a)[b] = 0 -> nd_path[b] = 1
			
	so now let define ans0 as a number where all bits that occure odd 
	number of time in arr, will be set on.
	
	now we will turn off all ans0 bits on all arr's elements,
	
	now we have a new array with only even-occured-bits are set on,
	now for a bit b that occure even times:
		then if xor(a)[b] = 1 -> nd_path[b] = 1
		or   if xor(a)[b] = 0 -> nd_path[b] = 0
		because xor(arr)[b] = 0;
	so if we can set the bth bit to one, we will add it 2 times to the answer,
	other than that we cann't add it the answer.
	
	so we are looking for a subset of the new array that have 
	that have the maximum xor, lets its xor be ans1;
	
	then ans = ans0 + ans1*2;
	
*/
