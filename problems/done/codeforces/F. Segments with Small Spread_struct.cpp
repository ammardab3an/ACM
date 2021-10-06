// Problem: F. Segments with Small Spread
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
// Memory Limit: 1024 MB
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

struct monoQueue{
    
    stack<iii> s1, s2;
    
    int size(){
        return s1.size() + s2.size();
    }    
    
    int empty(){
        return !size();
    }
    
    void clear(){
        while(!empty()) pop();
    }
    
    int get_dif(){
        
        if(empty()){
            return 0;
        }
        if(!s1.empty() && !s2.empty()){
            return max(s1.top().second.second, s2.top().second.second) - min(s1.top().second.first, s2.top().second.first);
        }
        if(!s2.empty()){
            return s2.top().second.second - s2.top().second.first;
        }
        return s1.top().second.second - s1.top().second.first;
    }
    
    void push(int val){
        
        if(s2.empty()){
            s2.push({val, {val, val}});
        }
        else{
            s2.push({val, {min(s2.top().second.first, val), 
                           max(s2.top().second.second, val)}});
        }
    }
    
    void pop(){
        
        if(s1.empty()){
            while(!s2.empty()){
                
                if(s1.empty()){
                    s1.push({s2.top().first, {s2.top().first, s2.top().first}});
                }
                else{
                    s1.push({s2.top().first, {min(s2.top().first, s1.top().second.first), 
                                              max(s2.top().first, s1.top().second.second)}});
                }
                
                s2.pop();
            }
        }
        assert(!s1.empty());
        s1.pop();
    }
};


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    int ans = 0;
    
    monoQueue que;
    
    int r = 0;
    for(int l = 0; l < n; l++){
        
        if(l) que.pop();
        
        while(r < n && que.get_dif() <= k) que.push(vec[r++]);
        
        if(que.get_dif() <= k){
            ans += (r-1)-l+1;
        }
        else{
            ans += (r-2)-l+1;
        }
    }
    
    cout << ans << endl;
}
