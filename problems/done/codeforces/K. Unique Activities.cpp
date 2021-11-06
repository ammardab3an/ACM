// Problem: K. Unique Activities
// Contest: Codeforces - 2020-2021 ICPC Southwestern European Regional Contest (SWERC 2020)
// URL: https://codeforces.com/gym/103081/problem/K
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

inline int mul(int a, int b, int MOD){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
inline int add(int a, int b, int MOD){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
const int NMAX = 3e5 + 10;

int n;
char str[NMAX];
int pre_hash[NMAX], p_pow[NMAX];

int p = 31;
int m = 1e9 + 9;

void calc_hash(){
        
    pre_hash[0] = str[0]-'A'+1;
    for(int i = 1; i < n; i++){
        pre_hash[i] = add(mul(pre_hash[i-1], p, m), str[i]-'A'+1, m);
    }    
    
    p_pow[0] = 1;
    for(int i = 1; i <= n; i++){
        p_pow[i] = mul(p_pow[i-1], p, m);
    }
}

int get_sub_hash(int l, int r){
    
    int ret = pre_hash[r];
    
    if(l){
        int t = pre_hash[l-1];
        t = mul(t, p_pow[r-l+1], m);
        ret = add(ret, mul(-1, t, m), m);
    }    
    
    return ret;
}

int found(int len){
    
    vector<map<int, int> > vec(10000);
    
    for(int i = 0; i+len-1 < n; i++){
        
        int cur_hash = get_sub_hash(i, i+len-1);
        
        auto &mp = vec[cur_hash%10000];
        auto it = mp.lower_bound(cur_hash);
        
        if((it != mp.end()) && ((it->first) == cur_hash)){
            mp[cur_hash] = INF;
        }
        else{
            mp[cur_hash] = i;
        }
    }
    
    int ret = INF;
    for(auto &mp : vec)
    for(auto p : mp) ret = min(ret, p.second);
    if(ret == INF) ret = -1;
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
    
    calc_hash();
    
    int l = 0;
    int r = n;
    
    int ans_len = 0;
    int ans_pos = 0;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        int tmp = found(mid);
        
        if(tmp != -1){
            ans_len = mid;
            ans_pos = tmp;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    string ans;
    for(int i = 0; i < ans_len; i++){
        ans.push_back(str[ans_pos+i]);
    }
    
    cout << ans << endl;
}

