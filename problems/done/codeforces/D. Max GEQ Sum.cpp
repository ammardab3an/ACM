// Problem: D. Max GEQ Sum
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    
    sparse_table(int n, const vi _arr){
        
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
    
    int tt = 1;
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi pre(n);
		pre[0] = vec[0];
		for(int i = 1; i < n; i++){
			pre[i] = pre[i-1] + vec[i];
		}
		
		vi suf(n);
		suf[n-1] = vec[n-1];
		for(int i = n-2; i >= 0; i--){
			suf[i] = suf[i+1] + vec[i];
		}
		
		sparse_table st_pre(n, pre);
		sparse_table st_suf(n, suf);
		
		vi mx_l(n), mx_r(n);
		
		{
			stack<pii> st;
			st.push({-1, INFLL});
			
			for(int i = 0; i < n; i++){
				
				while(!st.empty() && st.top().second <= vec[i]){
					st.pop();
				}
				
				mx_l[i] = st.top().first;
				
				st.push({i, vec[i]});
			}	
		}
		{
			stack<pii> st;
			st.push({n, INFLL});
			
			for(int i = n-1; i >= 0; i--){
				
				while(!st.empty() && st.top().second <= vec[i]){
					st.pop();
				}
				
				mx_r[i] = st.top().first;
				st.push({i, vec[i]});
			}
		}
		
		bool found = false;
		
		for(int i = 0; i < n; i++){
			
			int l = mx_l[i]+1;
			int r = mx_r[i]-1;
			
			int sm_l_pos = st_pre.query_range(i, r);
			int sm_r_pos = st_suf.query_range(l, i);
			
			int sm_l = pre[sm_l_pos] - pre[i];
			int sm_r = suf[sm_r_pos] - suf[i];
			
			int sm = sm_l + sm_r + vec[i];
			
			if(sm > vec[i]){
				
				// cout << l << ' ' << i << ' ' << r << endl;
				// cout << sm_l_pos << ' ' << sm_l << endl;
				// cout << sm_r_pos << ' ' << sm_r << endl;
				
				found = true;
				break;
			}
		}
		// if(tt==57){
			// cout << n << endl;
			// for(auto i : vec) cout << i << ' '; cout << endl;
			// return 0;
		// }
		// cout << tt++ << ' ';
		cout << (!found ? "YES" : "NO") << endl;
    }	
}
