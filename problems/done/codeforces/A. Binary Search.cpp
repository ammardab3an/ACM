// Problem: A. Binary Search
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
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

    int n, k;
    cin >> n >> k;
    
    vector<int> vec(n);
    for(auto &i : vec) cin >> i;
    
    while(k--){
        
        int num;
        cin >> num;
        
        int l = 0; 
        int r = n-1;
        bool ans = false;
        
        while(l <= r){
            
            int m = (l+r)/2;
            
            if(vec[m] == num){
                ans = true;
                break;
            }
            
            else if(vec[m] > num){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }
}
