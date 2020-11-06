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

    stack<char> st;

    for(char c : str){
        if(st.empty() || st.top() != c) st.push(c);
        else st.pop();
    }

    cout << (st.empty() ? "Yes" : "No");
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
