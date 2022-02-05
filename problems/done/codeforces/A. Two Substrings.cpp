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

    int strSz = str.size();

    vpii AB, BA;
    for(int i = 1; i < strSz; i++){
        if(str[i-1] == 'A' && str[i] == 'B')
            AB.push_back({i-1, i});
        if(str[i-1] == 'B' && str[i] == 'A')
            BA.push_back({i-1, i});
    }

    for(pii st : AB)
    for(pii nd : BA){
        if(set<int>({st.first, st.second, nd.first, nd.second}).size() == 4){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
