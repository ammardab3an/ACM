// Problem: E. Thief in a Shop
// Contest: Codeforces - Educational Codeforces Round 9
// URL: https://codeforces.com/contest/632/problem/E
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

typedef complex<double> cd;

void fft(vector<cd> & a, bool invert) {
	
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

void mul_fft(vector<cd> &A, vector<cd> B){
	
	int res_sz = A.size() + B.size() -1;
	res_sz = 1 << int(ceil(log2(double(res_sz))));
	
	A.resize(res_sz);
	B.resize(res_sz);
	
	fft(A, false);
	fft(B, false);
	for(int i = 0; i < res_sz; i++){
		A[i] *= B[i];
	}
	fft(A, true);
	
	for(auto &i : A){
		if(round(i.real()) > 0){
			i = 1;
		}
		else{
			i = 0;
		}
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    vector<cd> pol(1010);
    for(int i = 0; i < n; i++){
    	int ai;
    	cin >> ai;
    	pol[ai] = 1;
    }
    
    vector<cd> cur(1010);
    cur[0] = 1;
    
    while(k){
    	if(k&1) mul_fft(cur, pol);
    	mul_fft(pol, pol);
    	k /= 2;	
    }
    
    for(int i = 1; i < cur.size(); i++) if(round(cur[i].real()) > 0){
    	cout << i << ' ';
    }
    cout << endl;
}
