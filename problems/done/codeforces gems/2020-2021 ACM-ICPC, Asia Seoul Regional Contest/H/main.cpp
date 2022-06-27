#include<bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

const int AMAX = 60000+10;

int32_t main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> n(3);
    vector<vector<int>> vec(3);

    for(int i = 0; i < 3; i++){
        cin >> n[i];
        vec[i].resize(n[i]);
        for(auto &e : vec[i]) cin >> e;
        sort(vec[i].begin(), vec[i].end());
    }

    auto calc = [&](int foo){

        if(foo==1){
            swap(n[0], n[2]);
            swap(vec[0], vec[2]);
        }
        if(foo==2){
            map<int, int> mp;
            for(auto v : vec)
            for(auto i : v) mp[i]++;
            int ans = 0;
            for(auto p : mp) ans += p.second==3;
            return ans;
        }

        bitset<AMAX> pre, suf;

        int i = -1;
        int j = 0;
        int k = n[2];

        while(i+1 < n[0] && vec[0][i+1] <= vec[1][j]){
            pre[vec[1][j] - vec[0][i+1]] = true;
            i++;
        }

        while(k-1 >= 0 && vec[1][j] <= vec[2][k-1]){
            suf[vec[2][k-1]-vec[1][j]] = true;
            k--;
        }

        int ans = 0;

        ans += (pre&suf).count();

        for(j = 1; j < n[1]; j++){

            int dif = vec[1][j] - vec[1][j-1];

            pre <<= dif;
            suf >>= dif;

            while(i+1 < n[0] && vec[0][i+1] <= vec[1][j]){
                pre[vec[1][j] - vec[0][i+1]] = true;
                i++;
            }

            while(k-1 >= 0 && vec[1][j] <= vec[2][k-1]){
                suf[vec[2][k-1] - vec[1][j]] = true;
                k--;
            }

            ans += (pre&suf).count();
        }

        return ans;
    };

    int ans = calc(0) + calc(1) - calc(2);

    cout << ans << endl;
}
