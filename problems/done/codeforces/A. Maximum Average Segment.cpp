// Problem: A. Maximum Average Segment
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A
// Memory Limit: 512 MB
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

    int n, d;
    cin >> n >> d;
    
    vector<double> vec(n);
    for(auto &i : vec) cin >> i;
    
    vector<double> pre(n);
    vector< pair<int, double> > pre_mn(n);
    
    auto can = [&](double m){
        
        pre[0] = vec[0] - m;
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] + vec[i] - m;
        
        // cout << m << endl;
        // for(int i = 0; i < n; i++) cout << pre[i] << ' ' ; cout << endl;
        
        pre_mn[0] = {0, pre[0]};
        
        if(pre[0] > 0) pre_mn[0] = {-1, 0};
        
        for(int i = 1; i < n; i++) {
            pre_mn[i] = pre_mn[i-1];
            if(pre[i] < pre_mn[i].second){
                pre_mn[i] = {i, pre[i]};
            }
        }
        
        for(int i = d-1; i < n; i++){
            double sm = pre[i];
            if(i-d+1 > 0) sm -= pre_mn[i-d].second;
            // cout << sm << ' ' ;
            if(sm >= 0) return (pii){i-d+1 > 0 ? pre_mn[i-d].first+1 : 0, i};
        }
        
        // cout << endl;
        
        return (pii){-1, -1};
    };
    
    double l = 0;
    double r = 100.0;
    
    double ans = -1;
    int ans_l=-1, ans_r=-1;
    
    // auto tmp = can(7.5);
    // cout << tmp.first << ' ' << tmp.second << endl;
    // return 0;
    
    for(int i = 0; i < 100; i++){
        
        double m = (l+r)/2.0;
        
        auto tmp = can(m);
        
        // cout << m << ' ' << tmp.first << endl;
        
        if(tmp.first != -1){
            ans = m;
            ans_l = tmp.first;
            ans_r = tmp.second;
            l = m;
        }
        else{
            r = m;
        }
    }
    
    // cout << ans << ' ' << ans_l << ' ' << ans_r << endl;
    cout << ans_l+1 << ' ' << ans_r+1 << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    