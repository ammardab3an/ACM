// Problem: C. Maximum width
// Contest: Codeforces - Codeforces Round #704 (Div. 2)
// URL: https://codeforces.com/contest/1492/problem/C
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

int n, m;
char str0[NMAX], str1[NMAX];
vi pos[26];
int mn[NMAX];
int mx[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    cin >> str0 >> str1;
    
    for(int i = 0; i < 26; i++) pos[i].clear();
    
    for(int i = 0; i < n; i++){
        int c = str0[i] - 'a';
        pos[c].push_back(i);    
    }   
    
    {
        int cur = pos[str1[0]-'a'].front();
        mn[0] = cur;
        for(int i = 1; i < m; i++){
            int c = str1[i]-'a';
            cur = *upper_bound(pos[c].begin(), pos[c].end(), cur);
            mn[i] = cur;
        }
    }
    
    {
        int cur = pos[str1[m-1]-'a'].back();
        mx[m-1] = cur;
        for(int i = m-2; i >= 0; i--){
            int c = str1[i]-'a';
            cur = *(--lower_bound(pos[c].begin(), pos[c].end(), cur));
            mx[i] = cur;
        }
    }
    
    // for(int i = 0; i < m; i++) cout << mn[i] << ' '; cout << endl;
    // for(int i = 0; i < m; i++) cout << mx[i] << ' '; cout << endl;
    
    int ans = 0;
    for(int i = 0; i+1 < n; i++){
        ans = max(ans, mx[i+1]-mn[i]);
    }
    
    cout << ans << endl;
}
