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

    int n, b;
    cin >> n >> b;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    int sz = -1;
    {
        auto tmp = vec;
        tmp.push_back(0);
        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
        for(auto &i : vec) i = lower_bound(tmp.begin(), tmp.end(), i)-tmp.begin();
        sz = tmp.size();
    }

    assert(sz != -1);

    vector<vector<int>> pos(sz);
    for(int i = 0; i < n; i++){
        pos[vec[i]].push_back(i);
    }

    vector<int> ans(n);

    for(int i = 0; i < sz; i++){

        for(auto p : pos[i]){

            if(i==0){
                ans[i] = 0;
                continue;
            }

            int lf = (p-1+n)%n;
            int ri = (p+1)%n;

            int mx = 0;
            if(vec[lf] < i) mx = max(mx, ans[lf]);
            if(vec[ri] < i) mx = max(mx, ans[ri]);
            ans[p] = mx + b;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << i << " \n"[i+1==ans.size()];
    }
}

