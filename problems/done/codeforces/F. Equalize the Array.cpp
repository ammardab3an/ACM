// Problem: F. Equalize the Array
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.com/contest/1490/problem/F
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

int arr[NMAX];
int cnta[NMAX];
int pre[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
    
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        sort(arr, arr+n);
        
        int pst = -1;
        int cnt = -1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == pst) arr[i] = cnt;
            else pst = arr[i], cnt++, arr[i] = cnt;
            cnta[cnt]++;
        }
        
        int sz = cnt+1;

        sort(cnta, cnta+sz);

        pre[0] = cnta[0];
        for(int i = 1; i < sz; i++) pre[i] = pre[i-1] + cnta[i];
        
        // for(int i = 0; i < sz; i++) cout << cnta[i] << ' '; cout << endl;
        // for(int i = 0; i < sz; i++) cout << pre[i] << ' '; cout << endl;
        
        int ans = INF;
        
        for(int i = 0; i < sz; i++){
            
            int cans = 0;
            
            int lb = lower_bound(cnta, cnta+sz, cnta[i]) - cnta -1;
            if(lb+1) cans += pre[lb];
            
            int ub = upper_bound(cnta, cnta+sz, cnta[i]) - cnta;
            if(ub < sz) cans += pre[sz-1] - pre[ub-1] - (sz-ub) * cnta[i];
            
            ans = min(ans, cans);
        }
        
        memset(cnta, 0, sz * sizeof(cnta[0])) ;
        
        cout << ans << endl;
    }	
}
