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

pii arr[MAX];

bool compFun(const pii & st, const pii & nd){

    if(st.first != nd.first)
        return st.first < nd.first;
    return st.second < nd.second;
}

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr+n, compFun);

    lli ans = 0;

    map<int, int> xmp, ymp;

    int xlst(INT_MAX), ylst(INT_MAX), cnt(1);

    for(int i = 0; i < n; i++){

        int cx = arr[i].first;
        int cy = arr[i].second;

        ans += xmp[cx]++;
        ans += ymp[cy]++;

        if(cx == xlst && cy == ylst)
            ans -= cnt++;

        else{
            xlst = cx;
            ylst = cy;
            cnt  = 1;
        }
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
