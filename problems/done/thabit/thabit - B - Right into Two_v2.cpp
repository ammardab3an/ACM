
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

const int p = 31;

int n, m;
char str[2][5050];
int suf_hash[2][5050];

inline int get(bool k, int l, int r){
    
    int ret = suf_hash[k][l];
    
    if((!k && r < n) || (k && r < m)){
        int tmp = suf_hash[k][r];
        tmp = mul(tmp, pow_exp(p, r-l));
        ret = add(ret, -tmp);
    }
    
    return ret;
}

inline int add_hash(int hash_a, int hash_b, int len_a){
    
    hash_b = mul(hash_b, pow_exp(p, len_a));
    hash_b = add(hash_b, hash_a);
    
    return hash_b;    
}

int32_t main(){
    
    fastIO;
    
    cin >> str[0] >> str[1];
    
    // init
    
    n = strlen(str[0]);
    m = strlen(str[1]);
    
    suf_hash[0][n-1] = str[0][n-1]-'a'+1;
    suf_hash[1][m-1] = str[1][m-1]-'a'+1;
    
    for(int i = n-2; i >= 0; i--){
        suf_hash[0][i] = add(str[0][i]-'a'+1, mul(suf_hash[0][i+1], p));
    }
    for(int i = m-2; i >= 0; i--){
        suf_hash[1][i] = add(str[1][i]-'a'+1, mul(suf_hash[1][i+1], p));
    }
    
    // brute force
    
    int _i, _j;
    int mn = min(n, m);
    
    if(n >= m){
        _i = (n-m)/2;
        _j = 0;
    }
    else{
        _i = 0;
        _j = (m-n)/2;
    }
    
    bool found = false;
    for(int l = 0; l <= mn && !found; l++){
        
        int i = l + _i;
        int j = l + _j;
        
        int pre_a = get(0, 0, i);
        int suf_a = get(0, i, n);
        
        int pre_b = get(1, 0, m-j);
        int suf_b = get(1, m-j, m);
        
        int hash_a = add_hash(suf_b, suf_a, j);
        int hash_b = add_hash(pre_b, pre_a, m-j);
        
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
