// Problem: D. Lucky Probability
// Contest: Codeforces - Codeforces Beta Round #84 (Div. 2 Only)
// URL: https://codeforces.com/contest/110/problem/D
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

int comb(int l0, int r0, int l1, int r1){
    int nl = max(l0, l1);
    int nr = min(r0, r1);
    return nl <= nr ? (nr-nl+1) : 0;
}

pii comb2(int l0, int r0, int l1, int r1){
    int nl = max(l0, l1);
    int nr = min(r0, r1);
    return nl <= nr ? (pii){nl, nr} : (pii){0, 0};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    vi vec;
    queue<int> que;
    que.push(0);
    
    while(!que.empty()){
    	
    	int fr = que.front();
    	que.pop();
    	
    	int x = fr;
    	
    	if(x > 1e9){
    		continue;
    	}
    	
    	if(x){
	    	vec.push_back(x);		
    	}
    	
    	{
    		int nx = x*10+4;
    		que.push(nx);
    	}
    	{
    		int nx = x*10+7;
    		que.push(nx);
    	}
    }
    
    
    int l0, r0, l1, r1, k;
    cin >> l0 >> r0 >> l1 >> r1 >> k;
    
    if(l0 > l1 || (l0==l1 && r0 > r1)){
    	swap(l0, l1);
    	swap(r0, r1);
    }
    
    int ans0 = 0;
    int ans1 = (r0-l0+1) * (r1-l1+1);
    
    auto [nl, nr] = comb2(l0, r0, l1, r1);
    
    int n = vec.size();
    for(int i = 0; i < n; i++) {
    	
    	int j = i+k-1;
    	if(j >= n) break;
    	
		int pl = i ? vec[i-1]+1 : 1;
		int pr = vec[i];
		
		int sl = vec[j];
		int sr = j+1<n ? vec[j+1]-1 : 1e9;
		
		int cans = 0;
		
		cans += comb(l0, r0, pl, pr) * comb(l1, r1, sl, sr);
		cans += comb(l1, r1, pl, pr) * comb(l0, r0, sl, sr);
    	
    	if(k==1){
    		if(nl <= vec[i] && vec[i] <= nr){
    			cans--;
    		}
    	}
    	
    	ans0 += cans;
    }
    
    // cout << ans0 << ' ' << ans1 << endl;
    
    double ans = double(ans0)/double(ans1);
    cout << fixed << setprecision(12) << ans << endl;
}
