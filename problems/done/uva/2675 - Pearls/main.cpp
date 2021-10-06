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

const int oo  = 1e9;
const int MAX = 1e3 + 10;

int n;
int cost[MAX];
int wnt[MAX];
int mem[MAX];

int dp(int pos){

    if(pos == n)
        return 0;

    int & ret = mem[pos];
    if(ret != -1) return ret;

    ret = oo;

    int sum = 0;
    for(int i = pos; i < n; i++){
        sum += wnt[i];
        ret = min(ret, (sum + 10) * cost[i] + dp(i+1));
    }

    return ret;
}

void solve(){

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> wnt[i] >> cost[i];

    cout << dp(0) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
        memset(mem, -1, sizeof mem);
		solve();
	}
}
