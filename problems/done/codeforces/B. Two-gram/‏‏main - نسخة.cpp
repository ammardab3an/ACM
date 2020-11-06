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

    map<string, int> mp;

    for(int i = 0; i < n-1; i++)
        mp[str.substr(i, 2)]++;

    string ansStr; int ansK = 0;
    for(auto p : mp)
        if(p.second > ansK)
            ansStr = p.first, ansK = p.second;

    cout << ansStr;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
