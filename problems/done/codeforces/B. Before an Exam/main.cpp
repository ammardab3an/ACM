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

    int d, sumTime;
    cin >> d >> sumTime;

    int mn[d], mx[d];

    int mnSm = 0;
    for(int i = 0; i < d; i++){
        cin >> mn[i] >> mx[i];
        mnSm += mn[i];
    }

    if(mnSm > sumTime){
        cout << "NO";
        return;
    }

    int ans[d];
    memcpy(ans, mn, sizeof mn);

    int dif = sumTime - mnSm;
    for(int i = 0; i < d && dif; i++){
        ans[i] += min(mx[i] - mn[i], dif);
        dif    -= min(mx[i] - mn[i], dif);
    }

    if(!dif){
        cout << "YES" << endl;
        for(int i = 0; i < d; i++)
            cout << ans[i] << ' ';
    }
    else
        cout << "NO";
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
