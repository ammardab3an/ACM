
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

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
const int BLOCK = ceil(sqrt(double(NMAX)));

char str[2][5050];
int mem[2][5050][5050];

int p = 31;
int mod = MOD;

int get(bool k, int l, int r){
    
    if(l == r) return 0;
    
    int &ret = mem[k][l][r];
    if(ret+1) return ret;       
    
    int ans = mul(get(k, l+1, r), p);
    ans = add(ans, str[k][l]-'a'+1);
    
    return ret = ans;
}

int add_hash(int hash_a, int hash_b, int len_a){
    
    hash_b = mul(hash_b, pow_exp(p, len_a));
    hash_b = add(hash_b, hash_a);
    
    return hash_b;    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> str[0] >> str[1];
    
    memset(mem, -1, sizeof mem);
    
    bool found = false;
    
    int n = strlen(str[0]);
    int m = strlen(str[1]);
    
    // cout << add_hash(get(1, m-2, m), get(0, 2, n), 2) << endl;
    // cout << add_hash(get(1, 0, m-2), get(0, 0, 2), 3) << endl;
    
    for(int i = 0; i <= n && !found; i++)
    for(int j = 0; j <= m && !found; j++){
        
        if(n-i+j != m-j+i) continue;
        
        int pre_a = get(0, 0, i);
        int suf_a = get(0, i, n);
        
        int pre_b = get(1, 0, m-j);
        int suf_b = get(1, m-j, m);
        
        int hash_a = add_hash(suf_b, suf_a, j);
        int hash_b = add_hash(pre_b, pre_a, m-j);
        
        cout << i << ' ' << j << ' ' << pre_b << endl;
        
        if(hash_a == hash_b){
            
            found = true;
            
            string ans;
            for(int k = 0; k < m-j; k++) ans.push_back(str[1][k]);
            for(int k = 0; k < i  ; k++) ans.push_back(str[0][k]);
            
            cout << ans << endl;
        }
    }
    
    if(!found){
        cout << -1 << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
