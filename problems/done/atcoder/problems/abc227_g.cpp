// Problem: G - Divisors of Binomial Coefficient
// Contest: AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest 227)
// URL: https://atcoder.jp/contests/abc227/tasks/abc227_g
// Memory Limit: 1024 MB
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

const int PMAX = 1e6 + 10;

vi primes;
bool not_prime[PMAX];

void sieve_init(){

    primes.push_back(2);
    for(int i = 4; i < PMAX; i+=2){
        not_prime[i] = true;
    }   
    
    for(int i = 3; i < PMAX; i+=2) if(!not_prime[i]){
        primes.push_back(i);
        for(int j = i*i; j < PMAX; j+=i){
            not_prime[j] = true;
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
    
    sieve_init();
    map<int, int> div;
    
    vi vec(k+1);
    iota(vec.begin(), vec.end(), 0);
    
    for(auto p : primes){
        
        for(int i = p; i <= k; i+=p){
            
            while(vec[i]%p==0){
                vec[i] /= p;
                div[p]--;
            }
        }
    }
    
    vec.resize(k);
    for(int i = 0; i < k; i++){
        vec[i] = n-k+1+i;
    }
    
    for(auto p : primes){
        
        // x*p >= n-k+1
        // x >= (n-k+1)/p
        for(int i = p * ((n-k+1+(p-1))/p); i <= n; i+=p){
            
            while(vec[i-(n-k+1)]%p==0){
                vec[i-(n-k+1)] /= p;
                div[p]++;
            }
        }
    }
    
    for(int i = 0; i < k; i++) if(vec[i] != 1){
        div[vec[i]]++;    
    }
    
    int ans = 1;
    int mod = 998244353;
    for(auto p : div) if(p.second > 0){
        ans = (ans * (p.second+1)) % mod;
    }
    
    cout << ans << endl;
}
