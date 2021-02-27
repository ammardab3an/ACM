// Problem: B. A Trivial Problem
// Contest: Codeforces - Manthan, Codefest 16
// URL: https://codeforces.com/problemset/problem/633/B
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    vector<vi> ans(1e6+10);
    
    for(int i = 0; i < 1e6 + 10; i++){
        
        int number_of_zeros = 0;
        
        int num = i;
        int den = 5;    
        
        while(num >= den){
            
            number_of_zeros += num/den;
            den *= 5;
        }
        
        ans[number_of_zeros].push_back(i);
    }
    
    int n;
    cin >> n;
    
    cout << ans[n].size() << endl;
    for(auto i : ans[n]) cout << i << ' ';
}
