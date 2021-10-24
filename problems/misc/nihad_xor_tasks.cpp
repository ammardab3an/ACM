
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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

int calc(int r){
    
    int ans = 0;
    while((r >= 0) && (r%4 != 3)){
        ans ^= r;
        r--;
    }    
    return ans;
}

int calc(int l, int r){
    int ans = calc(r);
    if(l) ans ^= calc(l-1);    
    return ans;
}

int _go0(int n, int x, int y){
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans ^= (x+i)*y;
    }
    return ans;
}

int go0(int n, int x, int y){
    return y * calc(x, x+n);
}

int _go1(int n, int x, int y){
    
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans ^= x+i*y;
    }    
    return ans;
}

int go1(int n, int x, int y){
    int nx = x / y;
    int s1 = n%2==0 ? ((y-1)&x) : 0;
    int s2 = calc(nx, nx+n);
    return s1 + y * s2;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int k, n, x, y;
        cin >> k >> n >> x >> y;
        
        if(k == 1){
            cout << go0(n, x, y) << ' ' << _go0(n, x, y) << endl;
        }
        else{
            cout << go1(n, x, y) << ' ' << _go1(n, x, y) << endl;
        }
    }	
    
}

/*
خواص للxor:
🔴 x^y=z => x^z=y
🔴 x^y=y^x
🔴 x^x=0
🔴 الxor لأي أربع أرقام متتالية وكان أول رقم زوجي هو صفر
0^1^2^3=0
2^3^4^5=0

بالتالي اذا بدنا نعرف الxor التراكمي من 0 لn بكفي نمشي حلقة من
n-n%4    ->   n
يعني الحلقة بالكتير بتمشي 3 عناصر

🔴 الxor التراكمي من l ل r منحسبو عن طريق
xor(l, r) = xor(0, r) ^ xor(0, l-1)

some tasks:

task_1 : calc (x*y)^((x+1)*y)^...^((x+n)*y)
if y=pow(2,m)

task_2 : calc x^(x+y)^(x+2y)^...^(x+ny)
if y=pow(2,m)

بينحلو بالاستفادة من الافكار يلي فوق مع التفكر اكتر
*/