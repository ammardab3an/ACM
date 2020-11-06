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

int mem[4][MAX];

void add(int & x, int y){
    x = ((x % MOD) + (y % MOD)) % MOD;
}

int dp(int pos, int n){

    if(!n) return pos == 0 ? 1 : 0;

    int & ret = mem[pos][n];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 4; i++) if(i != pos)
        add(ret, dp(i, n-1));

    return ret;
}

void solve(){
    int n;
    cin >> n;
    memset(mem, -1, sizeof mem);
    cout << dp(0, n) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
