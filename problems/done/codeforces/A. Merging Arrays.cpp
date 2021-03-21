// Problem: A. Merging Arrays
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
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

    int n, m;
    cin >> n >> m;
    
    vi vec_0(n), vec_1(m), vec_res(n+m);
    
    for(auto &i : vec_0) cin >> i;
    for(auto &i : vec_1) cin >> i;
    
    int i(0), j(0), k(0);
    
    while(i < n && j < m){
        
        if(vec_0[i] < vec_1[j]){
            vec_res[k++] = vec_0[i++];
        }
        else{
            vec_res[k++] = vec_1[j++];
        }
    }
    
    while(i < n) vec_res[k++] = vec_0[i++];
    while(j < m) vec_res[k++] = vec_1[j++];
    
    for(auto i : vec_res) cout << i << ' ';
}
