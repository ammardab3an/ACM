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

const int MAX = 1e4 + 10;

int n;
int mem[7][MAX];

int dp(int pos, int sum){

    int & ret = mem[pos][sum];
    if(ret != -1) return ret;

    ret = 1e9;

    for(int to = 1; to <= 6; to++) if(to != pos && to != 7 - pos){

        if(to + sum == n) return ret = 1;
        if(to + sum >  n) continue;

        ret = min(ret, 1 + dp(to, to + sum));
    }

    return ret;
}

void solve(){

    cin >> n;
    memset(mem, -1, sizeof mem);
    int ans = dp(1, 0);
    cout << (ans >= 1e9 ? -1 : ans) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while(t--){
		solve();
	}
}
