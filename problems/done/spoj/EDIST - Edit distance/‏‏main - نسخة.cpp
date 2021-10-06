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

char str_1[MAX];
char str_2[MAX];
int  len_1, len_2;

int mem[MAX][MAX];

int dp(int pos_1, int pos_2){

    if(pos_1 == len_1 || pos_2 == len_2)
        return max(len_1 - pos_1, len_2 - pos_2);

    int & ret = mem[pos_1][pos_2];
    if(ret != -1) return ret;

    int stPath = dp(pos_1+1, pos_2) + 1;

    int ndPath = dp(pos_1, pos_2+1) + 1;

    int rdPath = dp(pos_1+1, pos_2+1) + (str_1[pos_1] != str_2[pos_2]);

    return ret = min(stPath, min(ndPath, rdPath));
}

void solve(){

    cin >> str_1 >> str_2;
    len_1 = strlen(str_1);
    len_2 = strlen(str_2);

    memset(mem, -1, sizeof mem);

    cout << dp(0, 0) << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
