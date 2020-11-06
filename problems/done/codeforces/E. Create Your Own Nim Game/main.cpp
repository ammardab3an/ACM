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
const int MOD = 1e9 + 7;

int n;
int mem[111][111];

int dp(int Xor, int k){

    if(!k) return Xor != 0;

    int & ret = mem[Xor][k];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 1; i <= k; i++){
        ret += dp(Xor ^ i, k-i);
        if(ret >= MOD) ret -= MOD;
    }

    return ret;
}

void solve(){

    cin >> n;
    cout << dp(0, n) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	memset(mem, -1, sizeof mem);

	while(t--){
		solve();
	}
}
