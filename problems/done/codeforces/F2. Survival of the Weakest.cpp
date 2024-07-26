// Problem: F2. Survival of the Weakest (hard version)
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/F2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    if(n==0){
    	n = 2e5;
    	vec = vi(n);
    	for(auto &i : vec){
    		i = 1 << (int)rand(0, 1e9);
    	}
    }
    
    sort(vec.begin(), vec.end());
    
    vpii tmp;
    
    {
    	int lst = vec[0];
    	int cnt = 1;
    	for(int i = 1; i < n; i++){
    		if(vec[i] != lst){
    			tmp.push_back({lst, cnt});
    			lst = vec[i];
    			cnt = 1;
    		}
    		else{
    			cnt++;
    		}
    	}
    	tmp.push_back({lst, cnt});
    }
    
    if(tmp.size() > BLOCK){	
	    tmp.resize(BLOCK);
    }
    
    int ans_add = 0;
    
    for(int i = n-1; i > 0; i--){
  		
  		// cout << tmp.size() << endl;
  		
    	int mn = tmp.front().first;
    	ans_add = mul(add(ans_add, mn), 2);
    	
    	multiset<iii> que;
    	
    	{
	    	int lst = 0;
	    	int tot = 0;
	    	for(int i = 0; i < tmp.size(); i++){
	    		que.insert({2*tmp[i].first, {i, i}});
	    	}
    	}
    	
    	vpii ntmp;
    	int lft = min(i, BLOCK);
    	
    	while(lft){
    		
    		auto tp = *que.begin();
    		que.erase(que.begin());
    		
    		int cur = tp.first-2*mn;
    		auto [i, j] = tp.second;
    		
    		int cnt;
    		
    		if(i==j){
    			cnt = tmp[i].second;
    			cnt = (cnt*(cnt-1))/2;
    		}
    		else{
    			cnt = tmp[i].second*tmp[j].second;
    		}
    		
    		cnt = min(cnt, lft);
    		lft -= cnt;
    		
    		if(cnt){
    			if(ntmp.size() && ntmp.back().first==cur){
    				ntmp.back().second += cnt;
    			}
    			else{
    				ntmp.push_back({cur, cnt});
    			}
    		}
    		
    		if(++j < tmp.size()){
    			que.insert({(tmp[i].first+tmp[j].first), {i, j}});
    		}
    	}
    	
    	tmp = ntmp;
    }
    
    int ans = add(tmp.front().first, ans_add);
    cout << ans << endl;
}
