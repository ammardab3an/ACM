// Problem: Festival
// Contest: Google Coding Competitions - Round F 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887dba
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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
 
const int HMAX = 3e5 + 10;

struct node{
    int sm;
    int sz;
    node(){
        sm=sz=0;
    }
} tree[HMAX << 2];

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p){
        return;
    }
    
    if(l == r){
        tree[nd].sz += val;
        tree[nd].sm = tree[nd].sz * l;
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd].sz = tree[nd*2].sz + tree[nd*2+1].sz;
    tree[nd].sm = tree[nd*2].sm + tree[nd*2+1].sm;
}

int bs(int nd, int l, int r, int k){
    
    if(l==r){
        assert(tree[nd].sz >= k);
        return k * l;    
    }
    
    int mid = (l+r)/2;
    
    if(tree[nd*2+1].sz >= k){
        return bs(nd*2+1, mid+1, r, k);
    }
    else{
        int st_path = bs(nd*2, l, mid, k-tree[nd*2+1].sz);
        int nd_path = tree[nd*2+1].sm;
        return st_path + nd_path;
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int tt = 0;
    int t; cin >> t; while(t--){
    
        cout << "Case #" << ++tt << ": ";
        
        int n, d, k;
        cin >> d >> n >> k;
        
        vector<vi> vec(d+1);
        
        for(int i = 0; i < n; i++){
            
            int h, l, r;
            cin >> h >> l >> r;
            l--, r--;
            
            vec[l].push_back(h);
            vec[r+1].push_back(-h);
        }
        
        int ans = 0;
        
        for(int i = 0; i <= d; i++){
            
            for(auto e : vec[i]){
                
                if(e >= 0){
                    update(1, 0, HMAX-1, e, +1);
                }
                else{
                    update(1, 0, HMAX-1, -e, -1);
                }
            }
            
            int cans = bs(1, 0, HMAX-1, min(k, tree[1].sz));
            ans = max(ans, cans);
        }
        
        cout << ans << endl;
    }	
}
