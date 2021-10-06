// Problem: G. Food Rations
// Contest: Codeforces - UTPC Contest 02-05-21 Div. 1 (Advanced)
// URL: https://codeforces.com/gym/102947/problem/G
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string num;
    cin >> num;
    
    vi cnt(10);
    for(auto c : num) cnt[c-'0']++;
    
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    
    int ans_mod = 0;
    
    string ans;
    for(int i = 9; i >= 0; i--){
        
        ans += string(cnt[i], '0'+i);
        
        while(cnt[i]--){
            ans_mod *= 10;
            ans_mod += i;
            ans_mod %= 7;
        }
    }
    
    vi tmp = {1, 6, 8, 9};
    
    do{
        
        int cur_mod = ans_mod;
        
        for(auto i : tmp){
            cur_mod *= 10;
            cur_mod += i;
            cur_mod %= 7;
        }
        
        if(!cur_mod){
            
            for(auto i : tmp){
                ans += '0'+i;
            }    
            
            break;
        }
        
    } while(next_permutation(tmp.begin(), tmp.end()));
    
    cout << ans << endl;
}
