
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

const int MAX = 1e5 + 10;

int n, c, dis;
int arr[MAX];
int mem[MAX];

int _dp(int idx){

    int & ret = mem[idx];
    if(ret != -1) return ret;

    ret = 0;

    for(int nxt = idx+1; nxt <= n; nxt++){
        if(arr[nxt] - arr[idx] >= dis)
            ret = max(ret, dp(nxt) + 1);
        else
            break;
    }

    return ret;
}

int dp(){

    for(int i = 0; i <= n; i++){

        mem[i] = 0;

        for(int j = 0; j < i; j++){
            if(arr[i] - arr[j] >= dis)
                mem[i] = max(mem[i], mem[j] + 1);
            else
                break;
        }
    }

    return mem[n];
}

void solve(){

	cin >> n >> c;

	arr[n] = INT_MAX;
	for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int ans;
    int l = 0;
    int r = arr[n-1];

    while(l <= r){

        dis = (l + r)/2;

        if(c <= dp())
            ans = dis,
            l = dis+1;
        else
            r = dis-1;
    }

    cout << ans << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
