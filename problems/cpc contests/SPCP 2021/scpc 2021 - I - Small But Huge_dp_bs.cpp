
// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int arr[NMAX];
int pre[10][NMAX];
vi primes = {2, 3, 5, 7, 11, 13};
const int PRIME_SZ = 6;
int mem[NMAX][1 << PRIME_SZ];
int vis[NMAX][1 << PRIME_SZ], vid;
int memo[NMAX][1 << PRIME_SZ];
int viso[NMAX][1 << PRIME_SZ], vido;

struct sparse_table{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table(){};
    
    sparse_table(int n){
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = 0;
            for(int j = 0; j < PRIME_SZ; j++){
            	if(arr[i]%primes[j]==0){
            		st[i][0] |= 1 << j;
            	}
            }
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = st[i][j-1] | st[i+(1<<(j-1))][j-1];
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        return st[l][j] | st[r-(1<<j)+1][j];
    }
    
} st;

void build(){
	st = sparse_table(n);	
}

int query(int l, int r){
	return st.query_range(l, r);
}

int go(int i, int msk);
int go_suf(int i, int msk){
	
	if(i > n){
		return 0;
	}	
	
	int &ret = memo[i][msk];
	if(viso[i][msk]==vido) return ret;
	viso[i][msk] = vido;
	
	return ret = add(go(i, msk), go_suf(i+1, msk));
}

int go(int i, int msk){
	
	if(!msk){
		return 0;
	}
	
	if(i==n){
		return 1;
	}	
	
	int &ret = mem[i][msk];
	if(vis[i][msk]==vid) return ret;
	vis[i][msk] = vid;
	
	int ans = 0;
	
	int j = i;
	
	while(j != n){
		
		int nxt = query(i, j);
			
		int l = j;
		int r = n-1;
		
		int bs_ans = j;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			int que = query(i, mid);
			
			if(que==nxt){
				bs_ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		
		int nmsk = msk&nxt;
		
		if(nmsk){
			int cans = go_suf(j+1, nmsk);
			cans = add(cans, mul(-1, go_suf(bs_ans+2, nmsk)));
			ans = add(ans, cans);
		}
		
		j = bs_ans + 1;
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		build();
		
		vid++;
		vido++;
		
		int ans = go(0, (1<<PRIME_SZ)-1);
		cout << ans << endl;
    }	
}
