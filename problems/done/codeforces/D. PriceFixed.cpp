// Problem: D. PriceFixed
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.com/contest/1539/problem/D
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    multiset<pii> st;
    
    for(int i = 0; i < n; i++){
        int ai, bi;
        cin >> ai >> bi;
        st.insert({bi, ai});
    }
    
    int ans = 0;
    int cnt = 0;
    
    while(!st.empty()){
        
        if(st.size() == 1){
            
            pii p = *st.begin();
            
            int cur_cnt = p.first - cnt;
            
            int taken_2 = min(p.second, cur_cnt);
            int taken_1 = p.second - taken_2;
            
            ans += taken_2 * 2 + taken_1 * 1;
            cnt += p.second;
            
            break;
        }
        
        pii mn = *st.begin();
        pii mx = *st.rbegin();
        
        st.erase(st.begin());
        st.erase(st.find(*st.rbegin()));
        
        int cnt_mn = mn.first - cnt;
        int cnt_mx = mx.first - cnt;
        
        int taken = min(cnt_mn, mx.second);
        
        ans += taken * 2;
        cnt += taken;
        
        cnt_mn -= taken;
        cnt_mx -= taken;
        
        if(!cnt_mn){
            ans += mn.second * 1;
            cnt += mn.second;
        }
        else{
            st.insert(mn);
        }
        
        if(mx.second-taken > 0){
            st.insert({mx.first, mx.second-taken});
        }
        
        while(!st.empty() && (st.begin()->first <= cnt)){
            ans += st.begin()->second * 1;
            cnt += st.begin()->second;
            st.erase(st.begin());
        }
    }
    
    cout << ans << endl;
}
