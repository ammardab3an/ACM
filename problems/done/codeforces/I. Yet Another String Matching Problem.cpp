// Problem: I. Yet Another String Matching Problem
// Contest: Codeforces - Educational Codeforces Round 40 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/954/I
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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


using cd = complex<double>;

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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string a, b;
    cin >> a >> b;
    
    int n = a.size();
    int m = b.size();
    
    reverse(b.begin(), b.end());
    
    vector<vector<vi>> tot(6, vector<vi>(6, vi(n-m+1)));
    
    for(int c0 = 0; c0 < 6; c0++)
    for(int c1 = c0; c1 < 6; c1++){
    	
	    int deg_a = n-1;
	    int deg_b = m-1;
	    int deg_res = deg_a + deg_b;
	    int sz_res = deg_res+1;
	    
	    sz_res = 1 << int(ceil(log2(double(sz_res))));
	    
	    vector<cd> A(sz_res), B(sz_res);
	    
	    for(int i = 0; i < n; i++){
	    	A[i] = (a[i]-'a'==c0) || (a[i]-'a'==c1);
	    }
	    for(int i = 0; i < m; i++){
	    	B[i] = (b[i]-'a'==c1) || (b[i]-'a'==c0);
	    }
	    
	    fft(A, false);
	    fft(B, false);
	    for(int i = 0; i < sz_res; i++){
	    	A[i] *= B[i];
	    }
	    fft(A, true);
	    
	    for(int i = 0; i+m-1 < n; i++){
	    	tot[c0][c1][i] += round(A[i+m-1].real());
	    }
    }
    
    for(int i = 0; i+m-1 < n; i++){
    	
    	vi par(6);
    	iota(par.begin(), par.end(), 0);
    	
    	for(int c0 = 5; c0 >= 0; c0--)
	    for(int c1 = c0+1; c1 < 6; c1++){
	    	if(tot[c0][c1][i] - tot[c0][c0][i] - tot[c1][c1][i]){
	    		int u = c1;
	    		while(par[u] != u) u = par[u];
	    		par[u] = c0;
	    	}
	    }
	    
	    vi vis(6);
	    int cans = 6;
	    for(int u = 0; u < 6; u++){
	    	int cur = u;
	    	while(par[cur] != cur){
	    		cur = par[cur];
	    	}
	    	cans -= !vis[cur];
	    	vis[cur] = true;
	    }
	    
	    cout << cans << ' ';
    }
}
