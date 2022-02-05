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

int n, m;

string minNum(int pos, int sm){

    if(pos == 1) return string(1, sm + '0');

    for(int i = pos == n ? 1 : 0; i <= min(9, sm); i++)
        if(sm - i <= (pos -1) * 9)
            return string(1, i + '0') + minNum(pos - 1, sm - i);

    return "";
}
string maxNum(int pos, int sm){

    if(pos == 1) return string(1, sm + '0');

    for(int i = min(9, sm); i >= (pos == n ? 1 : 0); i--)
        if(sm - i <= (pos -1) * 9)
            return string(1, i + '0') + maxNum(pos - 1, sm - i);

    return "";
}

void solve(){
    cin >> n >> m;

    if(!m){
        cout << (n == 1 ? "0 0" : "-1 -1");
        return;
    }

    if(9 * n < m){
        cout << "-1 -1";
        return;
    }

    cout << minNum(n, m) << ' ' << maxNum(n, m);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
