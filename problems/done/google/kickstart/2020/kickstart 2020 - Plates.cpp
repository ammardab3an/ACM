// Problem: Plates
// Contest: Google Coding Competitions - Round A 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// 
// Powered by CP Editor (https://c...content-available-to-author-only...r.org)


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

int n, k, p;
int arr[55][55];
int mem[2020];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){

        cin >> n >> k >> p;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++) cin >> arr[i][j];
        
        for(int i = 0; i < n; i++)
        for(int j = 1; j < k; j++) arr[i][j] += arr[i][j-1];
        
        memset(mem, 0, sizeof mem);
        
        for(int i = 0; i < n; i++){
            
            for(int left = p; left >= 0; left--){
                
                int mx = mem[left];
                
                for(int j = 0; j < min(left, k); j++)
                    mx = max(mx, mem[left-j-1] + arr[i][j]);
                
                mem[left] = mx;
            }
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << mem[p] << endl;;
    }	
}
