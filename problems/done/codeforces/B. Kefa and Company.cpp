// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 1e5 + 10;

pii arr[MAX];
int mon[MAX];
int fac[MAX];
lli sum[MAX];

void solve(){

    int n, d;
    cin >> n >> d;

    for(int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr+n+1);

    for(int i = 1; i <= n; i++){
        mon[i] = arr[i].first;
        fac[i] = arr[i].second;
        sum[i] = arr[i].second + sum[i-1];
    }


    lli ans = 0;
    for(int i = 1; i <= n; i++){
        int j = lower_bound(mon, mon+n+1, arr[i].first + d) - mon;
        ans = max(ans, sum[j-1] - sum[i-1]);
    }

    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}

