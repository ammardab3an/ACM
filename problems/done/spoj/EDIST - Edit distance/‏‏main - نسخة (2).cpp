// In the name of God, the Most Gracious, the Most Merciful.

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

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e3 + 10;

int dp(char * str_1, char * str_2){

    int len_1 = strlen(str_1);
    int len_2 = strlen(str_2);

    int arr[len_1][len_2];

    for(int i = 0; i < len_1; i++)
    for(int j = 0; j < len_2; j++){

        arr[i][j] = max(i+1, j+1) - (str_1[i] == str_2[j]);

        if(i) arr[i][j] = min(arr[i][j], arr[i-1][j] + 1);
        if(j) arr[i][j] = min(arr[i][j], arr[i][j-1] + 1);

        if(i && j) arr[i][j] = min(arr[i][j], arr[i-1][j-1] + (str_1[i] != str_2[j]));

    }

    return arr[len_1-1][len_2-1];
}

void solve(){

    char str_1[MAX];
    char str_2[MAX];

    cin >> str_1 >> str_2;

    cout << dp(str_1, str_2) << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
