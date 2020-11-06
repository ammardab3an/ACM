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

const int MAX = 2e5 + 10;

void solve(){

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int mx = 0;

    int cnt = 0;
    for(int i = 0; i < 2*n; i++){
        if(!arr[i%n]){
            mx = max(mx, cnt);
            cnt = 0;
        }
        else
            cnt++;
    }

    cout << mx << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
