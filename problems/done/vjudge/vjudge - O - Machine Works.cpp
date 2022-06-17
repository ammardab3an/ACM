// Problem: O - Machine Works
// Contest: Virtual Judge - Dynamic Programming Sheet 2 Week 4
// URL: https://vjudge.net/contest/490713#problem/O
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

struct struct_e{
	
	int D, P, R, G;

	struct_e(){
		D=P=R=G=0;
	}
	
};

int n;
struct_e arr[NMAX];

// m1*x + c1 = m2*x + c2
// x(m1-m2) = c2-c1
// x = (c2-c1)/(m1-m2);
double intersect(const pii &l1, const pii &l2){
	return double(l2.second-l1.second)/double(l1.first-l2.first);	
}

bool usefull(const pii &l1, const pii &l2, const pii &l3){
	
	double d12 = intersect(l1, l2);
	double d23 = intersect(l2, l3);
	
	return d12 < d23;
}

int calc(const pii &seg, int x){
	return seg.first * x + seg.second;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int tt = 1;
    int N, C, D;
    while(cin >> N >> C >> D, N){
    	
    	n = N+2;
    	arr[0].R = C;
    	arr[n-1] = struct_e();
    	arr[n-1].D = D+1;
    	
    	for(int i = 1; i < n-1; i++){
    		cin >> arr[i].D >> arr[i].P >> arr[i].R >> arr[i].G;	
    	}
    	
    	sort(arr, arr+n, [](const struct_e &a, const struct_e &b){
			return a.D < b.D;
    	});
    	
    	
    	int ans = 0;
    	map<int, int> mp;
    	mp[0] = arr[0].R;
    	
    	for(int i = 1; i < n; i++){
    		
    		// dp[i] = dp[j] + arr[j].R - arr[j].P + arr[j].G * (arr[i].D - arr[j].D -1);
    		// dp[i] = arr[i].D * arr[j].G + (dp[j] + arr[j].R - arr[j].P - arr[j].G * (arr[j].D + 1)) 
    		// x = arr[i].D
    		// m = arr[j].G
    		// c = dp[j] + arr[j].R - arr[j].P - arr[j].G * (arr[j].D + 1)
    		
    		int cans = 0;
    		int x = arr[i].D;
    		while(mp.size() > 1){
    			
    			auto f = mp.begin();
    			auto s = f; s++;
    				
    			if(calc(*f, x) <= calc(*s, x)){
    				mp.erase(mp.begin());
    			}
    			else{
    				break;
    			}
    		}
    		
    		cans = calc(*mp.begin(), x);
    		if(i==n-1) ans = cans;
    		
    		if(cans >= arr[i].P){
	    		
	    		int m = arr[i].G;
	    		int c = cans + arr[i].R - arr[i].P - arr[i].G * (arr[i].D + 1);
	    			
    			auto l2 = mp.emplace(m, c).first;
    			l2->second = max(l2->second, c);
    			
    			if(l2 != mp.begin() && l2 != --mp.end()){
    				
    				auto l1 = l2; l1--;
    				auto l3 = l2; l3++;
    				
    				if(!usefull(*l1, *l2, *l3)){
    					mp.erase(l2);
    					continue;
    				}
    			}
    			
    			while(l2 != mp.begin()){
    				
    				auto l1 = l2; l1--;
    				if(l1==mp.begin()) break;
    				auto l0 = l1; l0--;
    				
    				if(!usefull(*l0, *l1, *l2)){
    					mp.erase(l1);
    				}
    				else{
    					break;
    				}
    			}
    		}
    	}
    	
    	cout << "Case " << tt++ << ": " << ans << endl;
    }
}
