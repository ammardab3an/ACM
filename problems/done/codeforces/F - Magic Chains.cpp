
// tle
// https://codeforces.com/gym/100030/problem/F
// By AmmarDab3an 

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
 
const int NMAX = 6e4 + 10;
const int p = 1e9+9;
const int m = 31;

int calc(const string &str){
	int ret = 0;
	for(auto c : str){
		ret = ((ret*1ll*m)%p + (c-'a'+1))%p;
	}
	return ret;
}

string arr[NMAX];
pii look[NMAX];
int tmp_hash[NMAX];
int dist[NMAX];
int par[NMAX];
int pow_m[111];

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    int sz = arr[0].size();
    
    unordered_map<int, int, custom_hash> look;
    
    for(int i = 0; i < n; i++){
    	tmp_hash[i] = calc(arr[i]);
    	look[tmp_hash[i]] = i;
    }
    
    for(int i = 0; i < n; i++){
    	par[i] = -1;
    	dist[i] = INF;
    }
    
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    
    pow_m[0] = 1;
    for(int i = 1; i < sz; i++){
    	pow_m[i] = (pow_m[i-1]*1ll*m)%p;
    }
    
    while(!que.empty()){
    	
    	int tp = que.front();
    	que.pop();
    	
    	int cn = tp;
    	int cd = dist[cn];
    	
    	for(int i = 0; i < sz; i++){
    		for(int j = 0; j < 26; j++){
    			
    			int cur = tmp_hash[cn];
				cur = (cur + (((j)-(arr[cn][i]-'a'))*1ll*pow_m[sz-i-1])%p)%p;
				cur = (cur+p)%p;
    			
    			auto it = look.find(cur);
    			
    			if(it!=look.end() && dist[it->second]>cd+1){
    				int nxt = it->second;
    				dist[nxt] = cd+1;
    				par[nxt] = cn;
    				que.push(nxt);
    			}
    		}
    	}
    }
    
    if(dist[n-1] > n){
    	cout << "FAIL" << endl;
    }
    else{	
	    cout << dist[n-1]+1 << endl;
	    
	    vi tmp;
	    int cur = n-1;
	    while(cur != -1){
	    	tmp.push_back(cur);
	    	cur = par[cur];
	    }
	    
	    reverse(tmp.begin(), tmp.end());
	    
	    for(auto i : tmp){
	    	cout << arr[i] << endl;
	    }
    }
}
