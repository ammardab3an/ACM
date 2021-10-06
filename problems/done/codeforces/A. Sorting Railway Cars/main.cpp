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

int pos[MAX];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x; pos[x-1] = i;
    }

    int cnt(1), mxCnt(1);

    for(int i = 1; i < n; i++){

        if(pos[i-1] < pos[i])
            cnt++;
        else
            cnt = 1;

        mxCnt = max(mxCnt, cnt);
    }

    cout << n - mxCnt << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
