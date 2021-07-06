#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 2e5 + 10;

const int NMAX = 550;

int n, m;
int arr[NMAX][NMAX];
int pre[5][NMAX][NMAX];

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){

        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> arr[i][j];

        memset(pre, 0, sizeof pre);

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            pre[1][i][j] = max(arr[i][j], max(pre[1][i-1][j], pre[1][i][j-1]));
        }

        for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--){
            pre[2][i][j] = max(arr[i][j], max(pre[2][i-1][j], pre[2][i][j+1]));
        }

        for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++){
            pre[3][i][j] = max(arr[i][j], max(pre[3][i+1][j], pre[3][i][j-1]));
        }

        for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--){
            pre[4][i][j] = max(arr[i][j], max(pre[4][i+1][j], pre[4][i][j+1]));
        }
//
//        for(int k = 1; k <= 4; k++){
//            for(int i = 1; i <= n; i++){
//                for(int j = 1; j <= m; j++) cout << pre[k][i][j] << ' ' ;
//                cout << endl;
//            }
//            cout << endl;
//        }

        int dif = 1e9 + 10;

        for(int i = 2; i < n; i++)
        for(int j = 2; j < m; j++){

            int mx0 = pre[1][i-1][j-1];
            int mx1 = pre[2][i-1][j+1];
            int mx2 = pre[3][i+1][j-1];
            int mx3 = pre[4][i+1][j+1];

            int mn = min({mx0, mx1, mx2, mx3});
            int mx = max({mx0, mx1, mx2, mx3});

            dif = min(dif, mx-mn);
        }

        cout << dif << endl;
    }

}