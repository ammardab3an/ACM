// Problem: F. Friendly Fire
// Contest: Codeforces - 2019, XII Samara Regional Intercollegiate Programming Contest
// URL: https://codeforces.com/gym/102215/problem/F
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

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n;
    while(cin >> n){
    	
	    // p.first = attack
	    // p.second = health
	
	    vpii vec(n);
	    for(auto &p : vec)
	    	cin >> p.first >> p.second;
	
	    vi pos(n);
	    iota(pos.begin(), pos.end(), 0);
	    sort(pos.begin(), pos.end(), [&](int i, int j){
	    	return vec[i].second < vec[j].second;
	    });
	
	    vector<pii> pre(n);
	    pre[0].first = pos[0];
	    pre[0].second = -1;
	
	    for(int i = 1; i < n; i++){
	
	    	pre[i] = pre[i-1];
	
	    	if(vec[pos[i]].first >= vec[pre[i].first].first){
	    		pre[i].second = pre[i].first;
	    		pre[i].first = pos[i];
	    	}
	    	else if((pre[i].second==-1) || (vec[pos[i]].first >= vec[pre[i].second].first)){
	    		pre[i].second = pos[i];
	    	}
	    }
	
	    int og_ans = 0;
	    for(auto p : vec){
	    	og_ans += p.first;
	    }
	
	    int ans = og_ans;
	    pii ans_p = {0, 1};
	
	    for(int i = 0; i < n; i++){
			
			int p = i;
	    	int att = vec[p].first;
	    	int hel = vec[p].second;
	
	    	int l = 0;
	    	int r = n-1;
	
	    	int bs_ans = -1;
	
	    	while(l <= r){
	
	    		int mid = (l+r)/2;
	
	    		if(vec[pos[mid]].second <= att){
	    			bs_ans = mid;
	    			l = mid+1;
	    		}
	    		else{
	    			r = mid-1;
	    		}
	    	}
			
	    	if(bs_ans != -1){
	
	    		int p0 = pre[bs_ans].first;
	    		int p1 = pre[bs_ans].second;
				
	    		for(auto np : {p0, p1}) if(p != np && np != -1){
	    			int cans = og_ans - vec[np].first;
	    			if(vec[np].first >= hel) cans -= att;
	    			if(ans > cans){
	    				ans = cans;
	    				ans_p = {p, np};
	    			}
	    		}
	    	}
	    }
	
	    // cout << og_ans-ans << endl;
	    
		cout << og_ans - ans << endl;
	    cout << ans_p.first+1 << ' ' << ans_p.second+1 << endl;
    }
}
