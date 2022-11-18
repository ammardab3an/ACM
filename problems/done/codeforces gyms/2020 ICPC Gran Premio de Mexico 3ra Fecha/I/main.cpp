#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int MOD = 1e9+7;

int mul(int x, int y){
    return (x*1ll*y)%MOD;
}

int pow_exp(int n, int p){
    if(!p) return 1;
    if(p&1) return mul(n, pow_exp(n, p-1));
    int ret = pow_exp(n, p/2);
    return mul(ret, ret);
}

signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> vec(3);
    for(auto &i : vec) cin >> i;

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int ans = 0;

    while(vec.size() > 1){

        if(vec.back() >= 500){
            ans += vec.back()-100;
            vec.pop_back();
        }
        else{
            int x = vec.back();
            vec.pop_back();
            vec.back() += x;
        }
    }

    for(auto i : vec){
        if(i >= 500){
            ans += i-100;
        }
        else{
            ans += i;
        }
    }

    cout << ans << endl;
}

