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
int arr[1010];
int ans[1010];
vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 1;

    for(int k : primes){
        bool b = false;
        for(int i = 0; i < n; i++)
            if(!ans[i] && arr[i]%k == 0)
                ans[i] = cnt, b = true;
        cnt += b;
    }

    cout << cnt-1 << endl;
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;

}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
        memset(ans, 0, sizeof ans);
		solve();
	}
}
