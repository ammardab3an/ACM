
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
string str[10101];
unordered_map<string, int> mp;
int mem[10101];
vi nxt[10101];

vi calc(int i){
	
	if(nxt[i].size()){
		return nxt[i];
	}
	
	if(nxt[i]==(vi){-1}){
		return (vi){};
	}
	
	string s = str[i];
	for(int l = 0; l <= (int)s.size(); l++){
		for(int c = 'a'; c <= 'z'; c++){
			string cur = s.substr(0, l) + string(1, c) + s.substr(l);
			// cout << cur << endl;
			auto it = mp.find(cur);
			if(it != mp.end()){
				nxt[i].push_back(it->second);
			}	
		}
	}
	
	if(nxt[i].empty()){
		nxt[i] = (vi){-1};
		return (vi){};
	}
	else{
		return nxt[i];
	}
}

int go(int i){
	
	int &ret = mem[i];
	if(ret+1) return ret;
	
	int ans = 1;
	
	vi tmp = calc(i);
	for(auto j : tmp){
		ans = max(ans, 1+go(j));	
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
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> str[i];
    	mp[str[i]] = i;
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
    	ans = max(ans, go(i));
    }
    
    cout << ans << endl;
}
