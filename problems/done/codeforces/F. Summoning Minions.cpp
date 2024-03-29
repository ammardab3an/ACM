// Problem: F. Summoning Minions
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1354/problem/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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
 
const int NMAX = 75 + 10;

int n, k;
int a[NMAX], b[NMAX];
int pos[NMAX];

int mem[NMAX][NMAX][NMAX];
int vis[NMAX][NMAX][NMAX], vid;

vi vec0, vec1;

int go(int i, int rem_0, int rem_1){
    
    if(i==n) return 0;
    
    int &ret = mem[i][rem_0][rem_1];
    if(vis[i][rem_0][rem_1]==vid) return ret;
    vis[i][rem_0][rem_1] = vid;
    
    int st_path = 0;
    int nd_path = 0;
    
    if(rem_1){    
        st_path = go(i+1, rem_0, rem_1-1) + (k-1)*b[pos[i]];
    }
    if(rem_0){    
        nd_path = go(i+1, rem_0-1, rem_1) + a[pos[i]] + (k-rem_0)*b[pos[i]];
    }
    
    return ret = max(st_path, nd_path);
}

void calc(int i, int rem_0, int rem_1){
    
    if(i==n) return;
    
    if(rem_1 && (go(i, rem_0, rem_1) == (go(i+1, rem_0, rem_1-1) + (k-1)*b[pos[i]]))){
        vec1.push_back(pos[i]+1);
        calc(i+1, rem_0, rem_1-1);
    }
    else{
        vec0.push_back(pos[i]+1);
        calc(i+1, rem_0-1, rem_1);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        
        iota(pos, pos+n, 0);
        
        sort(pos, pos+n, [&](int i, int j){
            return b[i] < b[j];
        });
        
        vid++;
        vec0.clear();
        vec1.clear();
        calc(0, k, n-k);
        
        cout << k + (n-k)*2 << endl;
        for(int i = 0; i+1 < vec0.size(); i++) cout << vec0[i] << ' ';
        for(auto i : vec1) cout << i << ' ' << -i << ' ';
        cout << vec0.back() << endl;
    }	
}
