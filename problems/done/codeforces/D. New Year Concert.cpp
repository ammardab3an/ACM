// Problem: D. New Year Concert
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1632/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

struct sparse_table{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table(){};
    
    sparse_table(int n, vector<int> arr){
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = arr[i];
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
        	st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        return __gcd(st[l][j], st[r-(1<<j)+1][j]);
    }
    
};



int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    
    int n;
    cin >> n;
    
    vi _vec(n);
    for(auto &i : _vec) cin >> i;
    
    sparse_table st(n, _vec);
    
    vpii vec;
    for(int i = 0; i < n; i++){
    	
    	int l = i;
    	int r = n-1;
    	
    	int ans = -1;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		int g = st.query_range(i, mid);
    		
    		if(g == (mid-i+1)){
    			ans = mid;
    			break;
    		}
    		
    		if(g < (mid-i+1)){
    			r = mid-1;
    		}
    		else{
    			l = mid+1;
    		}
    	}
    	
    	if(ans != -1){
    		vec.push_back({ans, i});
    	}
    }
    
    sort(vec.begin(), vec.end());
    
    int cnt = 0;
    int lst = -1;
    
    vi ans(n);
    
    for(auto p : vec){
    	
    	int i = p.second;
    	int j = p.first;
    	
    	if(lst < i){
    		cnt++;
    		lst = j;
    	}	
    	
    	ans[j] = max(ans[j], cnt);
    }
    
    for(int i = 1; i < n; i++){
    	ans[i] = max(ans[i], ans[i-1]);
    }
    
    for(auto i : ans){
    	cout << i << ' ';
    }
}
