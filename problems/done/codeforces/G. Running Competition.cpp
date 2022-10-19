// Problem: G. Running Competition
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1398/problem/G
// Memory Limit: 512 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

using cd = complex<double>;

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
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
    
    int n, w, h;
    cin >> n >> w >> h;
    
    n++;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    int deg_res = 2*w;
    int res_sz = deg_res+1;
    res_sz = 1 << int(ceil(log2(double(res_sz))));
    
    vector<cd> a(res_sz), b(res_sz);
    for(int i = 0; i < n; i++){
    	a[vec[i]] = 1;
    	b[w-vec[i]] = 1;
    }
    
    fft(a, false);
    fft(b, false);
    for(int i = 0; i < res_sz; i++){
    	a[i] *= b[i];
    }
    fft(a, true);
    
    for(auto &e : a){
    	e = (int)round(e.real());
    }
    
    int q; cin >> q; while(q--){
    	
    	int x;
    	cin >> x;
    	
    	x /= 2;
    	
    	vi factors;
    	for(int i = 1; i*i <= x; i++) if(x%i==0){
    		factors.push_back(i);
    		if(x/i != i) factors.push_back(x/i);
    	}
    	
    	sort(factors.begin(), factors.end());
    	reverse(factors.begin(), factors.end());
    	
    	int ans = -1;
    	
    	for(auto f : factors){
    		
    		if(f-h <= 0) break;
    		if((f-h)+w >= res_sz) continue;
    		
    		if((int)a[(f-h)+w].real()){
    			ans = 2*f;
    			break;
    		}
    	}
    	
    	cout << ans << ' ';
    }
}
