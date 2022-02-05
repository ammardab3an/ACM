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

void solve(){

    string num;
    cin >> num;

    int n = num.size();

    for(int i = 0; i < n; i++){

        if(num[i] % 8 == 0){
            cout << "YES" << endl << num[i];
            return;
        }

        for(int j = i+1; j < n; j++){

            if((10 * num[i] + num[j]) % 8 == 0){
                cout << "YES" << endl << num[i] << num[j];
                return;
            }

            for(int k = j+1; k < n; k++){

                if((100 * num[i] + 10 * num[j] + num[k]) % 8 == 0){
                    cout << "YES" << endl << num[i] << num[j] << num[k];
                    return;
                }
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
