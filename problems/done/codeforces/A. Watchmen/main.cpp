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

pii arr[MAX];

bool compFun(const pii & st, const pii & nd){

    if(st.first != nd.first)
        return st.first < nd.first;
    return st.second < nd.second;
}

void solve(){

    int n;
    cin >> n;

    map<int, int> xmp;
    map<int, int> ymp;
    map<pii, int> pmp;

    lli ans = 0;

    for(int i = 0; i < n; i++){
        int cx, cy;
        cin >> cx >> cy;
        ans += xmp[cx]++;
        ans += ymp[cy]++;
        ans -= pmp[{cx, cy}]++;
    }

    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
