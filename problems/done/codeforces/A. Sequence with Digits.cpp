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

    lli a1, k;
    cin >> a1 >> k;

    k--;
    while(k--){

        int mn = 9;
        int mx = 0;
        lli tmp = a1;

        while(tmp > 0){
            int dig = tmp%10;
            mn = min(mn, dig);
            mx = max(mx, dig);
            tmp /= 10;
            if(mn == 0) goto WTF;
        }

        a1 += mn * mx;
    }

    WTF:
    cout << a1 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
