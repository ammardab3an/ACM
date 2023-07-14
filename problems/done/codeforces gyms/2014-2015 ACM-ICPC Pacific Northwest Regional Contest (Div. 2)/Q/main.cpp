#include <bits/stdc++.h>

using namespace std;

int n;
int a[110];
int dp[110][110];

int mex(int x){
    if(x == 0) return 1;
    return 0;
}

int get_max(int l, int r){
    int idx = l;
    for(int i = l; i <= r; i++){
        if(a[i] > a[idx]) idx = i;
    }
    return idx;
}

int solve(int l, int r){

    if(l > r) return 0;
    if(l == r) return 1;

    if(dp[l][r] != -1) return dp[l][r];

    int mx_idx = get_max(l, r);

    if(mx_idx == l) return dp[l][r] = mex(solve(l+1, r));
    if(mx_idx == r) return dp[l][r] = mex(solve(l, r-1));

    dp[l][r] = mex(solve(l, mx_idx-1)) ^ mex(solve(mx_idx+1, r));
    cout << "l " << l << " and " << r << " " << dp[l][r] << endl;
    return dp[l][r];

}

int main()
{

    int t;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i <= n+3; i++){
            for(int j = 0; j <= n+3; j++) dp[i][j] = -1;
        }

        int ans = solve(0, n-1);

        if(ans) cout << "Alice\n";
        else cout << "Bob\n";

    }

    return 0;
}
