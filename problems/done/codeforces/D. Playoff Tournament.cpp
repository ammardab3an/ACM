// Problem: D. Playoff Tournament
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int NMAX = (1 << 18) + 10;

int n, k;
string str;
pii arr[NMAX << 1];
int tree[NMAX << 1];

void build(int nd, int l, int r){
    
    arr[nd] = {l, r};
    
    if(l+1 == r){
        
        arr[nd*2+1] = {l, l};
        arr[nd*2] = {r, r};
        
        tree[nd*2] = tree[nd*2+1] = 1; 
        
        tree[nd] = 1 + (str[nd] == '?');
        
        return;
    }    
    
    int mid = (l+r)/2;
    build(nd*2+1, l, mid);
    build(nd*2, mid+1, r);
    
    if(str[nd] == '?'){
        tree[nd] = tree[nd*2] + tree[nd*2+1];
    }
    else{
        if(str[nd] == '1'){
            tree[nd] = tree[nd*2];
        }
        else{
            tree[nd] = tree[nd*2+1];
        }
    }
}

void update(int nd, int l, int r, int q_l, int q_r, int p, char val){
    
    if(l > q_r || q_l > r) return;
    
    if(p == nd){
        
        str[nd] = val;
        
        if(str[nd] == '?'){
            tree[nd] = tree[nd*2] + tree[nd*2+1];
        }
        else{
            if(str[nd] == '1'){
                tree[nd] = tree[nd*2];
            }
            else{
                tree[nd] = tree[nd*2+1];
            }
        }
        
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2+1, l, mid, q_l, q_r, p, val);
    update(nd*2, mid+1, r, q_l, q_r, p, val);
    
    if(str[nd] == '?'){
        tree[nd] = tree[nd*2] + tree[nd*2+1];
    }
    else{
        if(str[nd] == '1'){
            tree[nd] = tree[nd*2];
        }
        else{
            tree[nd] = tree[nd*2+1];
        }
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> k >> str;
    n = 1 << k;
    
    str.push_back('#');
    reverse(str.begin(), str.end());
    
    build(1, 1, n);
    
    int q; cin >> q; while(q--){
        
        int p;
        char val;
        cin >> p >> val;
        
        p = n-p;
        
        update(1, 1, n, arr[p].first, arr[p].second, p, val);
        
        cout << tree[1] << endl;
    }
    
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
