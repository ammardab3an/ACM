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

const int MAX = 3e5 + 10;

int arr[MAX];
int cnt[2][1 << 20];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    lli ans = 0;
    int Xor = 0;

    cnt[1][0] = 1;

    for(int i = 0; i < n; i++){
        Xor ^= arr[i];
        ans += cnt[i%2][Xor]++;
    }

    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
