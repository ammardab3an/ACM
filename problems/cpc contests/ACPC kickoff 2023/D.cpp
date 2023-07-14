
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
    
    int n;
    cin >> n;
    
    int x0, y0;
    cin >> x0 >> y0;
    
    map<int, vi> mp_i;
    map<int, vi> mp_j;
    
    vector<pii> pnts(n);
    for(int i = 0; i < n; i++){
    	auto &[x, y] = pnts[i];
    	cin >> x >> y;
    	mp_i[x].push_back(y);
    	mp_j[y].push_back(x);
    }
    
    for(auto &[k, v] : mp_i){
    	sort(v.begin(), v.end());
    }
    for(auto &[k, v] : mp_j){
    	sort(v.begin(), v.end());
    }
    
    int m; cin >> m; while(m--){
    	
    	char c;
    	cin >> c;
    	
    	if(c=='R'){
    		auto &v = mp_j[y0];
    		auto it = upper_bound(v.begin(), v.end(), x0);
    		if(it!=v.end()){
    			x0 = *it;
    		}
    	}
    	else if(c=='L'){
    		auto &v = mp_j[y0];
    		auto it = lower_bound(v.begin(), v.end(), x0);
			if(!v.empty() && it!=v.begin()){
				it--;
				x0 = *it;
			}
    	}
    	else if(c=='U'){
    		auto &v = mp_i[x0];
    		auto it = upper_bound(v.begin(), v.end(), y0);
    		if(it!=v.end()){
    			y0 = *it;
    		}
    	}
    	else if(c=='D'){
    		auto &v = mp_i[x0];
    		auto it = lower_bound(v.begin(), v.end(), y0);
			if(!v.empty() && it!=v.begin()){
				it--;
				y0 = *it;
			}
    	}
    	
    	cout << x0 << ' ' << y0 << endl;
    }
}
