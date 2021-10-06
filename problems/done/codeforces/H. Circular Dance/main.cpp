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

    for(int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;

    for(int i = 1; i <= n; i++)
        if(arr[arr[i].second].first == arr[i].first || arr[arr[i].second].second == arr[i].first)
            swap(arr[i].first, arr[i].second);

    vi ans;
    ans.push_back(1);

    while(ans.size() < n){
        int cur = ans.back();
        ans.push_back(arr[cur].first);
        ans.push_back(arr[cur].second);
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
