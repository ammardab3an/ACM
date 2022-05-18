// Problem: I. Invested Money
// Contest: Codeforces - 2021-2022 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103640/problem/I
// Memory Limit: 1024 MB
// Time Limit: 350 ms
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
    
    
    {
    	
	    string str;
	    cin >> str;
	    
	    map<string, int> mp;
	    
	    mp["Sat"] = 0;
	    mp["Sun"] = 1;
	    mp["Mon"] = 2;
	    mp["Tue"] = 3;
	    mp["Wed"] = 4;
	    mp["Thu"] = 5;
	    mp["Fri"] = 6;
	    
	    int ans = INF;
	    int today = mp[str];
	    
	    int n;
	    cin >> n;
	    
	    while(n--){
	    	
	    	int d;
	    	cin >> d;
	    	
	    	int cur = ((today-d)%7 +7)%7;
	    	
	    	if(d==0){
	    		cur = (cur+30)%7;
	    		
	    		if(cur==0){
	    			d -= 2;
	    			cur = 2;
	    		}
	    		else if(cur==1){
	    			d -= 1;
	    			cur = 2;
	    		}
	    		
	    		ans = min(ans, 30-d);
	    		continue;		
	    	}
	    	
	    	while(cur != 2 && d >= 30){
	    		
	    		d -= 30;
	    		cur = (cur+30)%7;
	    		
	    		if(cur==0){
	    			d -= 2;
	    			cur = 2;
	    		}
	    		else if(cur==1){
	    			d -= 1;
	    			cur = 2;
	    		}
	    	}
	    	
	    	while(cur==2 && d >= 91){
	    		int k = d/91;
	    		d -= k*91;
	    	}
	    	
	    	while(d > 0){
	    		d -= 30;
	    		cur = (cur+30)%7;
	    		
	    		if(cur==0){
	    			d -= 2;
	    			cur = 2;
	    		}
	    		else if(cur==1){
	    			d -= 1;
	    			cur = 2;
	    		}
	    	}
	    	
	    	int cans = 0;
	    	cans = -d;
	    	
	    	ans = min(ans, cans);
	    }
	    
	    cout << ans << endl;
    }
}
