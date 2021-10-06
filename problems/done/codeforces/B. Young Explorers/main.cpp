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

int arr[MAX];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int cnt = 0;

    for(int i = 0; i < n;){

        int sz = 1;
        int mx = arr[i++];

        while(i < n && sz < mx){
            mx = max(mx, arr[i]);
            sz++; i++;
        }

        if(sz == mx) cnt++;
    }

    cout << cnt << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
