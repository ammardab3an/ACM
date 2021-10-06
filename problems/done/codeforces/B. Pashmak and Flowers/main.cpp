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

    int mx = INT_MIN;
    int mn = INT_MAX;
    int mxCnt, mnCnt;

    while(n--){

        int x;
        cin >> x;

        if(x > mx){
            mx = x;
            mxCnt = 0;
        }
        if(x < mn){
            mn = x;
            mnCnt = 0;
        }

        if(x == mx) mxCnt++;
        if(x == mn) mnCnt++;

    }


    if(mx != mn)
        cout << mx - mn << ' ' << 1LL * mxCnt * mnCnt << endl;
    else
        cout << mx - mn << ' ' << 1LL * mxCnt * (mxCnt -1) / 2 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
