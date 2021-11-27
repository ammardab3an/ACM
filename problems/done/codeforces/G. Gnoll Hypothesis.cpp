// Problem: G. Gnoll Hypothesis
// Contest: Codeforces - 2019-2020 ICPC Northwestern European Regional Programming Contest (NWERC 2019)
// URL: https://codeforces.com/gym/102500/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

vi primes = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
    307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
    401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499
};

bool vis[555];
double mem[555];

double calc(int x, int n, int k){
        
    if(vis[x]){
        return mem[x];
    }
    vis[x] = true; 
    
    vi tmp_0;
    vi tmp_1;
    
    tmp_0.push_back(k);
    tmp_0.push_back(k-1);
    
    int a = n-x-2;
    int b = n-x-2 - (k-2) +1;
    
    for(int i = b; i <= a; i++){
        tmp_0.push_back(i);
    }
    
    int c = n;
    int d = n-k+1;
    
    for(int i = d; i <= c; i++){
        tmp_1.push_back(i);
    }
    
    double ret = 1;
    
    for(auto p : primes){
        
        int cnt_0 = 0;
        int cnt_1 = 0;
        
        for(auto &i : tmp_0){
            while(i && i%p==0) cnt_0++, i/=p;
        }
        
        for(auto &i : tmp_1){
            while(i && i%p==0) cnt_1++, i/=p;
        }
        
        int mn = min(cnt_0, cnt_1);
        cnt_0 -= mn, cnt_1 -= mn;
        
        while(cnt_0--) ret *= p;
        while(cnt_1--) ret /= p;
    }
    
    return mem[x] = ret;
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
    
    vector<double> vec(n);
    for(auto &d : vec) cin >> d;
    
    cout << fixed << setprecision(10);
    
    if(k==1){
        double t = (double)100.0/n;
        for(int i = 0; i < n; i++){
            cout << t << ' ' ;
        }    
        cout << endl;
        return 0;
    }
    
    vector<double> pre(n);
    pre[0] = vec[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + vec[i];
    }
    
    vector<double> ans(n);
    
    for(int i = 0; i < n; i++)
    for(int x = 0; (n-2-x) >= (k-2); x++){
        
        int j = (i-x-1+n)%n;    
        
        double sm = 0;
        
        if(j < i){
            sm = pre[i];
            sm -= pre[j];
        }
        else{
            sm = pre[n-1];
            sm -= pre[j];
            sm += pre[i];
        }
        
        ans[i] += sm * calc(x, n, k);    
    }    
    
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}