// Problem: E. Escalator
// Contest: Codeforces - 2021-2022 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/103388/problem/E
// Memory Limit: 1024 MB
// Time Limit: 250 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;

#define ll  int64_t
#define int ll

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
const int MOD = 998244353;
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

const int  MAX = 5e5 + 10;
const int NMAX = 2e7 + 10;
const int MMAX = 2e7 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){

    fastIO
    int n, k;
    vector <pii> v;

    cin >> n;
    for (int i=0,x,y;i<n;i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    int last = -1;
    vector <bool> vis(n, false);
    
    int cur_time = 0;
    
    for (int i = 0;i < v.size();i++) if(!vis[i]){
        
        cur_time = max(cur_time, v[i].first) + 10;
        
        for (int j = i + 1;j < v.size();j++) if(!vis[j]){
            
            if ((v[j].first <= cur_time) && (v[j].second == v[i].second)) {
                
                cur_time = max(cur_time, v[j].first + 10);
                vis[j] = 1;
            }
        }
    }
    
    cout << cur_time;
}
