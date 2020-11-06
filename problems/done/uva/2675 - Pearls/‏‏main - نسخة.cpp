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

const int MAX = 100 + 10;

int n;
int cls[MAX];
int wnt[MAX];
int mem[MAX][MAX];

int dp(int pos, int car){

    if(pos == n)
		return car ? 1e9 : 0;

    int & ret = mem[pos][car];
    if(ret != -1) return ret;

    int stPath = dp(pos+1, car+wnt[pos]);
    int ndPath = (wnt[pos] + car + 10) * cls[pos] + dp(pos+1, 0);

    return ret = min(stPath, ndPath);
}

void solve(){

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> wnt[i] >> cls[i];

    cout << dp(0, 0) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
        memset(mem, -1, sizeof mem);
		solve();
	}
}
