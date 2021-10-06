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

    int cnt[2]({});

    for(char c : str)
        cnt[c - '0']++;

    string ans = "";

    if(!cnt[0] || !cnt[1]){
        ans = str;
    }
    else{
        for(int i = 0; i < str.size(); i++)
            ans += "01";
    }

    cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
