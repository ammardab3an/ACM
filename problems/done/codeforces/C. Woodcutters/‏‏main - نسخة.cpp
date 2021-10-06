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

const int MAX = 1e5 + 10;

int n;
pii arr[MAX];
map<int, int> mem[MAX];

int dp(int nd, int lastPos){

    if(nd == n-1)
        return 1;

    if(mem[nd].count(lastPos))
        return mem[nd][lastPos];

    int ret = 0;

    ret = dp(nd+1, arr[nd].first);

    if(arr[nd].first - arr[nd].second > lastPos)
        ret = max(ret, 1 + dp(nd+1, arr[nd].first));

    if(arr[nd].first + arr[nd].second < arr[nd+1].first )
        ret = max(ret, 1 + dp(nd+1, arr[nd].first + arr[nd].second));

    return mem[nd][lastPos] = ret;
}

void solve(){

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    cout << dp(0, INT_MIN);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
