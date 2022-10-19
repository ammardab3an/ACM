// Problem: E - Packing Potatoes
// Contest: AtCoder - AtCoder Beginner Contest 258
// URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
// Memory Limit: 1024 MB
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, q, x;
    cin >> n >> q >> x;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi pre(n);
    pre[0] = vec[0];
    for(int i = 1; i < n; i++){
    	pre[i] = pre[i-1] + vec[i];
    }
    
    auto calc = [&](int p, int cnt){
    	
    	int ret = 0;
    	
    	if(cnt > n){
	    	ret += pre.back() * (cnt/n);
	    	cnt %= n;
    	}
    	
    	if(cnt){
	    	int mn = min(cnt, n-p);
	    	ret += pre[p+mn-1] - pre[p] + vec[p];	
	    	int rm = cnt-mn;
	    	if(rm) ret += pre[rm-1];
    	}
    	
    	return ret;
    };
    
    
    vector<bool> vis(n);
    
    vpii tmp;
    
    int cur = 0;
    while(!vis[cur]){
    	
    	vis[cur] = true;
    	
    	int l = 0;
    	int r = INF;
    	
    	int ans = 0;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		if(calc(cur, mid) >= x){
    			ans = mid;
    			r = mid-1;
    		}
    		else{
    			l = mid+1;
    		}
    	}
    	
    	tmp.push_back({cur, ans});
    	cur = (cur+ans)%n;
    }
    
    int cnt = 0;
    for(auto p : tmp){
    	if(p.first==cur) break;
    	cnt++;
    }
    
    while(q--){
    	
    	int p;
    	cin >> p;
    	p--;
    	
    	if(p <= cnt){
    		cout << tmp[p].second << endl;
    	}
    	else{
    		
    		p -= cnt;
	    	p %= tmp.size()-cnt;
	    	
	    	cout << tmp[cnt+p].second << endl;
    	}
    }
}
