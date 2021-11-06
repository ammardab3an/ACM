// Problem: D. Blue-Red Permutation
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/D
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

pii tree[NMAX << 2];
int lazy[NMAX << 2];

void clear_seg(int nd, int l, int r){

    tree[nd] = {0, l};
    lazy[nd] = 0;
    if(l == r) return;    
    
    int mid = (l+r)/2;
    clear_seg(nd*2, l, mid);
    clear_seg(nd*2+1, mid+1, r);
    
    tree[nd] = tree[nd*2];
}

void push(int nd, int l, int r){
    
    if(lazy[nd] == 0){
        return;
    }    
    
    tree[nd].first += lazy[nd];
    
    if(l != r){
        lazy[nd*2] += lazy[nd];
        lazy[nd*2+1] += lazy[nd];
    }
    
    lazy[nd] = 0;
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }
    
    if(q_l <= l && r <= q_r){
        lazy[nd] += val;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = min(tree[nd*2], tree[nd*2+1]);    
}

void update_ele(int nd, int l, int r, int p, int val){
    
    push(nd, l, r);
    
    if(p < l || r < p){
        return;
    }    
    
    if(l==r){
        tree[nd] = {val, l};
        return;
    }
    
    int mid = (l+r)/2;
    update_ele(nd*2, l, mid, p, val);
    update_ele(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = min(tree[nd*2], tree[nd*2+1]);        
}

pii query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return {INF, INF};
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    pii st_path = query(nd*2, l, mid, q_l, q_r);
    pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        vi vec(n);
        for(auto &i : vec) cin >> i;
        
        string cols;
        cin >> cols;
        
        clear_seg(1, 1, n);
        
        bool bad = false;
        
        vpii tmp;
        
        for(int i = 0; i < n; i++){
            
            int l, r;
            
            if(cols[i]=='B'){
                
                if(vec[i] <= 0){
                    bad = true;
                    break;
                }
                
                l = 1;
                r = min(vec[i], n);
            }
            else{
                
                if(vec[i] > n){
                    bad = true;
                    break;
                }
                
                l = max(vec[i], (int)1);
                r = n;    
            }
            
            tmp.push_back({l, r});     
            update(1, 1, n, l, r, +1);
        }
        
        
        if(bad){
            cout << "NO" << endl;
            continue;
        }
        
        sort(tmp.begin(), tmp.end(), [&](const pii &a, const pii &b){
            return (a.second-a.first+1) < (b.second-b.first+1);
        });
        
        for(int i = 0; i < n; i++){
            
            int l = tmp[i].first;
            int r = tmp[i].second;
            
            pii mn = query(1, 1, n, l, r);
            
            if(mn.first <= 0){
                bad = true;
                break;
            }
            
            update(1, 1, n, l, r, -1);
            update_ele(1, 1, n, mn.second, INF);
            
            // for(int i = 1; i <= n; i++){
                // cout << query(1, 1, n, i, i).first << ' ';
            // } cout << endl;
            
        }
        
        // cout << bad << ' ' << query(1, 1, n, 1, n).first < n << endl;
        
        bad = bad || (query(1, 1, n, 1, n).first < n);
        
        if(bad){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }	
}
