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

const int MAX = 2e3 + 10;
const int MOD = 1e9 + 7;

int dp[MAX][MAX];

int add(int & x, int y){
    return x = ((x % MOD) + (y % MOD)) % MOD;
}

void solve(){

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) dp[1][i] = 1;

    for(int i = 1; i <  k; i++)
    for(int j = 1; j <= n; j++) // if(dp[i][j])
    for(int j2 = j; j2 <= n; j2 += j)
        add(dp[i+1][j2], dp[i][j]);

    int ans = 0;
    for(int j = 1; j <= n; j++)
        add(ans, dp[k][j]);

    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
