// Problem: E. Accidental Victory
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.com/contest/1490/problem/E
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

int arr[NMAX];
int pre[NMAX];
int pos[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) 
            cin >> arr[i];
        
        for(int i = 0; i < n; i++)
            pos[i] = i;
            
        auto cmp = [&](int i, int j){
            return arr[i] < arr[j];
        };
        
        sort(pos, pos+n, cmp);
        
        pre[0] = arr[pos[0]];
        for(int i = 0; i < n; i++) pre[i] = pre[i-1] + arr[pos[i]];
        
        vi ans;
        ans.push_back(pos[n-1]);
        
        for(int i = n-2; i >= 0; i--){
            if(arr[pos[i+1]] <= pre[i]) ans.push_back(pos[i]);
            else break;
        }
        
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for(auto i : ans) cout << i+1 << ' '; cout << endl;

    }	
}