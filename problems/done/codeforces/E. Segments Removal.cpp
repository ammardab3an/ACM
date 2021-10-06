// Problem: E. Segments Removal
// Contest: Codeforces - Codeforces Round #452 (Div. 2)
// URL: https://codeforces.com/problemset/problem/899/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vector<iii> tmp;
    
    int cnt = 1;
    int idx = 0;
    int lst = vec[0];
    
    for(int i = 1; i < n; i++){
        
        if(vec[i] != lst){
            tmp.push_back({idx, {cnt, lst}});
            idx = i;
            lst = vec[i];
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    
    tmp.push_back({idx, {cnt, lst}});
    
    // for(auto p : tmp) cout << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
    
    set<iii> st, sst;
    for(auto p : tmp) st.insert(p);
    for(auto p : tmp) sst.insert({-p.second.first, {p.first, p.second.second}});
    
    int ans = 0;
    
    while(!st.empty()){
        
        ans++;
        
        auto tp = *sst.begin();
        sst.erase(sst.begin());
        
        tp.first *= -1;
        swap(tp.first, tp.second.first);
        auto it = st.find(tp);
        
        if(it != st.begin() && it != st.end()){
            
            auto be = it; be++;
            auto af = it; af--;
            
            if(be->second.second == af->second.second){
                
                auto be_p = *be;
                auto af_p = *af;
                
                st.erase(be);
                st.erase(af);
                
                iii res;
                res.first = be_p.first;
                res.second.first = be_p.second.first + af_p.second.first;
                res.second.second = be_p.second.second;
                
                swap(be_p.first, be_p.second.first);
                swap(af_p.first, af_p.second.first);
                
                be_p.first *= -1;
                af_p.first *= -1;
                
                sst.erase(sst.find(be_p));
                sst.erase(sst.find(af_p));
                
                st.insert(res);
                swap(res.first, res.second.first);
                res.first *= -1;
                sst.insert(res);
            }
        }
        
        st.erase(it);
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
