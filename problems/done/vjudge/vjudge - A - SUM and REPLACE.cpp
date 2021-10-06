// Problem: A - SUM and REPLACE
// Contest: Virtual Judge - Contest 3
// URL: https://vjudge.net/contest/437298#problem/A
// Memory Limit: 262 MB
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
 
const int NMAX = 3e5 + 10;
const int MAXN = 1e6 + 10;
  
// stores smallest prime factor for every number
int spf[MAXN];
  
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
  
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
  
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
  
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
  
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

int n, q;
int arr[NMAX];
int mem[MAXN];
int tree[NMAX << 2];
int foo[NMAX << 2];

void build(int nd, int l, int r){
    if(l == r){
        tree[nd] = arr[l];
        foo[NMAX << 2] = arr[l] <= 2;
        return;
    }
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    tree[nd] = tree[nd*2] + tree[nd*2+1];
    foo[nd] = foo[nd*2] + foo[nd*2+1];
}

void update(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        
        if(foo[nd] == (r-l+1)) return;
        
        if(l == r){
            tree[nd] = mem[tree[nd]];
            foo[nd] = tree[nd] <= 2;
            return;
        }
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r);
    update(nd*2+1, mid+1, r, q_l, q_r);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
    foo[nd] = foo[nd*2] + foo[nd*2+1];
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return 0;
    
    if(q_l <= l && r <= q_r) return tree[nd];
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return stPath + ndPath;
}

int get(int n){
    
    int ret = 1;
    
    int pst = -1;
    int cnt = 0;
    
    while(n != 1){
        
        if(spf[n] == pst){
            cnt++;
            n /= pst;
        }    
        else{
            ret *= cnt+1;
            pst = spf[n];
            cnt = 1;
            n /= pst;
        }
    }    
    
    ret *= cnt+1;
    
    return ret;
}

void init(){
    mem[1] = 1;
    for(int i = 2; i < MAXN; i++) mem[i] = get(i);    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    sieve();
    init();
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    build(1, 1, n);
    
    while(q--){
        
        int i, l, r;
        cin >> i >> l >> r;
        
        if(i == 1){
            update(1, 1, n, l, r);
        }
        else{
            cout << query(1, 1, n, l, r) << endl;
        }
    }	
    
}    
/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    