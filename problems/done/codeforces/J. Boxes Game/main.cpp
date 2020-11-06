// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, int>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<int>         vint;

// Global Variables

const int nMAX = 1e3 + 10;

int arr[nMAX];
int mem[nMAX][nMAX];

int dp(int l, int r){

    if(l > r) return 0;

    int & ret = mem[l][r];
    if(ret != -1) return ret;

    int stPath = arr[l] - dp(l+1, r);
    int ndPath = arr[r] - dp(l, r-1);

    return ret = max(stPath, ndPath);
}

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(mem, -1, sizeof mem);

    cout << dp(0, n-1) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
