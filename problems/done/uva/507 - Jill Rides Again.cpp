// Problem: 507 - Jill Rides Again
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=448
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

int n;
int arr[NMAX];
int pre[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        cin >> n;
        
        arr[0] = 0;
        for(int i = 1; i < n; i++) cin >> arr[i];
        
        pre[0] = 0;
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] + arr[i];
        
        int ans_val = 0;
        int ans_dis = 0;
        int ans_l = -1, ans_r = -1;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                
                int csum = pre[j] - pre[i];
                
                if(csum > ans_val || (csum == ans_val && j-i > ans_dis)){
                    ans_val = csum;
                    ans_dis = j-i;
                    ans_l = i;
                    ans_r = j;
                }
            }
        }
        
        if(!ans_val) 
            cout << "Route " << tt++ << " has no nice parts" << endl;
        else
            cout << "The nicest part of route " << tt++ << " is between stops " << ans_l+1 << " and " << ans_r+1 << endl;
        
    }	
}
