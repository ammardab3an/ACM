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

lli arr[MAX];

void solve(){

    lli n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    lli ans = 0;
    map<lli, lli> mp0, mp1;

    for(int i = 1; i < n; i++)
        mp1[arr[i]]++;

    for(int i = 1; i < n-1; i++){

        mp0[arr[i-1]]++;
        mp1[arr[i]]--;

        if(arr[i] % k) continue;

        lli cnt0 = mp0[arr[i]/k];
        lli cnt1 = mp1[arr[i]*k];

        ans += cnt0 * cnt1;
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
