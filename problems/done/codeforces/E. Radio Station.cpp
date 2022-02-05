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

    int n, m;
    cin >> n >> m;

    map<string, string> mp;

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        mp[s2] = s1;
    }

    while(m--){
        string s1, s2;
        cin >> s1 >> s2;
        cout << s1 << ' ' << s2 << " #" << mp[s2.substr(0, s2.size()-1)] << endl;
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
