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

    int n, k;
    cin >> n >> k;

    bool arr[222] = {0};

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x] = true;
    }

    int i;
    for(i = 1; k || arr[i]; i++) if(!arr[i]) k--;

    cout << i-1 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
