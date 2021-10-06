// Problem: B. Mocha and Red and Blue
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/B
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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
char str[111], ans[111];
int arr[111];
int mem[111][5];

int go(int i, int lst){
    
    if(i == n) return 0;
    
    int &ret = mem[i][lst];
    if(ret + 1) return ret;
    
    if(arr[i] != 2){
        return ret = go(i+1, arr[i]) + (arr[i]==lst);
    }
    
    int st_path = go(i+1, 0) + (0==lst);
    int nd_path = go(i+1, 1) + (1==lst);
    
    return ret = min(st_path, nd_path);
}

void calc(int i, int lst){
    
    if(i == n) return;
    
    if(arr[i] != 2){
        ans[i] = arr[i];
        calc(i+1, arr[i]);
        return;
    }    
    
    if(go(i, lst) == (go(i+1, 0) + (0==lst))){
        ans[i] = 0;
        calc(i+1, 0);
    }
    else{
        ans[i] = 1;
        calc(i+1, 1);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n;
        cin >> str;
        
        for(int i = 0; i < n; i++){
            
            arr[i] = str[i] != '?' ? str[i] == 'R' ? 0 : 1 : 2;
        }
        
        memset(mem, -1, sizeof mem);
        
        calc(0, 3);
        
        for(int i = 0; i < n; i++){
            ans[i] = ans[i] == 0 ? 'R' : 'B';
        }
        
        ans[n] = 0;
        
        cout << ans << endl;
    }	
}
