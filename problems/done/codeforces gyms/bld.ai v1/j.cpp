
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, a;
    cin >> n >> a;
    
    int m, b;
    cin >> m >> b;
    
    auto get_pos = [&](int pos, bool debug = false)->int{
    	
    	int l = 0;
    	int r = max(n*a, m*b) + 10;
    	
    	int ans = 0;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		int cnt0 = mid/a - (mid>0 && (mid%a==0));
    		int cnt1 = mid/b - (mid>0 && (mid%b==0));
    		
    		cnt0 = min(cnt0, n);
    		cnt1 = min(cnt1, m);
    		
    		int cnt = cnt0+cnt1;
    		
    		if(debug){
    			cout << l << ' ' << r << endl;
    			cout << mid << ' ' << cnt0 << ' ' << cnt1 << ' ' << ans << endl;
    		}
    		
    		if(cnt <= pos){
    			ans = mid;
    			l = mid+1;
    		}
    		else{
    			r = mid-1;
    		}
    	}	
    	
    	return ans;
    };
    
    // get_pos(n+m-1, true);
    // for(int i = 0; i < n+m; i++){
    	// cout << get_pos(i) << ' '; 
    // }
    // cout << endl;
    
    if((n+m)%2==1){
    	int ans = get_pos((n+m)/2);
    	cout << ans << ".0" << endl;
    }
    else{
    	int ans0 = get_pos((n+m)/2);
    	int ans1 = get_pos((n+m)/2-1);
    	// cout << ans0 << ' ' << ans1 << endl;
    	double ans = double(ans0+ans1) / double(2);
    	cout << fixed << setprecision(1) << ans << endl;
    }
}
