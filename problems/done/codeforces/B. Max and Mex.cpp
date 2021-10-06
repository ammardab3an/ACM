// Problem: B. Max and Mex
// Contest: Codeforces - Codeforces Round #706 (Div. 2)
// URL: https://codeforces.com/contest/1496/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;

        set<int> st;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            st.insert(num);
        }

        int mx = *st.rbegin();

        int mex = -1;
        
        int j = 0;

        if(k) for(auto i : st){
           if(i != j++){
              mex = j-1;
              break;
           }
        } 

        if(mex == -1){
            cout << n+k << endl;
        } 
        else{
            st.insert((mx+mex+1)/2);
            cout << st.size() << endl;
        }
    }	
}