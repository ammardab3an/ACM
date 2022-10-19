// Problem: A+B Problem
// Contest: Kattis
// URL: https://open.kattis.com/problems/aplusb
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

const int MX = 5e4 + 10;
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

int test(vi vec){
	
	int ret = 0;
	
	int n = vec.size();
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) if(i != j)
	for(int k = 0; k < n; k++) if(i != k) if(j != k){
		
		ret += (vec[i]+vec[j]) == vec[k];	
	}
	
	return ret;
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
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    // cout << test(vec) << endl;
    
    sort(vec.begin(), vec.end());
    
    map<int, int> mp;
    for(auto i : vec) mp[i]++;
    
    int res_deg = (2*MX)*2;
    int res_sz = res_deg+1;
    res_sz = 1 << int(ceil(log2(double(res_sz))));
    
    vector<cd> a(res_sz);
    
    for(auto i : vec){
    	a[i+MX] += 1;
    }
    
    fft(a, false);
    for(auto &i : a){
    	i *= i;
    }
    fft(a, true);
    
    int ans = 0;
    
    for(int i = 0; i < res_sz; i++){
    	
    	int v = round(a[i].real());
    	int j = i-2*MX;
    	
    	auto it = mp.find(j);
    	if(it==mp.end()) continue;
    	
    	if(j!=0 && j%2==0){
    		auto it = mp.find(j/2);
    		if(it != mp.end()){
    			v -= it->second;		
    		}
    	}
    	
    	// cout << j << ' ' << v << endl;
    	
    	ans += v * (it->second);
    }
    
    int cnt_0 = mp[0];
    
    if(cnt_0){
    	ans -= (n-cnt_0) * cnt_0 * 2;
    	ans -= cnt_0 * cnt_0;
    	ans -= cnt_0 * (cnt_0-1) * 2;
    }
    
    cout << ans << endl;
}
