// Problem: F. Strings and Queries
// Contest: Codeforces - 2017 JUST Programming Contest 4.0
// URL: https://codeforces.com/gym/101532/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
    
    sparse_table(const vi &_arr){
        
        arr = _arr;
        int n = arr.size();
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = i;
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            if(arr[st[i][j-1]] >= arr[st[i+(1<<(j-1))][j-1]]){
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
        if(arr[st[l][j]] >= arr[st[r-(1<<j)+1][j]]){
            return st[l][j];
        }
        else{
            return st[r-(1<<j)+1][j];
        }
    }
};

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++){
		if(x%i==0) return false;
	}
	return true;
}

int hs(const string &str, int m, int p){
	
	int ret = 0;
	for(auto c : str){
		ret = (ret*m)%p;
		ret = (ret+(c-'a'+1))%p;
	}
	
	return ret;
}

int hs(const string &str){
	
	int hs0 = hs(str, 31, 773904613);
	int hs1 = hs(str, 29, 1e9+7);
	
	return (hs0 << 20) ^ hs1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, q;
		cin >> n >> q;
		
		vector<string> vec(n);
		for(auto &s : vec) cin >> s;
		
		vi cnt(n);
		map<int, int> mp;
		
		for(int i = 0; i < n; i++){
			
			string str = vec[i];
			int m = str.size();
			
			for(int j = 0; j < m; j++){
				
				{
					int l = j;
					int r = j;
					
					while((0 <= l) && (r < m) && (str[l]==str[r])){
						cnt[i]++;
						l--, r++;
					}
				}
				{
					int l = j;
					int r = j+1;
					while((0 <= l) && (r < m) && (str[l]==str[r])){
						cnt[i]++;
						l--, r++;
					}
				}
			}
			
			mp[hs(str)] = i;
		}
		
		sparse_table st(cnt);
		
		while(q--){
			
			string a, b;
			cin >> a >> b;
			
			int l = mp[hs(a)];
			int r = mp[hs(b)];
			
			if(l > r) swap(l, r);
			
			int p = st.query_range(l, r);
			
			cout << p+1 << endl;
		}
    }	
}
