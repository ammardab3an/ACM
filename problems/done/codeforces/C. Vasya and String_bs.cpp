// Problem: C. Vasya and String
// Contest: Codeforces - Codeforces Round #354 (Div. 2)
// URL: https://codeforces.com/problemset/problem/676/C
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

int n, k;
char str[NMAX];
int pre[2][NMAX];


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> k >> str;
    
    string ab = "ab";
    
    for(int i : {0, 1}){
        
        pre[i][0] = str[0] != ab[i];
        for(int j = 1; j < n; j++) pre[i][j] = pre[i][j-1] + (str[j] != ab[i]);
    }
    
    int mxAns = 0;
    
    auto can = [&](int i, int j){
        
        int tot[2];
        tot[0] = pre[0][j];
        tot[1] = pre[1][j];
        if(i) tot[0] -= pre[0][i-1], tot[1] -= pre[1][i-1];
        
        return min(tot[0], tot[1]) <= k;
    };
    
    for(int i = 0; i < n; i++){
        
        int l = i;
        int r = n-1;
        int ans = -1;
        
        while(l <= r){
            int m = (l+r)/2;
            if(can(i, m)){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        
        mxAns = max(mxAns, (ans-i+1));
    }
    
    cout << mxAns << endl;
}
