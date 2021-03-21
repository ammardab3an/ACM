// Problem: K-Goodness String
// Contest: Google Coding Competitions - Round A 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cca3
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
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        int n, k;
        cin >> n >> k;
        
        string str;
        cin >> str;
        
        int i = 0;
        int j = n-1;
        
        int cnt = 0;
        
        while(i < j){
            if(str[i] != str[j]) cnt++;
            i++;
            j--;
        }
        
        int ans = abs(k-cnt);
         
        cout << "Case #" << tt++ << ": ";
        cout << ans << endl;
    }	
}
