// Problem: B. Password
// Contest: Codeforces - Codeforces Beta Round #93 (Div. 1 Only)
// URL: https://codeforces.com/contest/126/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int NMAX = 1e6 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
char str[NMAX];

int md[] = {(int)1e9+7, (int)1e9+9};
int pr[] = {29, 31};
int power[2][NMAX];
int suf[2][NMAX];

void hash_init(int k){
    
    int m = md[k];
    int p = pr[k];
    
    power[k][0] = 1;
    for(int i = 1; i < n; i++){
        power[k][i] = (power[k][i-1] * p) % m;
    }
    
    suf[k][n-1] = (str[n-1]-'a'+1) % m;
    for(int i = n-2; i >= 0; i--){
        suf[k][i] = (suf[k][i+1] * p + (str[i]-'a'+1)) % m;
    }
}

int get_sub_hash(int k, int l, int r){
    
    int ret = suf[k][l];
    int m = md[k];
    
    if(r < n-1){
        int tmp = suf[k][r+1];
        tmp = (tmp * power[k][r-l+1]) % m;
        ret = (ret - tmp + m) % m;    
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
    
    cin >> str;
    n = strlen(str);
    
    hash_init(0);
    hash_init(1);
    
    int found = false;
    int ans_idx, ans_len;
    
    for(int len = n; len >= 1; len--){
        
        vi pre_hash = {get_sub_hash(0, 0, len-1), get_sub_hash(1, 0, len-1)};
        vi suf_hash = {get_sub_hash(0, n-len, n-1), get_sub_hash(1, n-len, n-1)};
        
        if(pre_hash != suf_hash) continue;
        
        for(int i = 1; i+len-1 < n-1; i++){
            
            vi mid_hash = {get_sub_hash(0, i, i+len-1), get_sub_hash(1, i, i+len-1)};
            
            if(mid_hash == pre_hash){
                found = true;
                ans_len = len;
                ans_idx = i;
            }
        }
        
        if(found) break;
    }
    
    if(!found){
        cout << "Just a legend" << endl;
    }
    else{
        for(int i = 0; i < ans_len; i++){
            cout << str[ans_idx+i];
        }
        cout << endl;
    }
}
