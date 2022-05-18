// Problem: E. Breaking the Wall
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/E
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
    
    int ans = INF;
    
    {
    	int mn0 = INF;
    	int mn1 = INF;
    	
    	for(auto i : vec){
    		if(i <= mn0){
    			mn1 = mn0;
    			mn0 = i;
    		}
    		else if(i <= mn1){
    			mn1 = i;
    		}
    	}	
    	
    	ans = min(ans, (mn0+1)/2 + (mn1+1)/2);
    }
    
    {
    	for(int i = 1; i+1 < n; i++){
    		
    		int l = vec[i-1];
    		int r = vec[i+1];
    		
    		if(l > r) swap(l, r);
    		
    		int cans = l + (r-l+1)/2;
    		
    		ans = min(ans, cans);		
    	}
    }
    
    {
    	for(int i = 1; i < n; i++){
    		
    		int l = vec[i-1];
    		int r = vec[i];
    		
    		if(l > r) swap(l, r);
    		
    		int cans = (r+1)/2;
    		l = max(l-cans, int(0));
    		cans += (l+1)/2;
    		
    		ans = min(ans, cans);
    	}	
    }
    
    {
    	for(int i = 1; i < n; i++){
    		
    		int l = vec[i-1];
    		int r = vec[i];
    		
    		int cans = 0;
    		
    		if(l%2==1 && r >= 2){
    			cans ++;
    			r -= 2;
    			l -= 1;
    		}
    		
    		if(r%2==1 && l >= 2){
    			cans ++;
    			r -= 1;
    			l -= 2;
    		}
    		
    		if(l > r) swap(l, r);
    		
    		if(l==0){
    			ans = min(ans, cans + (r+1)/2);
    			continue;
    		}
    		
    		if(l==r && l==1){
    			ans = min(ans, cans + (int)1);
    			continue;
    		}
    		
    		l /= 2;
    		r /= 2;
    		
    		int dif = r-l;
    		
    		int mn = min(dif, min(r/2, l));
    		cans += mn*2;
    		r -= mn*2;
    		l -= mn;
    		
    		mn = min(r/3, l/3);
    		cans += mn*4;
    		r -= mn*3;
    		l -= mn*3;
    		
    		mn = min(r/2, l);
    		cans += mn*2;
    		r -= mn*2;
    		l -= mn;
    		
    		cans += r+l;
    		
    		ans = min(ans, cans);
    	}	
    }
    
    cout << ans << endl;
}
