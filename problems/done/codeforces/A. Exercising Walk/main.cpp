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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    bool can = true;

    if(a > b){
        if(x - (a - b) < x1)
            can = false;
    }
    else if(x + b - a > x2)
        can = false;

    if(c > d){
        if(y - (c - d) < y1)
            can = false;
    }
    else if(y + d - c > y2)
        can = false;

    if(a || b) if(x2 - x1 < 1) can = false;
    if(c || d) if(y2 - y1 < 1) can = false;

    if(can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
