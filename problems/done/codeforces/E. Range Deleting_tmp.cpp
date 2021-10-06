// Problem: E. Range Deleting
// Contest: Codeforces - Educational Codeforces Round 65 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1167/E
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
    
    int n, x;
    cin >> n >> x;
    
    vector<int> vec(n);
    for(auto &i : vec) cin >> i;
    
    int pre = 0, suf = x+1;
	
	for(auto k : {1, -1})
    {
		set<pii> st, cur;
		for(int i = 0; i < n; i++){
			st.insert({k * vec[i], i});
		}
    	
    	int llst = 0;
    	int lst = 0;
    	
    	while(st.size()){
    		
    		pii tmp = *st.begin();
    		st.erase(st.begin());
    		tmp.first *= k;
    		
    		bool good = true;
    		
    		if(cur.size()){
	    		auto it = cur.lower_bound({tmp.second, 0});
	    		good &= it->second >= tmp.first;
    			if(good && it != cur.begin()){
    				good &= (--it)->second <= tmp.first;
    			}
    		}
    		
    		if(!good){
    			if(tmp.first == lst){
    				k==1 ? pre = llst : suf = llst;		
    			}
    			else{			
		    		k==1 ? pre = cur.begin()->second : suf = cur.begin()->second;
    			}
    			break;
    		}
    		
    		cur.insert({tmp.second, tmp.first});
    		
    		if(lst != tmp.first){
    			llst = lst;
    			lst = tmp.first;
    		}
    		
    		// cout << tmp.first << ' ' << tmp.second << endl;
    		// for(auto p : cur){
    			// cout << p.first << ' ' << p.second << endl;
    		// }
    		// cout << endl;
    	}
    }
    
    cout << pre << ' ' << suf << endl;
    
    vector<int> mx(n);
    
    mx[0] = vec[0];
    for(int i = 1; i < n; i++) 
    	mx[i] = max(mx[i-1], vec[i]);
    
    set<pii> st;
    for(int i = 0; i < n; i++){
    	st.insert({vec[i], -i});
    }
    
    int ans = 0;
    
    for(int l = 1; l <= pre; l++){
    	
    	int lst = -1;
    	auto it = st.lower_bound({l, -INF});
    	if((it->first) == l){
    		lst = -1 * (it->second);
    	}
    	
    	int cmx = lst >= 0 ? mx[lst] : 0;
    	
    	cout << ' ' << lst << ' ' << cmx << endl;
    	
    	int r = max(cmx, suf);
    	ans += (x-r+1);
    	
    	cout << l << ' ' << r << endl;
    }
    
    cout << ans << endl;
}
