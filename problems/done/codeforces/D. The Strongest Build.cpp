// Problem: D. The Strongest Build
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/D
// Memory Limit: 256 MB
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
vi arr[10];
vi sm_mx;

struct node{
    map<int, int> nxt;    
};

int ID = 1;
node nds[NMAX * 10];

void add(const vi &vec, int cur){
    
    for(auto i : vec){
        
        if(nds[cur].nxt[i] == 0){
           nds[cur].nxt[i] = ID++; 
        }
        
        cur = nds[cur].nxt[i];
    }
}

int mem[NMAX * 10];

int go(int i, int cur){
    
    if(i == n){
        return -INFLL;
    }
    
    int &ret = mem[cur];
    if(ret+1) return ret;
    
    int ans = -INFLL;
    
    auto &mp = nds[cur].nxt;
    
    // first path - break from the tree
    
    for(int j = arr[i].size()-1; j >= 0; j--){
        if(mp.find(j) == mp.end()){
            int cans = arr[i][j] + sm_mx[i+1];       
            ans = max(ans, cans);
            break;
        }
    }    
    
    // second path - continue dfs-ing in the tree
    
    for(auto p : mp){
        int cans = arr[i][p.first] + go(i+1, p.second);
        ans = max(ans, cans);
    }
    
    return ret = ans;
}

vi calc_res;
void calc(int i, int cur){
    
    int ans = go(i, cur);   
     
    auto &mp = nds[cur].nxt;
    
    // first path - break from the tree
    
    for(int j = arr[i].size()-1; j >= 0; j--){
        if(mp.find(j) == mp.end()){
            int cans = arr[i][j] + sm_mx[i+1];       
            if(cans == ans){
                calc_res.push_back(j);
                for(int j = i+1; j < n; j++){
                    calc_res.push_back(arr[j].size()-1);
                }
                return;
            }
        }
    }    
    
    // second path - continue dfs-ing in the tree
    
    for(auto p : mp){
        int cans = arr[i][p.first] + go(i+1, p.second);
        if(cans == ans){
            calc_res.push_back(p.first);
            calc(i+1, p.second);
            return;
        }
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
    for(int i = 0; i < n; i++){
        int sz; cin >> sz;
        for(auto &e : (arr[i] = vi(sz))){
            cin >> e;
        }
    }
    
    int root = 0;
    
    int m; cin >> m; while(m--){
        
        vi tmp(n);
        for(auto &i : tmp) cin >> i, --i;
        
        add(tmp, root);
    }
    
    sm_mx = vi(n+1);
    for(int i = n-1; i >= 0; i--){
        sm_mx[i] = sm_mx[i+1] + arr[i].back();
    }
    
    memset(mem, -1, sizeof mem);
    
    // cout << go(0, 0) << endl;
    
    calc(0, 0);
    
    for(auto i : calc_res){
        cout << i+1 << ' ';
    }
}
