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
int arr[MAX];
int sor[MAX];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int mx = *max_element(arr, arr+n);

    if(2*mx < n){
        cout << 0 << endl; return;
    }

    bool b1(1), b2(1);
    int l1(mx), l2(n-mx);

    memcpy(sor, arr, sizeof arr);
    sort(sor, sor+l1);
    sort(sor+l1, sor+n);

    for(int i = 0; i < n; i++) if(sor[i] != (i % l1 +1)){
        b1 = false;
        break;
    }

    memcpy(sor, arr, sizeof arr);
    sort(sor, sor+l2);
    sort(sor+l2, sor+n);

    for(int i = 0; i < n; i++) if(sor[i] != (i - l2 >= 0 ? i-l2+1 : i+1)){
        b2 = false;
        break;
    }

    set<pii> ans;

    if(b1) ans.insert({mx, n-mx});
    if(b2) ans.insert({n-mx, mx});

    cout << ans.size() << endl;
    for(pii p : ans)
        cout << p.first << ' ' << p.second << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
