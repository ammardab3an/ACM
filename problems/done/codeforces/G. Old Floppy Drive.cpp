// Problem: G. Old Floppy Drive
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1490/G
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

int n, m;
int arr[NMAX];
lli pre[NMAX];
int idx[NMAX], sz;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        // init
        sz = 0;

        cin >> n >> m;
        
        lli csum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            csum += arr[i];
            if(!sz || pre[sz-1] < csum){
                pre[sz] = csum;
                idx[sz] = i;
                sz++;
            }
        }
        
        while(m--){
            
            lli x;
            cin >> x;
            
            if(csum <= 0 && pre[sz-1] < x){
                cout << -1 << ' ';
                continue;
            }
            
            int laps = 0;
 
            if(pre[sz-1] < x){
                laps = (x - pre[sz-1] + csum-1) / csum;
                x -= laps * csum;
            }
            
            cout << lli(laps) * n + idx[lower_bound(pre, pre+sz, x) - pre] << ' ';
        }
        
        cout << endl;
    }
}
