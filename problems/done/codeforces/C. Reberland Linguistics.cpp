// Problem: C. Reberland Linguistics
// Contest: Codeforces - Codeforces Round #349 (Div. 2)
// URL: https://codeforces.com/problemset/problem/667/C
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

int n;
char str[NMAX];

int mem[NMAX][4];

int go(int i, int lst){
    
    if(i==n){
        return 1;
    }    
    
    int &ret = mem[i][lst];
    if(ret+1) return ret;
    
    string pst;
    for(int j = i-lst; j < i; j++) 
        pst.push_back(str[j]);
    
    int ans = false;
    
    // st_path
    
    if(i+2 <= n){
        string nxt;
        for(int j = 0; j < 2; j++)
            nxt.push_back(str[i+j]);
        
        if(nxt != pst){
            ans |= go(i+2, 2);        
        }
    }
    
    // nd_path 
    
    if(i+3 <= n){
        string nxt;
        for(int j = 0; j < 3; j++)
            nxt.push_back(str[i+j]);
        
        if(nxt != pst){
            ans |= go(i+3, 3);        
        }
    }
    
    return ret = ans;
}

bool vis[NMAX][4];
set<string> calc_st;

void calc(int i, int lst){
    
    if(i == n){
        return;
    }    
    
    if(vis[i][lst]){
        return;
    }
    else{
        vis[i][lst] = true;
    }
    
    string pst;
    for(int j = i-lst; j < i; j++) 
        pst.push_back(str[j]);
    
    
    if(i+2 <= n){
        
        string nxt;
        for(int j = 0; j < 2; j++)
            nxt.push_back(str[i+j]);
        
        if(pst != nxt && go(i+2, 2)){
            calc_st.insert(nxt);
            calc(i+2, 2);
        }
    }
    
    if(i+3 <= n){
        
        string nxt;
        for(int j = 0; j < 3; j++)
            nxt.push_back(str[i+j]);
        
        if(pst != nxt && go(i+3, 3)){
            calc_st.insert(nxt);
            calc(i+3, 3);
        }
    }
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
    
    memset(mem, -1, sizeof mem);
    
    int ans = 0;
    
    for(int i = 5; i < n; i++){
        calc(i, 0);
    }
    
    cout << calc_st.size() << endl;
    
    for(auto &s : calc_st){
        cout << s << endl;
    }
}
