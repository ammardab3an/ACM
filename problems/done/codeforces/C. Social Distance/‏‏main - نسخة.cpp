
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e5 + 10;

void solve(){

	int n, k;
	cin >> n >> k;

	int lstOne = 0;
	int cnt = 0;

    int i;
	for(i = 1; i <= n; i++){
        char c; cin >> c;
        if(c == '1'){
            if(!lstOne)
                cnt += (i - lstOne -1)/(k+1);
            else
                cnt += (i - lstOne -1)/(k*2+1);
            lstOne = i;
        }
	}

    cnt += (i - lstOne -1)/(k+1);

	cout << cnt << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
