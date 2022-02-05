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

    lli u, v;
    cin >> u >> v;

    if(!u && !v){
        cout << 0;
        return;
    }
    if(u == v){
        cout << "1\n" << u;
        return;
    }
    if((u&1 ^ v&1) || u > v){
        cout << -1;
        return;
    }

    lli d = (v-u)/2;

    if((u | d) == (u + d))
        cout << "2\n" << u + d << ' ' << d;
    else
        cout << "3\n" << u << ' ' << d << ' ' << d;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
