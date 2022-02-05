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

int arr[MAX];
map<int, int> mp;

void solve(){

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        arr[i] = a;
        mp[b]++;
    }

    lli ans = 0;
    for(int i = 0; i < n; i++){
        if(mp.count(arr[i]))
            ans += mp[arr[i]];
    }

    printf("%I64d\n", ans);
}

int main(){

	int t = 1; if(true) scanf("%d", &t);

	while(t--){
        mp.clear();
		solve();
	}
}
