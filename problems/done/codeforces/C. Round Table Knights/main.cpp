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

bool arr[MAX];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 3; i <= n; i++) if(n % i == 0){
        for(int j = 0; j < n/i; j++){
            int sm = 0;
            for(int k = 0 + j; k < n; k += n/i)
                sm += arr[k];
            if(sm == i){
                cout << "YES";
                return;
            }
        }
    }

    cout << "NO";
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
