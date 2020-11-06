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

const int MAX = 2e3 + 10;
const int MOD = 1e9 + 7;

int n, k;
int mem[MAX][MAX];

int dp(int pos, int lst){

    if(pos == k) return 1;

    int & ret = mem[pos][lst];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 1; lst * i <= n; i++)
        ret = ((ret % MOD) + (dp(pos+1, lst * i) % MOD)) % MOD;

    return ret;
}


void solve(){

    cin >> n >> k;
    memset(mem, -1, sizeof mem);
    cout << dp(0, 1);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
