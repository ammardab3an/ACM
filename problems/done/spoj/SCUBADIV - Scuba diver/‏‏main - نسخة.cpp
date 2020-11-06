
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int nMax  = 1e3 + 10;
const int oxMax = 21 + 10;
const int niMax = 79 + 10;

int ox, ni, n;
int arr[nMax][3];
int mem[nMax][oxMax][niMax];

int dp(){

    for(int i = 0; i < n; i++)
    for(int j = 0; j <= ox; j++)
    for(int k = 0; k <= ni; k++){

        mem[i][j][k] = 800 * nMax;

        if(j <= arr[i][0] && k <= arr[i][1])
            mem[i][j][k] = arr[i][2];

        if(i)
            mem[i][j][k] = min(mem[i][j][k], mem[i-1][j][k]),
            mem[i][j][k] = min(mem[i][j][k], mem[i-1][max(0, j-arr[i][0])][max(0, k-arr[i][1])] + arr[i][2]);
    }

    return mem[n-1][ox][ni];
}

void solve(){

	cin >> ox >> ni >> n;

	for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    cout << dp() << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
