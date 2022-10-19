// Problem: A. Chess
// Contest: Codeforces - ACM-ICPC-Swiss-Subregional 2017
// URL: https://codeforces.com/gym/101597/problem/A
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

int n;
int arr[NMAX];
map<int, int> mp;

bool go(int cur, int md, int cnt=1){
	
	if(cnt==n){
		return true;
	}	
	
	int nxt = (cur*2)%md;
	auto it = mp.find(nxt);
	
	if((it==mp.end()) || ((it->second)==0)){
		return false;
	}
	else{
		(it->second)--;
		bool ret = go(nxt, md, cnt+1);
		(it->second)++;
		return ret;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    
    bool all_zero = true;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	mp[arr[i]]++;
    	all_zero &= arr[i]==0;
    }
    
    if(all_zero){
    	cout << 1 << endl;
    	return 0;
    }
    
    int cur = 1;
    int cur_cnt = 1;
    while(mp.find(cur*2)!=mp.end()){
    	cur*=2;
    	cur_cnt++;
    }
    
    if(cur_cnt==n){
    	cout << cur+1 << endl;
    	return 0;
    }
    
    int ans = INFLL;
    
    mp[1]--;
    
    vi tmp;
    for(auto p : mp){
    	if(p.second){
    		tmp.push_back(p.first);
    	}
    }
    
    reverse(tmp.begin(), tmp.end());
    
    for(auto e : tmp){
    	int cur_md = cur*2 - e;
    	if(cur_md < 0) continue;
    	if(go(1, cur_md)) {
    		ans = cur_md;
    		break;
    	}
    }
    
    cout << ans << endl;
}
