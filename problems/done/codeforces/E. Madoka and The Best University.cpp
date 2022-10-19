// Problem: E. Madoka and The Best University
// Contest: Codeforces - Codeforces Round #818 (Div. 2)
// URL: https://codeforces.com/contest/1717/problem/E
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

int lca(int a, int b){
	return a*b/__gcd(a, b);
}

int eulerphi[NMAX];
int primechk[NMAX];

void init(void)
{
    int i, j;
    eulerphi[1]=1;
    for(i=2 ; i<=NMAX ; i++)
    {
        eulerphi[i]=i;
        primechk[i]=1;
    }
    for(i=2 ; i<=NMAX ; i++)
    {
        if(primechk[i]==1)
        {
            eulerphi[i]-=eulerphi[i]/i;
            for(j=2 ; i*j<=NMAX ; j++)
            {
                primechk[i*j]=0;
                eulerphi[i*j]-=eulerphi[i*j]/i;
            }
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
    
    init();
    
    int n;
    cin >> n;
    
    eulerphi[1] = 0;
    
    int ans = 0;
    
    for(int c = 1; c <= n-2; c++){
    	
    	int s = n-c;
    	
    	for(int d = 1; d*d <= s; d++) if(s%d==0){
    		
    		int d1 = d;
    		ans = add(ans, mul(lca(c, d1), eulerphi[s/d1]));
    		
    		if(d != s/d){
	    		int d2 = s/d;
	    		ans = add(ans, mul(lca(c, d2), eulerphi[s/d2]));
    		}
    	}
    }
    
    cout << ans << endl;
}


/*
a+b+c = n
lca(c, gcd(a, b))

gcd(a, b) = gcd(a, a+b) = gcd(a, n-c)

gcd(a, b) is a factor of n-c,

d = gcd(a, b)
a = a/d
b = b/d

d(a+b) = n-c
a+b = (n-c)/d

count the number of (a, b) where a and b ar coprimes

if a is a coprime with (n-c)/d
then a is a coprime with b

note that if d==n-c
then when we say : d(a+b), a or b must be equal to zero
then its not a valid answer, so we say phi[1] = 0 instead of 1,

*/