// Problem: D - Online games
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi tmp;
    
    vpii vec(n);
    for(auto &p : vec){
        cin >> p.first >> p.second;
        p.second = p.first+p.second-1;
        tmp.push_back(p.first);
        tmp.push_back(p.second);
    }
    
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
    
    vpii comp;
    comp.push_back({tmp[0], 1});
    
    for(int i = 1; i < tmp.size(); i++){
        if(tmp[i-1]+1 != tmp[i]){
            comp.push_back({tmp[i-1]+1, (tmp[i]-1) - (tmp[i-1]+1) +1});
        }
        comp.push_back({tmp[i], 1});
    }
    
    vi ans(n+1);
    vi cnt(comp.size());
    
    for(auto &p : vec){
        
        p.first = lower_bound(comp.begin(), comp.end(), (pii){p.first, -1}) - comp.begin();
        p.second = lower_bound(comp.begin(), comp.end(), (pii){p.second, -1}) - comp.begin();
        
        cnt[p.first] += 1;
        if(p.second+1 < comp.size()){        
            cnt[p.second+1] -= 1;
        }
    }
    
    int cur = 0;
    for(int i = 0; i < cnt.size(); i++){
        cur += cnt[i];
        ans[cur] += comp[i].second;
    }
    
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
}
