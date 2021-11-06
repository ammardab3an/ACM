// Problem: F. RBS
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
string str[20];
map<int, vi> mp[20];
int tot[20];
int mem[1 << 20];

int go(int msk, int sm){
    
    if(msk+1 == 1<<n){
        return 0;
    }    
    
    int &ret = mem[msk];
    if(ret+1) return ret;
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) if(((msk>>i)&1) == 0){
        
        int mn = mp[i].begin()->first;
        
        if(sm+mn >= 0){
            
            int cans = 0;
            cans += go(msk^(1<<i), sm+tot[i]);
            
            auto it = mp[i].find(-sm);
            if(it != mp[i].end()) 
                cans += it->second.size();
                
            ans = max(ans, cans);
        }   
        else{
            
            auto it = mp[i].find(-sm);
            
            if(it==mp[i].end()){
                continue;
            }
            
            if(it==mp[i].begin()){
                int cans = it->second.size();
                ans = max(ans, cans);
            }
            else{
                auto &v = mp[i][-sm];
                int r = (--it)->second.front();
                int cans = lower_bound(v.begin(), v.end(), r) - v.begin();
                ans = max(ans, cans);
            }
        } 
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
    }
    
    for(int i = 0; i < n; i++){
        
        int sm = 0;
        for(int j = 0; j < str[i].size(); j++){
            sm += str[i][j]=='(' ? +1 : -1;
            mp[i][sm].push_back(j);
        }
        tot[i] = sm;
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, 0) << endl;
}
