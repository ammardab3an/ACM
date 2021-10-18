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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct bit_2d
{ 
    
    int n, m;
    vector<vi> b1, b2, b3, b4;
    
    bit_2d(){}
    
    bit_2d(int h, int w){
        n = h, m = w;
        b1 = vector<vi>(h, vi(w));
        b2 = vector<vi>(h, vi(w));
        b3 = vector<vi>(h, vi(w));
        b4 = vector<vi>(h, vi(w));
    }
    
    void update(vector<vi> &tree, int i, int j, int val) 
    {
        if(!val) return;
        
        for(i++ ; i <= n ; i += (i & (-i))) 
        { 
            for(int jj = j + 1 ; jj <= m ; jj += (jj & (-jj))) 
            { 
                tree[i - 1][jj - 1] ^= val; 
            } 
        } 
    }    
    
    void update_range(vector<vi> &tree_m, vector<vi> &tree_c, int x, int l, int r, int c){
        update(tree_m, x, l, c);
        update(tree_m, x, r+1, c);
        update(tree_c, x, l, c*((l-1)%2==0));
        update(tree_c, x, r+1, c*(r%2==0));   
    }
    
    void update_submatrix(int x1, int y1, int x2, int y2, int c){
        update_range(b1, b2, x1, y1, y2, c);
        update_range(b1, b2, x2+1, y1, y2, c);
        update_range(b3, b4, x1, y1, y2, c*((x1-1)%2==0));
        update_range(b3, b4, x2+1, y1, y2, c*(x2%2==0));
    }
    
    int query(vector<vi> &tree, int i, int j) 
    { 
        int ret = 0; 
        for(i++ ; i ; i -= (i & (-i))) 
        { 
            for(int jj = j + 1 ; jj ; jj -= (jj & (-jj))) 
            { 
                ret ^= tree[i - 1][jj - 1]; 
            } 
        } 
        return ret; 
    } 
    
    int query_range(vector<vi> &tree_m, vector<vi> &tree_c, int x, int l, int r){
        
        int m = (r%2==0) ? query(tree_m, x, r) : 0;
        int c = query(tree_c, x, r);
        int ans = m ^ c;
        
        if(l){
            m = ((l-1)%2==0) ? query(tree_m, x, l-1) : 0;
            c = query(tree_c, x, l-1);
            ans ^= m ^ c;
        }
        
        return ans;
    }
    
    int query_submatrix(int x, int y){
        
        int s1 = (x%2==0) ? query_range(b1, b2, x, 0, y) : 0;
        int s2 = query_range(b3, b4, x, 0, y);

        return s1^s2;
    }
    
    int query_submatrix(int x1, int y1, int x2, int y2){
        
        int ans = query_submatrix(x2, y2);
        if(x1) ans ^= query_submatrix(x1-1, y2);
        if(y1) ans ^= query_submatrix(x2, y1-1);
        if(x1&&y1) ans ^= query_submatrix(x1-1, y1-1);
        
        return ans;
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
            x1--, y1--, x2--, y2--;
            
            tree.update_submatrix(x1, y1, x2, y2, c);
        }
        else{
            
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            
            int ans = tree.query_submatrix(x1, y1, x2, y2);
            
            cout << ans << endl;
        }
    }
}
