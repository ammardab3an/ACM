// Problem: Connecting Soldiers
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/NOKIA
// Memory Limit: 256 MB
// Time Limit: 366 ms
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

void go(int l, int r, vi &vec){
	
	if(l > r){
		return;
	}	
	
	int mid = (l+r)/2;
	vec.push_back(mid);
	go(l, mid-1, vec);
	go(mid+1, r, vec);
}

int calc(vi vec){
	
	int n = vec.size();
	
	set<int> st;
	st.insert(-1);
	st.insert(n);
	
	int ret = 0;
	
	for(auto i : vec){
		
		auto it = st.lower_bound(i);
		auto _it = it;
		_it--;
		
		ret += (*it) - i;
		ret += i - (*_it);
		
		st.insert(i);
	}	
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		int mn, mx;
		
		{
			vi vec(n);
			iota(vec.begin(), vec.end(), 0);
			mx = calc(vec);
		}
		
		{
			vi vec;
			go(0, n-1, vec);
			mn = calc(vec);
		}
		
		// cout << mn << ' ' << mx << endl;
		
		if(m >= mx){
			cout << m-mx << endl;
		}
		else if(mn <= m && m <= mx){
			cout << 0 << endl;
		}
		else{
			cout << -1 << endl;
		}
    }	
}
