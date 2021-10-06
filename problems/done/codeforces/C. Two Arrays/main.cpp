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

const int MAX = 1e3 + 10;
const lli MOD = 1e9 + 7;

int n, m;
lli mem[MAX][22];

lli dp(int lst, int pos){

    if(pos == m)
        return 1;

    lli & ret = mem[lst][pos];
    if(ret != -1) return ret;

    ret = 0;
    for(int nxt = lst; nxt <= n; nxt++)
        ret = ((ret % MOD) + (dp(nxt, pos+1) % MOD)) % MOD;

    return ret;
}

void solve(){

    cin >> n >> m;

    m *= 2;

    memset(mem, -1, sizeof mem);

    cout << dp(1, 0);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
