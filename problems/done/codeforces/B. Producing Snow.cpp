// Problem: B. Producing Snow
// Contest: Codeforces - VK Cup 2018 - Round 1
// URL: https://codeforces.com/problemset/problem/923/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
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

struct veniceSet{
    
    multiset<int> st;
    int water_level = 0;
    void add(int v){
        st.insert(water_level + v);
    }  
    void remove(int v){
        st.erase(st.find(water_level + v));
    }
    void update(int v){
        water_level += v;
    }
    int get_min(){
        return *st.begin() - water_level;
    }
    int size(){
        return st.size();
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n;
    cin >> n;
    
    vi v(n), t(n);
    for(auto &i : v) cin >> i;
    for(auto &i : t) cin >> i;
    
    veniceSet st;
    
    for(int i = 0; i < n; i++){
        
        int vi = v[i];
        int ti = t[i];
        
        st.add(vi);
        st.update(ti);
        
        int tot = ti * st.size();
        
        while(st.size() && st.get_min() < 0){
            
            int lo = st.get_min();
            
            tot -= abs(lo);
            
            st.remove(lo);
        }
        
        cout << tot << ' ';
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
