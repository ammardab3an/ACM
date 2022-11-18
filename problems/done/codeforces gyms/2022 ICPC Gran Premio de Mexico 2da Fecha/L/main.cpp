#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int NMAX = 1e5 + 10;
const int MOD = 1e9+7;

int add(int x, int y){
    int ret = (1ll*x+y)%MOD;
    return (ret+MOD)%MOD;
}

int mul(int x, int y){
    int ret = (x*1ll*y)%MOD;
    return (ret+MOD)%MOD;
}

signed main(){

    int n;
    cin >> n;

    vector<int> dp(n+1);
    vector<int> pre(n+1);

    dp[0] = dp[1] = 1;
    pre[0] = 1;
    pre[1] = 2;

    for(int i = 2; i <= n; i++){
        dp[i] = add(pre[i-1], mul(-1, pre[i-i/2-1]));
        pre[i] = add(pre[i-1], dp[i]);
    }

//    for(int i = 0; i <= n; i++) cout << dp[i] << ' '; cout << endl;
//    for(int i = 0; i <= n; i++) cout << pre[i] << ' '; cout << endl;

    cout << dp[n] << endl;
}
