#include <bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

string str;
int mod;

int add(int a, int b){
    int ret = (1ll*a + b) % mod;
    if(ret < 0) ret += mod;
    return ret;
}
int mul(int a, int b){
    int ret = (a *1ll* b) % mod;
    if(ret < 0) ret += mod;
    return ret;
}

int cnt[2][127];
int frq[2][127][127];
int sm;

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> str;
    cin >> mod;

    if(mod==0){
        str = string(1000000, 'a');
        mod = 1e9 + 7;
    }

    int n = str.size();
    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        int c = str[i];
        for(int j = 33; j < 127; j++){
            frq[1][c][j] += cnt[1][j];
        }
        cnt[1][c]++;
    }

    for(int i = 0; i < n; i++){

        {
            int c = str[i];
            cnt[1][c]--;
            for(int j = 33; j < 127; j++){
                sm = add(sm, mul(-cnt[1][j], frq[0][j][c]));
                frq[1][c][j] = add(frq[1][c][j], -cnt[1][j]);
            }
        }

        if(i){
            int c = str[i-1];
            for(int j = 33; j < 127; j++){
                sm = add(sm, mul(cnt[0][j], frq[1][c][j]));
                frq[0][j][c] = add(frq[0][j][c], cnt[0][j]);
            }
            cnt[0][c]++;
        }

        ans = add(ans, sm);
    }

    cout << ans << endl;
}
