
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

const int MAX = 1e5 + 10;

int n, c;
int arr[MAX];

bool can(int dis){

    int cnt = 1;
    int lst = arr[0];

    for(int k = 1; k < n && cnt < c; k++) {

        if(arr[k] - lst >= dis){

            lst = arr[k], cnt++;
        }
    }

    return cnt >= c;
}

void solve(){

	cin >> n >> c;

	for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int ans = 0;

    int l = 0;
    int r = arr[n-1];

    while(l <= r){

        int mid = (l + r)/2;

        if(can(mid))
            ans = mid,
            l = mid+1;
        else
            r = mid-1;
    }

    cout << ans << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
