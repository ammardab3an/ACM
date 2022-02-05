
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
int arr[NMAX];
int ccc[NMAX];
int ans[NMAX];

int vis[NMAX];
int idx[NMAX];
vi idxs[NMAX];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n >> m;

        memset(vis, -1, n * sizeof(vis[0]));
        memset(idx, -1, n * sizeof(idx[0]));
        for(int i = 0; i < n; i++) idxs[i].clear();

        for(int i = 0; i < n; i++){
            cin >> arr[i]; arr[i]--;
        }

        for(int i = 0; i < n; i++){

            int col;
            cin >> col; col--;

            if(arr[i] != col){
                idxs[col].push_back(i);
                idx[col]++;
            }
            else{
                vis[col] = i;
            }
        }

        for(int i = 0; i < m; i++) cin >> ccc[i];

        int tmp = -1;
        bool b = true;

        for(int i = m-1; i >= 0; i--){

            int col = ccc[i]-1;

            if(idx[col] == -1){

                if(vis[col] != -1){
                    ans[i] = vis[col];
                    if(tmp == -1) tmp = ans[i];
                }
                else if(tmp != -1){
                    ans[i] = tmp;
                }
                else{
                    b = false;
                    break;
                }
            }
            else{
                ans[i] = idxs[col][idx[col]--];
                if(tmp == -1) tmp = ans[i];
            }
        }

        if(b) for(int i = 0; i < n; i++) if(idx[i] != -1) {
            b = false;
            break;
        }

        if(b){
            cout << "YES" << endl;
            for(int i = 0; i < m; i++) cout << ans[i]+1 << ' '; cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
