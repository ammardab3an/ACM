
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e5 + 10;

char arr[MAX];

void solve(){

    int n, k;
	cin >> n >> k >> arr;

    int cnt = 0;

    for(int i = 0; i < n; i++){


        if(arr[i] == '0'){

            bool b = true;

            for(int j = i - k; j <= (i + k); j++) if(j >= 0 && j < n) if(arr[j] == '1'){
                b = false;
                break;
            }

            if(b) {
                arr[i] = '1';
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
