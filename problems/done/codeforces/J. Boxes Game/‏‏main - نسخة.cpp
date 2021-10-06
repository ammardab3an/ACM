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
const int aMAX = 1e6 + 10;

int arr[nMAX];
int mem[nMAX][nMAX][2];

int dp(int l, int r, bool b){

    if(l > r) return 0;

    int & ret = mem[l][r][b];
    if(ret != -123456) return ret;

    int stPath, ndPath;

    if(b){
        stPath = dp(l+1, r, !b) + arr[l];
        ndPath = dp(l, r-1, !b) + arr[r];
        return ret = max(stPath, ndPath);
    }
    else{
        stPath = dp(l+1, r, !b) - arr[l];
        ndPath = dp(l, r-1, !b) - arr[r];
        return ret = min(stPath, ndPath);
    }
}

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        mem[i][j][0] = mem[i][j][1] = -123456;

    cout << '\t' << dp(0, n-1, 1) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
