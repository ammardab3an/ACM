// Problem: C. Banknotes
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int uint64_t
#define ll  uint64_t

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

// #define endl '\n'
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

int n, k;
int arr[50];
int pre[50];
int _ans[50];

int calc(int num){
    
    int ret = 0;
    
    for(int32_t  i = n-1; i >= 0; i--){
        ret += num / pre[arr[i]];
        num %= pre[arr[i]];    
    }    
    
    return ret;
}

void go(int i, int rem_k){
    
    for(int32_t d = 9; d >= 0; d--){
            
        int tmp = calc(d * pre[i]);
        
        if(tmp <= rem_k){
            
            if(d == 9){
                go(i+1, rem_k - tmp);
                break;
            }
            else{
                _ans[i] = d+1;
                int dk = calc((d+1) * pre[i]);
                if(dk > k) break;
                k -= dk;
                go(0, k);
                break;
            }
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
    
    pre[0] = 1;
    for(int i = 1; i < 20; i++){
        pre[i] = pre[i-1] * 10;
    }
    
    int t; cin >> t; while(t--){

        cin >> n >> k;
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        memset(_ans, 0, sizeof _ans);
        
        go(0, k);
        
        string ans;
        for(int i = 0; i < 30; i++){
            ans.push_back('0' + _ans[i]);
        }
        
        while((ans.size() > 1) && (ans.back()=='0')) ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        cout << ans << endl;
    }	
}
