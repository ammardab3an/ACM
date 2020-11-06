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

pii arr[MAX];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    map<int, map<int, int> > mp;

    for(int i = 0; i < n; i++){
        mp[arr[i].first][arr[i].second]++;
        mp[arr[i].second][arr[i].first]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){

        ans += mp[arr[i].first].size()-1;
        ans += mp[arr[i].second].size()-1;

        for(auto p : mp[arr[i].first])
            if(mp[arr[i].second][p.first])
                ans -= min(mp[arr[i].second][p.first], mp[arr[i].second][]);
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
