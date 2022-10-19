// Problem: D. Rorororobot
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/D
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct sparse_table{
    
    vi arr;
    vector<int> lg2;
    vector<vi> st;
    
    sparse_table(){};
    
    sparse_table(int n, vi _arr){
        
        arr = _arr;
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = i;
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            if(arr[st[i][j-1]] > arr[st[i+(1<<(j-1))][j-1]]){
                st[i][j] = st[i][j-1];
            }
            else{
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        if(arr[st[l][j]] > arr[st[r-(1<<j)+1][j]]){
            return st[l][j];
        }
        else{
            return st[r-(1<<j)+1][j];
        }
    }
    
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi vec(m);
    for(auto &i : vec) cin >> i;
    
    sparse_table st(m, vec);
    
    int q;
    cin >> q;
    
    while(q--){
    	
    	int x0, y0, x1, y1, k;
    	cin >> x0 >> y0 >> x1 >> y1 >> k;
    	
    	if(x0 <= vec[y0-1] || x1 <= vec[y1-1] || abs(x0-x1)%k!=0 || abs(y0-y1)%k!=0){
    		cout << "NO" << endl;
    		continue;
    	}
    	
    	int mx_p = st.query_range(min(y0, y1)-1, max(y0, y1)-1);
    	int mx = vec[mx_p];
    	
    	int x = max(x0, x1);
    	
    	int l = 0;
    	int r = INF;
    	
    	int bs_ans = r+1;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		if((x+mid*k) > mx){
    			bs_ans = mid;
    			r = mid-1;
    		}
    		else{
    			l = mid+1;
    		}
    	}
    	
    	int nx = x + bs_ans*k;
    	
    	cout << (nx <= n ? "YES" : "NO") << endl;
    }
}