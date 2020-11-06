// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long           lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables
const int MAX = 1e5;

void solve(){

    int n;
    cin >> n;

    int last; cin >> last; last %= 2;

    bool b = true;
    for(int i = 1; i < n; i++){

        int num; cin >> num; num %= 2;

        if(num != last)
            b = false;

        last = num;
    }
    cout << (b ? "YES" : "NO") << endl;
}

int main(){

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
