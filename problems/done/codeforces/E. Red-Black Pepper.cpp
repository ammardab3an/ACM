// Problem: E. Red-Black Pepper
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1728/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int NMAX = 3e5 + 10;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int _lx, _bg;
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
        
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
        
    _lx = lx;
	_bg = b;
    return (rx - lx) / abs(b) + 1;
}

int n;
int arr[2][NMAX];
int sm;
int val[NMAX];
int pre[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[0][i] >> arr[1][i];
    }
    
    for(int i = 0; i < n; i++){
    	sm += arr[1][i];
    	val[i] = arr[0][i]-arr[1][i];
    }
    
    sort(val, val+n);
    reverse(val, val+n);
    pre[0] = val[0];
    for(int i = 1; i < n; i++){
    	pre[i] = pre[i-1] + val[i];
    }
    
    // cout << sm << endl;
    // for(int i = 0; i < n; i++){
    	// cout << val[i] << ' '; 
    // } cout << endl;
    // for(int i = 0; i < n; i++){
    	// cout << sm+pre[i] << ' '; 
    // } cout << endl;
    
    int m; cin >> m; while(m--){
    	
    	int a, b;
    	cin >> a >> b;
    	
    	int cnt = find_all_solutions(a, b, n, 0, n, 0, n);
    	
    	if(!cnt){
    		cout << -1 << endl;
    		continue;
    	}
    	
    	// cout << cnt << ' ' << _lx << ' ' << _bg << endl;
    	// for(int i = 0; i < cnt; i++){
    		// cout << _lx+i*_bg << ' ';
    	// } cout << endl;
    	
    	int l = 0;
    	int r = cnt-1;
    	int ans = -INFLL;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		int x = _lx + mid*_bg;
    		int y = (n-x*a)/b;
    		assert(x*a+y*b == n);
    		
    		int cans = sm;
    		if(x*a) cans += pre[x*a-1];
    		ans = max(ans, cans);
    		
    		if(x*a==0 || val[x*a-1] >= 0){
    			l = mid+1;
    		}
    		else{
    			r = mid-1;
    		}
    	}
    	
    	cout << ans << endl;
    }
}
