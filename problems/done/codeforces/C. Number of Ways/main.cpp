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

const int MAX = 5e5 + 10;

lli  sum[MAX];
bool cnt[2][MAX];
int  cntSm[MAX];

void solve(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    if(sum[n] % 3LL){
        cout << 0;
        return;
    }

    lli third = sum[n]/3;

    for(int i = 1; i <= n; i++){
        cnt[0][i] = sum[i] == third;
        cnt[1][i] = (sum[n] - sum[i-1]) == third;
    }


    lli ans = 0;

    for(int i = 1; i <= n; i++)
        cntSm[i] = cntSm[i-1] + cnt[0][i];

    for(int i = 3; i <= n; i++) if(cnt[1][i])
        ans += cntSm[i-2];

    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
