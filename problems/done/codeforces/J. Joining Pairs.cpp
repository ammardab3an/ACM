// Problem: J. Joining Pairs
// Contest: Codeforces - 2021-2022 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103640/problem/J
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    auto good = [&](int i, int j){
    	return i==0 || i==n || j==0 || j==m;
    };
    
    auto conv = [&](int i, int j){
    	
    	if(i==0){
    		return j;
    	}		
    	else if(j==m){
    		return m+i;
    	}
    	else if(i==n){
    		return m+n+(m-j);
    	}
    	else if(j==0){
    		return m+n+m+(n-i);
    	}
    	else{
    		assert(false);
    	}
    };
    
    int k;
    cin >> k;
    
    vpii tmp;
    int ii = 0;
    while(k--){
    	
    	pii p0, p1;
    	cin >> p0.first >> p0.second;
    	cin >> p1.first >> p1.second;
    	
    	if(good(p0.first, p0.second) && good(p1.first, p1.second)){
    		tmp.push_back({conv(p0.first, p0.second), ii});
    		tmp.push_back({conv(p1.first, p1.second), ii});
    		ii++;
    	}
    }
    
    bool ans = true;
    
    sort(tmp.begin(), tmp.end());
    
    vi vis(ii);
    stack<int> st;
    
    // for(auto [i, c] : tmp){
    	// cout << i << ' ' << c << endl;
    // }
	
    for(auto [i, c] : tmp){
    	
    	if(!vis[c]){
    		vis[c] = true;
    		st.push(c);
    	}	
    	else{
    		if(st.top() != c){
    			ans = false;
    			break;
    		}
    		st.pop();
    	}
    }
    
    cout << "NY"[ans] << endl;
}
