
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e5 + 10;

int arr[55];

void solve(){

    int n;
    cin >> n;

    int oddCnt = 0;
    int evenPosCnt = 0;

    for(int i = 0; i < n; i++){

        cin >> arr[i];
        oddCnt += arr[i]%2;

        if(i % 2)
            evenPosCnt += arr[i]%2 == 0;
    }

    int evenCnt = n-oddCnt;

    if(evenCnt < oddCnt || evenCnt > oddCnt+1)
        cout << -1 << endl;
    else
        cout << evenPosCnt << endl;

}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
