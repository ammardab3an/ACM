// Problem: E. Earth Wind and Fire
// Contest: Codeforces - Codeforces Global Round 3
// URL: https://codeforces.com/contest/1148/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    
    vi cur(n);
    for(auto &i : cur) cin >> i;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi pcur(n);
    iota(pcur.begin(), pcur.end(), 0);
    sort(pcur.begin(), pcur.end(), [&](int i, int j){
    	return cur[i] < cur[j];
    });
    
    sort(vec.begin(), vec.end());
    
    vi tmp(n);
    for(int i = 0; i < n; i++){
    	tmp[i] = vec[i]-cur[pcur[i]];
    }
    
    // for(auto i : tmp) cout << i << ' '; cout << endl;
    
    stack<pii> st;
    vector<iii> ans;
    bool bad = false;
    
    for(int i = 0; i < n; i++){
    	
    	if(tmp[i] >= 0){
    		st.push({i, tmp[i]});
    	}
    	else{
    		
    		int ti = tmp[i];
    		while(ti < 0 && !st.empty()){
    			int mn = min(-ti, st.top().second);
    			ti += mn;
    			st.top().second -= mn;
    			ans.push_back({mn, {st.top().first, i}});
    			if(st.top().second==0) st.pop();
    		}
    		
    		if(ti != 0){
    			bad = true;
    			break;
    		}
    	}
    }
    
    while(!st.empty() && st.top().second==0) st.pop();
    bad |= !st.empty();
    
    if(bad){
    	cout << "NO" << endl;
    }
    else{
    	cout << "YES" << endl;
    	cout << ans.size() << endl;
    	for(auto p : ans){
    		cout << pcur[p.second.first]+1 << ' ' << pcur[p.second.second]+1 << ' ' << p.first << endl;
    	}
    }
}
