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

    int kit = 0, bed = 0, liv = 0;
    while(n--){
        string str;
        cin >> str;

        if(str[0] == 'k') kit++;
        if(str[0] == 'b') bed++;
        if(str[0] == 'l') liv++;
    }
    bed /= 2;
    cout << min(kit, min(bed, liv)) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
