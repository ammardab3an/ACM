
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
 
 
// J - Jail Destruction
// https://codeforces.com/gym/102307/problem/J

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
 
const int NMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));
const int MAX_BLOCK = NMAX/BLOCK + 1;

int n, q;
int arr[NMAX];

struct my_set{
    
    vector<pii> mst;
    int water_level = 0;
    int sum = 0;
    
    void rebuild(int b){
        
        mst.clear();
        sum = water_level = 0;
        
        int mx = min(n, (b+1)*BLOCK);
        for(int i = b*BLOCK; i < mx; i++){
            if(arr[i]){
                sum += arr[i];
                mst.push_back({arr[i], i});
            }    
        }    
        
        sort(mst.begin(), mst.end());
        reverse(mst.begin(), mst.end());
    }
    
    void fill(){
        for(auto [v, i] : mst){
            arr[i] = v-water_level;
        }
    }  
    
    void clear(){
        fill();
        mst.clear();
        sum = 0;
    }   
    
    void dec(int val){
        
        while(mst.size() && (mst.back().first-water_level-val) <= 0){
            arr[mst.back().second] = 0;
            sum -= mst.back().first-water_level;
            mst.pop_back();
        }
        
        water_level += val;
        sum -= mst.size() * val;
    }   
};

my_set st[MAX_BLOCK];

void build(){
    for(int i = 0; i*BLOCK < n; i++){
        st[i].rebuild(i);
    }
}

void update(int l, int r, int val){
    
    int lb = l/BLOCK;
    int rb = r/BLOCK;
    st[lb].clear();
    st[rb].clear();
    
    if(lb==rb){
        
        for(int i = l; i <= r; i++){
            arr[i] = max(int(0), arr[i]-val);
        }    
        
        st[lb].rebuild(lb);
        return;
    }
    
    int mx = mx = min(n, (lb+1)*BLOCK);
    for(int i = l; i < mx; i++){
        arr[i] = max(int(0), arr[i]-val);
    }    
    
    st[lb].rebuild(lb);
    
    for(int i = lb+1; i < rb; i++){
        st[i].dec(val);
    }
    
    for(int i = rb*BLOCK; i <= r; i++){
        arr[i] = max(int(0), arr[i]-val);
    }
    
    st[rb].rebuild(rb);
}

int query(int l, int r){
     
    int lb = l/BLOCK;
    int rb = r/BLOCK;
    st[lb].fill();
    st[rb].fill();
    
    int ret = 0;
    
    if(lb==rb){
        for(int i = l; i <= r; i++){
            ret += arr[i];
        }    
        return ret;
    }
    
    int mx = min(n, (lb+1)*BLOCK);
    for(int i = l; i < mx; i++){
        ret += arr[i];
    }    
    
    for(int i = lb+1; i < rb; i++){
        ret += st[i].sum;
    }
    
    for(int i = rb*BLOCK; i <= r; i++){
        ret += arr[i];
    }
    
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    build();
    
    while(q--){
        
        int ty;
        cin >> ty;
        
        if(ty == 1){
            
            int a, b;
            cin >> a >> b;
            a--, b--;
            
            if(a <= b){
                int que = query(a, b);
                cout << que << endl;
            }
            else{
                int st_path = query(a, n-1);
                int nd_path = query(0, b);
                int que = st_path + nd_path;
                cout << que << endl;
            }
        }    
        else{
            
            int a, b, val;
            cin >> a >> b >> val;
            a--, b--;
            
            if(a <= b){
                update(a, b, val);
            }
            else{
                update(a, n-1, val);
                update(0, b, val);
            }
        }
        
        // for(int i = 0; i < n; i++){
            // cout << query(i, i) << ' ';
        // } cout << endl; 
    }
}
