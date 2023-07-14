
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
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi pos, neg;
    int cnt_zeros = 0;
    
    for(auto i : vec){
    	if(i > 0){
    		pos.push_back(i);
    	}
    	else if(i < 0){
    		neg.push_back(i);
    	}
    	else{
    		cnt_zeros++;
    	}
    }
    
    if(cnt_zeros && (n-cnt_zeros) < m){
    	cout << 0 << endl;
    	return 0;
    }
    
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    reverse(neg.begin(), neg.end());
    
    if(!k && pos.empty() && m%2==1){
    	
    	int ans = 1;
    	for(int i = 0; i < m; i++){
    		ans = mul(ans, neg[i]);
    	}
    	
    	cout << ans << endl;
    	return 0;
    }
    
    
    vi tmp = pos;
    for(auto i : neg) tmp.push_back(i);
    
    sort(tmp.begin(), tmp.end(), [&](int i, int j){
    	return abs(i) > abs(j);
    });
    
    int ml = 1;
    
    int cnt_ng = 0;
    vi lst_pos, lst_neg;
    for(int i = 0; i < m; i++){
    	
    	ml = mul(ml, abs(tmp[i]));	
    	
    	if(tmp[i] < 0) cnt_ng++;
    	
    	if(tmp[i] > 0) lst_pos.push_back(tmp[i]);
    	else lst_neg.push_back(tmp[i]);
    }
    
    if(!lst_pos.empty()){
    	lst_pos = {lst_pos.back()};
    }
    if(!lst_neg.empty()){
    	lst_neg = {lst_neg.back()};
    }
    
    if(cnt_ng%2==1){
    	
    	if(!k){
    		
    		vi nxt_pos, nxt_neg;
    		for(int i = m; i < tmp.size(); i++){
    			if(tmp[i] > 0 && nxt_pos.empty()){
    				nxt_pos.push_back(tmp[i]);
    			}
    			else if(tmp[i] < 0 && nxt_neg.empty()){
    				nxt_neg.push_back(tmp[i]);
    			}
    		}
    		
    		double st_path = 0;
    		double nd_path = 0;
    		int st_path_val = 0;
    		int nd_path_val = 0;
    		
    		if(!lst_pos.empty() && !nxt_neg.empty()){
    			
    			int a = lst_pos.back();
    			int b = nxt_neg.back();
    			
    			// cout << a << ' ' << b << endl;
    			
    			st_path = double(abs(b)) / double(a);
    			st_path_val = mul(abs(b), pow_exp(a, MOD-2));
    		}
    		
    		if(!lst_neg.empty() && !nxt_pos.empty()){
    			
    			int a = lst_neg.back();
    			int b = nxt_pos.back();
    			
    			// cout << a << ' ' << b << endl;
    			
    			nd_path = double(b) / double(abs(a));
    			nd_path_val = mul(b, pow_exp(abs(a), MOD-2));
    		}
    		
    		assert(st_path != 0 || nd_path != 0);
    		
    		if(st_path > nd_path){
    			ml = mul(ml, st_path_val);
    		}
    		else{
    			ml = mul(ml, nd_path_val);
    		}
    	}
    }
    
    int ans = ml;
    cout << ans << endl;
}
