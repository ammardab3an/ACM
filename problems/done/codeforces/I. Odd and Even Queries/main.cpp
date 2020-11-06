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

const int MAX = 1e5 + 10;
const lli MOD = 1e9 + 7;

int arr[MAX];

lli fastPow(lli a, lli p){

    if(p == 0)
        return 1;

    lli aa = ((a%MOD)*(a%MOD))%MOD;

    if(p % 2 == 0)
        return fastPow(aa, p/2LL) % MOD;

    else
        return ((a % MOD) * (fastPow(aa, p/2LL) % MOD)) % MOD;
}

void solve(){

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] %= 2;
        if(i) arr[i] += arr[i-1];
    }

    while(k--){

        int l, r, fn;
        cin >> l >> r >> fn;

        int oddCnt = arr[r-1];
        if(l-1) oddCnt -= arr[l-2];

        int evenCnt = r-l+1 - oddCnt;

        if(fn)
            cout << (fastPow(2, oddCnt) -1LL) % MOD << endl;
        else
            cout << (fastPow(2, oddCnt) * (fastPow(2, evenCnt) -1LL)) % MOD << endl;

    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
