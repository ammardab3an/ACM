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

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    if(!k)
        cout << (arr[0] == 1 ? -1 : arr[0] -1);
    else if(k == n)
        cout << arr[k-1];
    else if(arr[k-1] < arr[k])
        cout << arr[k-1];
    else
        cout << -1;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
