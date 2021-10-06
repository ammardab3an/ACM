// Problem: C2. Potions (Hard Version)
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/contest/1526/problem/C2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
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

int n, sz;
int arr[NMAX], tmp[NMAX];

int tree[NMAX << 2];

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        tree[nd] += val;
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
}

int query(int nd, int l, int r, int p){
    
    if(p < l || r < p) return 0;
    
    if(l == r) return tree[nd];
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, p);
    int ndPath = query(nd*2+1, mid+1, r, p);    
    
    return tree[nd] + stPath + ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        
        cin >> arr[i];   
        if(arr[i] >= 0){
            update(1, 1, n, i, n, arr[i]);
        }
        else{
            tmp[sz++] = i;
        }
        
    }
    
    priority_queue <pii> taken;
    
    for(int i = 0; i < sz; i++){
        
        int p = tmp[i];
        int v = arr[p];
        
        int que = query(1, 1, n, p);
        
        // cout << p << ' ' << v << ' ' << que << endl;
        
        if(arr[p]+que >= 0){
            taken.push({-arr[p], p});
            update(1, 1, n, p, n, arr[p]);
        }
        
        else{
            
            int dif = arr[p]+que;
            
            if(taken.size()){
                
                pii tp = taken.top();
                
                if(-tp.first < arr[p]){
                    
                    update(1, 1, n, tp.second, n, tp.first);
                    taken.pop();
                    
                    update(1, 1, n, p, n, arr[p]);
                    taken.push({-arr[p], p});
                }
            }
        }
    }
    
    cout << n-sz+taken.size() << endl;
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
