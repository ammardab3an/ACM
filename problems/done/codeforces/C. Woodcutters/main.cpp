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

int n;
int pos[MAX];
int hig[MAX];
int dp[MAX][3];

void solve(){

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> pos[i] >> hig[i];

    pos[0]   = INT_MIN;
    pos[n+1] = INT_MAX;

   for(int i = 1; i <= n; i++){

        dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));

        dp[i][0] = dp[i-1][0];
        if(pos[i] - hig[i] > pos[i-1])              dp[i][0] = max(dp[i-1][0], dp[i-1][2]) + 1;
        if(pos[i] - hig[i] > pos[i-1] + hig[i-1])   dp[i][0] = max(dp[i][0]  , dp[i-1][1] + 1);

        if(pos[i] + hig[i] < pos[i+1])
            dp[i][1] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])) + 1;
   }

    cout << dp[n][1];
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
