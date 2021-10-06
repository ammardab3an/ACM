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

const int MAX = 1e7 + 10;
const int MOD = 1e9 + 7;

void solve(){

    int n;
    cin >> n;

    int Di   = 1;
    int ABCi = 0;

    for(int i = 1; i <= n; i++){

        // j = i+1
        // i = j-1

        int Dj   = (ABCi * 3LL)      % MOD;
        int ABCj = (ABCi * 2LL + Di) % MOD;

        Di   = Dj;
        ABCi = ABCj;
    }

    cout << Di;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
