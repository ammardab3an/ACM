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

    string str;
    cin >> str;

    int strSz(str.size());

    lli ans = 0;

    for(int i = 0; i < strSz; i++)
        if((str[i] - '0') % 4 == 0)
            ans++;

    for(int i = 0; i+1 < strSz; i++)
        if(((str[i] - '0') * 10 + (str[i+1] - '0')) % 4 == 0)
            ans += i+1;

    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
