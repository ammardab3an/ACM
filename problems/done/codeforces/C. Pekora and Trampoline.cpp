// Problem: C. Pekora and Trampoline
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

    int t; cin >> t; while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        memset(pre, 0, n * sizeof(pre[0]));
        
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += pre[i];
            ans += max(int(0), arr[i]-1 -sum);
            
            int cnt = max(sum, arr[i]-1);
            
            if(cnt){
                pre[i+2] += 1;
                pre[i+min(arr[i],int(5555))+1] -= 1;
            }
            
            if(cnt > arr[i]-1){
                pre[i+1] += cnt - (arr[i]-1);
                pre[i+2] -= cnt - (arr[i]-1);
            }
        }
        
        cout << ans << endl;
    }	
}