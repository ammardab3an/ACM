// Problem: E. Messages
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/E
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
 
const int  MAX = 1000 + 10;
const int NMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n;
pii tmp[NMAX];
vi comp;
vi arr[NMAX];

double mem[NMAX][22];
int vis[NMAX][22], vid;
double pre_calc[NMAX];

double nCr[MAX][MAX];

void init( ){ 
    nCr[0][0] = 1 ; 
    for ( int i = 1 ; i<= 1000 ; i ++ ){ 
        for ( int j = 0 ; j <= i ; j ++ ){ 
            if ( j == 0 ) 
                nCr[i][j] = 1 ; 
            else 
                nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j] ; 
        } 
    } 
  
}

double choose(int n, int c){
    c = min(c, n-c);
    return nCr[n][c];
}

double go(int i, int rst){
    
    if(rst == 0){
        return 0;
    }
    
    if(i == n){
        return -1e18;
    }    
    
    if(vis[i][rst] == vid){
        return mem[i][rst];
    }
    else{
        vis[i][rst] = vid;
    }
    
    double st_path = go(i+1, rst);
    double nd_path = go(i+1, rst-1) + pre_calc[i];
    
    return mem[i][rst] = max(st_path, nd_path);
}

void get_path(int i, int rst){
    
    if(rst == 0){
        return;
    }
    
    if(go(i+1, rst) == go(i, rst)){
        get_path(i+1, rst);
    }
    else{
        cout << comp[i] << ' ';
        get_path(i+1, rst-1);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
        
    cin >> n;
    for(int i = 0; i < n; i++){
        
        int m, k;
        cin >> m >> k;
        
        comp.push_back(m);
        tmp[i] = {m, k};
    }
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    
    for(int i = 0; i < n; i++){
        
        int m = tmp[i].first;
        int k = tmp[i].second;
        
        m = lower_bound(comp.begin(), comp.end(), m) - comp.begin();
        
        arr[m].push_back(k);
    }
    
    double cans = 0;
    int cans_cnt = 0;
    
    int mn = min((int)20, n);
    for(int cnt = 1; cnt <= mn; cnt++){
        
        vid++;
        for(int i = 0; i < n; i++){
            pre_calc[i] = 0;
            for(auto k : arr[i]){
                if(cnt > k){                    
                    pre_calc[i] += choose(cnt-1, k-1) / choose(cnt, k);
                }
                else{
                    pre_calc[i] += 1;
                }
            }                
        }   
        
        double ccans = go(0, cnt);
        if(ccans > cans){
            cans = ccans;
            cans_cnt = cnt;
        } 
    }   
         
    // cout << cans << ' ' << cans_cnt << endl;
    
    vid++;
    int cnt = cans_cnt;
    for(int i = 0; i < n; i++){
        
        pre_calc[i] = 0;
        for(auto k : arr[i]){
            if(cnt > k){                    
                pre_calc[i] += choose(cnt-1, k-1) / choose(cnt, k);
            }
            else{
                pre_calc[i] += 1;
            }
        }
        
        // cout << pre_calc[i] << ' ';
        // if(i==n-1)cout << endl;
    } 
    
    cout << cans_cnt << endl;
    get_path(0, cans_cnt);
}
