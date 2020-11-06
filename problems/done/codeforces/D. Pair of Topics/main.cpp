// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

// Global Variables
const int MAX = 2e5 + 10;
int arr[MAX];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++){
        int b; cin >> b; arr[i] -= b;
    }

    sort(arr, arr+n);

    lli ans = 0, cnt = 0;

    for(int i = 0; i < n; i++) if(arr[i] > 0){

        lli tmp = n - int(upper_bound(arr, arr+n, -arr[i]) - arr);

        if(tmp){
            cnt++;
            ans += tmp - cnt;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
