
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int nMax  = 1e3 + 10;
const int oxMax = 21 + 10;
const int niMax = 79 + 10;
const int weMax = 800 + 10;

int n;
int arr[nMax][3];
int mem[nMax][oxMax][niMax];

// the difference between starting from zero and starting from the required value is that if you start from zero and you
// have two parameters to be considered, the recursive function may exceed one of the parameters limit, for example: dp(0, 0, 100).

int dp(int pos, int ox, int ni){

    if(!ox && !ni)
        return 0;

    if(pos == n)
        return weMax * nMax;

    int & ret = mem[pos][ox][ni];
    if(ret != -1) return ret;

    int stPath = dp(pos+1, ox, ni);
    int ndPath = dp(pos+1, max(0, ox - arr[pos][0]), max(0, ni - arr[pos][1])) + arr[pos][2];

    return ret = min(stPath, ndPath);
}

void solve(){

    int ox, ni;
	cin >> ox >> ni >> n;

	for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    memset(mem, -1, sizeof mem);

    cout << dp(0, ox, ni) << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
