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

const int  MAX = 3e3 + 10;
const int NMAX = 2e7 + 10;
const int MMAX = 2e7 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
string s;
vector < vector <int> > g;
vector <int> ans, cnt;

int32_t main(){
    
    fastIO
    cin >> n;
    g.resize(n);
    for (int i=0,a,b;i<n-1;i++){
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b), g[b].push_back(a);
    }
    
    ans.resize(n);
    fill(ans.begin(), ans.end(),0);

    cnt.resize(n);
    fill(cnt.begin(), cnt.end(),0);
    
    auto dfs = [&](auto &self, int i, int p) -> void{
        for (int u : g[i]){
            if (u == p) continue;
            self(self, u, i);
            cnt[i] += cnt[u];
            ans[i] += ans[u] + cnt[u];
        }
        ++cnt[i];
    };
    
    auto dfs2 = [&](auto &self, int i, int p) -> void{
        for (int u : g[i]) {
            if (u == p) continue;
            ans[u] = ans[i] + n - 2 * cnt[u];
            self(self, u, i);
        }
    };

    dfs(dfs, 0, -1);
    dfs2(dfs2, 0, -1);
    
    for (int i : ans) cout << i << ' ';
}