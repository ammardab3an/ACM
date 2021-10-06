// Problem: Q - Flowers
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_q
// Memory Limit: 1024 MB
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
int arr[2][NMAX];
int tmp[2][NMAX];
int mem[NMAX];

int go(int pos){
    
    if(pos == n) return 0;
    
    int &ret = mem[pos];
    if(ret + 1) return ret;
    
    int ans = 0;
    
    for(int nxt = pos+1; nxt < n; nxt++) if(arr[0][pos] < arr[0][nxt]){
        ans = max(ans, go(nxt) + arr[1][nxt]);
    }
    
    return ret = ans;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n; n++;
    for(int i = 1; i < n; i++) cin >> tmp[0][i];
    for(int i = 1; i < n; i++) cin >> tmp[1][i];
    
    int lst = 0;
    int lst_idx = 0;
    
    for(int i = 1; i < n; i++){
        
        if(tmp[0][i] == lst+1){
            lst++;
            arr[1][lst_idx] += tmp[1][i];
            continue;
        }
        
        lst = tmp[0][i];
        lst_idx++;
        
        arr[0][lst_idx] = tmp[0][i];
        arr[1][lst_idx] = tmp[1][i];
    }
    
    n = lst_idx+1;
    
    // for(int i = 0; i < n; i++) cout << arr[0][i] << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << arr[1][i] << ' '; cout << endl;
    
    memset(mem, -1, sizeof mem);
     
    cout << go(0) + arr[1][0] << endl;
}
