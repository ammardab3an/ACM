// Problem: D. Iahub and Xors
// Contest: Codeforces - Codeforces Round #198 (Div. 1)
// URL: https://codeforces.com/contest/341/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int NMAX = 1e3 + 10;

struct bit_2d
{ 

    int n;
    int tree[2][2][NMAX][NMAX];
    
    bit_2d(){}
    bit_2d(int h, int w){
        n = max(h, w);
    }    
    
    void add(int X , int Y , int V){
        for(int x = X ; x <= n ; x+=x&(-x))
            for(int y = Y ; y<=n ; y+=y&(-y))
                tree[X&1][Y&1][x][y] ^= V;
    }
    
    int get(int X , int Y){
        int ret = 0;
        for(int x = X ; x > 0 ; x-=x&(-x))
            for(int y = Y ; y > 0 ; y-=y&(-y))
                ret ^= tree[X%2][Y%2][x][y];
        return ret;
    }
    
    void update_submatrix(int x1, int y1, int x2, int y2, int val){
        add(x1 , y1 , val);
        add(x2+1 , y1 , val);
        add(x1 , y2+1 , val);
        add(x2+1 , y2+1 , val);
    }
    
    int query_submatrix(int x1, int y1, int x2, int y2){
        return get(x2, y2) ^ get(x1-1, y2) ^ get(x2, y1-1) ^ get(x1-1, y1-1);
    }
    
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    bit_2d tree(n, n);
    
    while(m--){
        
        int k;
        cin >> k;
        
        if(k==2){
            
            int x1, y1, x2, y2, c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            
            tree.update_submatrix(x1, y1, x2, y2, c);
        }
        else{
            
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            int ans = tree.query_submatrix(x1, y1, x2, y2);
            
            cout << ans << endl;
        }
    }
}