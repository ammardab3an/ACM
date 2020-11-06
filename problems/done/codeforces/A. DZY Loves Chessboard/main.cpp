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

const int MAX = 100 + 10;

char grid[MAX][MAX];

void solve(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '-')
                grid[i][j] = (vector<string>){"BW", "WB"}[j%2][i%2];
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
