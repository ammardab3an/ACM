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

int arr[26][26];

void solve(){

    int n;
    cin >> n;

    string str;
    cin >> str;


    for(int i = 0; i < n-1; i++)
        arr[str[i] - 'A'][str[i+1] - 'A']++;

    int ansK = 0;
    string ansStr = "00";

    for(int i = 0; i < 26; i++)
    for(int j = 0; j < 26; j++)
        if(arr[i][j] > ansK)
            ansStr[0] = 'A' + i,
            ansStr[1] = 'A' + j,
            ansK = arr[i][j];

    cout << ansStr;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
