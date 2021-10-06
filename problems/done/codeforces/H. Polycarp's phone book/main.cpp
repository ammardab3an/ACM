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

    map< string, set<int> > mp;

    string str;
    string ans[n];

    for(int k = 0; k < n; k++){
        cin >> str;
        ans[k] = str;

        for(int i = 0; i < 9; i++)
        for(int j = i; j < 9; j++)
            mp[str.substr(i, j-i+1)].insert(k);

    }

    for(auto p : mp){
        if(p.second.size() == 1)
            if(ans[*p.second.begin()].size() > p.first.size())
                ans[*p.second.begin()] = p.first;
    }


    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
