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

const int MAX = 1e3 + 10;

char grid[MAX][MAX];

void solve(){

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    if(2*x < y) y = 2*x;

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    int ans = 0;

    int cnt = 0;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(grid[i][j] == '.'){
                cnt++;
            }
            else{
                ans += cnt/2 * y + (cnt%2) * x;
                cnt = 0;
            }
        }

        if(cnt) ans += cnt/2 * y + (cnt%2) * x;
        cnt = 0;
    }

    if(cnt) ans += cnt/2 * y + (cnt%2) * x;
    cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
