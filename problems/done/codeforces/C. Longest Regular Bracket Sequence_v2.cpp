// Problem: C. Longest Regular Bracket Sequence
// Contest: Codeforces - Codeforces Beta Round #5
// URL: https://codeforces.com/problemset/problem/5/C
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string str;
    cin >> str;
    
    int n = str.size();
    
    int ans_len = 0;
    int ans_cnt = 1;
    
    stack<int> st;
    vector<int> c(n, -1), d(n, -1);
    
    for(int i = 0; i < n; i++){
        
        if(str[i] == '('){
            st.push(i);
        }
        else{
            
            if(st.empty()){
                c[i] = d[i] = -1;
            }
            else{
                
                d[i] = c[i] = st.top();
                st.pop();
                
                if(d[i]-1 >= 0 && str[d[i]-1] == ')'){
                    if(c[d[i]-1] != -1){
                        c[i] = c[d[i]-1];
                    }
                }
                
                int cur_len = i-c[i]+1;
                
                if(ans_len < cur_len){
                    ans_len = cur_len;
                    ans_cnt = 1;
                }
                else if(ans_len == cur_len){
                    ans_cnt++;
                }
            }
        }
    }
    
    cout << ans_len << ' ' << ans_cnt << endl;
}
