// Problem: L. Leverage MDT
// Contest: Codeforces - 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/102428/problem/L
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University


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

const int NMAX = 1E3 + 10;

char tmp[NMAX][NMAX];
int grid[NMAX][NMAX];

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> tmp[i];

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        grid[i][j] = (j > 0) && (tmp[i][j-1] != tmp[i][j]);
        if(i) grid[i][j] += grid[i-1][j];
        if(j) grid[i][j] += grid[i][j-1];
        if(i&&j) grid[i][j] -= grid[i-1][j-1];
    }

    auto get_sub = [&](int i, int j, int x, int y){
        int ret = grid[x][y];
        if(i) ret -= grid[i-1][y];
        if(j) ret -= grid[x][j-1];
        if(i&&j) ret += grid[i-1][j-1];
        return ret;
    };

    int ans = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){

        int l = 1;
        int r = min(i+1, j+1);

        while(l <= r){

            int mid = (l+r)/2;

            if(get_sub(i-mid+1, j-mid+2, i, j) == 0){
                ans = max(ans, mid);
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }

    cout << ans*ans << endl;
}





