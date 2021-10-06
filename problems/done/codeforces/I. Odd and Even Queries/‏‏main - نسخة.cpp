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

int arr[MAX];

lli choose(int n, int k){

    lli ret = 1;
    for(int i = 1; i <= k; i++){
        ret *= n--;
        ret /= i;
        if(ret >= MOD) ret -= MOD;
    }
    return ret;
}

void solve(){

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x % 2 == 0;
    }

    for(int i = 1; i < n; i++)
        arr[i] += arr[i-1];

    while(k--){

        int l, r, fn;
        cin >> l >> r >> fn;

        int ans = 0;

        int evenCnt = arr[r-1];
        if(l-1) evenCnt -= arr[l-2];

        int oddCnt = r-l+1 - evenCnt;

        if(!fn){
            if(evenCnt){
                for(int i = 1; i <= evenCnt; i++)
                for(int j = 1; j <= oddCnt ; j++){
                    ans += choose(evenCnt, i) * choose(oddCnt, j);
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }

        else{
            if(oddCnt){
                for(int i = 1; i <= oddCnt; i++){
                    ans += choose(oddCnt, i);
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }

        cout << ans << endl;
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
