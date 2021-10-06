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
int grid[111][111];

void solve(){

    int n, m, kk;
    cin >> n >> m >> kk;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){

        cin >> grid[i][j];

        if(i > 0) grid[i][j] += grid[i-1][j];
        if(j > 0) grid[i][j] += grid[i][j-1];
        if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
    }

    int ans = 0;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if((n-i) * (m-j) > ans)
    for(int k = i; k < n; k++) if((k-i+1) * (m-j) > ans) for(int l = j; l < m; l++){

        int area = (k-i+1) * (l-j+1);

        if(area > ans){

            int cnt = grid[k][l];

            if(i > 0) cnt -= grid[i-1][l];
            if(j > 0) cnt -= grid[k][j-1];
            if(i > 0 && j > 0) cnt += grid[i-1][j-1];

            if(cnt <= kk)
                ans = area;
        }
    }

    cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
