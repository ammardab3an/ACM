
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

int n, m;
string str;
int dist[33][33];
int mem[NMAX][1<<6];

int go(int i, int _xor){
	
	if(i==n){
		return _xor==0 ? 0 : INF;
	}
	
	int &ret = mem[i][_xor];
	if(ret+1) return ret;
	
	int ans = INF;
	
	for(int j = 0; j < 26; j++){
		int cans = go(i+1, _xor^j) + dist[str[i]-'a'][j];
		ans = min(ans, cans);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    cin >> str;
    
    vector<vi> mv(26, vi(26, INFLL));
    
    while(m--){
    	char u, v;
    	int w;
    	cin >> u >> v >> w;
    	int &d = mv[u-'a'][v-'a'];		
    	d = min(d, w);
    }
    
    memset(dist, INF, sizeof dist);
    
    for(int i = 0; i < 26; i++){
    	
	    priority_queue<pii> que;
	    que.push({0, i});
	    dist[i][i] = 0;
	    
	    while(!que.empty()){
	    	
	    	pii tp = que.top();
	    	que.pop();
	    	
	    	int cn = tp.second;
	    	int cd = tp.first;
	    	
	    	if(dist[i][cn] < cd) continue;
	    	
	    	for(int j = 0; j < 26; j++){
	    		
	    		int nxt = j;
	    		int nxtd = cd + mv[cn][nxt];
	    		
	    		if(nxtd < dist[i][nxt]){
	    			dist[i][nxt] = nxtd;
	    			que.push({nxtd, nxt});
	    		}
	    	}
	    }
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0, 0);
    if(ans >= INF) ans = -1;
    
    cout << ans << endl;
}
