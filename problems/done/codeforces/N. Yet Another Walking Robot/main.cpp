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

    string str;
    cin >> str;

    int strSz = str.size();

    map<pii, int> visMp;
    pii ans = {-1, n}, curSm = {0, 0};
    visMp[curSm] = 0;

    for(int i = 0; i < strSz; i++){

        char c = str[i];

        if(c == 'R') curSm.first++;
        if(c == 'L') curSm.first--;
        if(c == 'U') curSm.second++;
        if(c == 'D') curSm.second--;

        if(visMp.count(curSm)){
            if(i - visMp[curSm] + 1 < ans.second - ans.first + 1){
                ans.first  = visMp[curSm];
                ans.second = i;
            }
        }

        visMp[curSm] = i + 1;
    }

    if(ans.first == -1)
        cout << -1 << endl;
    else
        cout << ans.first +1 << ' ' << ans.second +1 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
