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
 
const int NMAX = 1e6 + 10;

struct node{
	int l, r;
	node(){l=r=-2;}
	node(int l, int r) : l(l), r(r) {}
};

node arr[NMAX];
node pre[NMAX];
node suf[NMAX];

node merge(const node &a, const node &b){
	
	if(a.l == -1 || b.l == -1){
		return node(-1, -1);
	}	
	
	if(a.l==-2){
		return b;
	}
	if(b.l==-2){
		return a;
	}
	
	if(a.r < b.l){
		return node(a.l, b.r);
	}
	else{
		return node(-1, -1);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, x;
    cin >> n >> x;
    
    for(int i = 0; i < n; i++){
    	
    	int ai;
    	cin >> ai;
    	
    	if(arr[ai].l==-2){
    		arr[ai].l = arr[ai].r = i;
    	}
    	else{
	    	arr[ai].l = min(arr[ai].l, i);
	    	arr[ai].r = max(arr[ai].r, i);
    	}
    }
    
    for(int i = 1; i <= x; i++){	
		pre[i] = merge(pre[i-1], arr[i]);
    }
    
    for(int i = x; i >= 1; i--){
    	suf[i] = merge(arr[i], suf[i+1]);
    }
    
    ll ans = 0;
    
    for(int i = 1; i <= x; i++){
    	
    	int l = i;
    	int r = x;
    	
    	int cans = -1; 
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		node que = merge(pre[i-1], suf[mid+1]);
    		
    		if(que.l != -1){
    			cans = mid;
    			r = mid-1;
    		}
    		else{
    			l = mid+1;
    		}
    	}
    	
    	if(cans != -1){
    		ans += x-cans+1;
    	}
    	
    }
    
    cout << ans << endl;
}
