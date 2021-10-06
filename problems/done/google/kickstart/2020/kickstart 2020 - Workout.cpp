// Problem: Workout
// Contest: Google Coding Competitions - Round A 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

// #define endl '\n'
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

int n, k;
int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){
        
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        int l = 1;
        int r = 1e9 + 10;
        
        int ans = -1;
        
        auto can = [&](int m){
            
            int i = 1;
            int cnt = 0;
            int lst = arr[0];
            
            while(i < n){
                
                if(arr[i] - lst > m){
                    lst = lst + m;
                    cnt++;
                }
                else{
                    lst = arr[i];
                    i++;
                }
            }
            
            return cnt <= k;  
        };
        
        while(l <= r){
            
            int m = (l+r)/2;
            
            if(can(m)){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << ans << endl;
    }	
}
