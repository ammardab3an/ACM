#include<bits/stdc++.h>

#define int int64_t

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> vec;

    for(int i = 1; i < (1<<16); i++){

        {
            int x = i;
            int cur = x;
            while(x){
                cur <<= 1;
                cur |= x&1;
                x /= 2;
            }
            vec.push_back(cur);
        }
        {
            int x = i;
            int cur = x;
            x /= 2;
            while(x){
                cur <<= 1;
                cur |= x&1;
                x /= 2;
            }
            vec.push_back(cur);
        }
    }

    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end())-vec.begin());

    int t; cin >> t; while(t--){

        int l, r;
        cin >> l >> r;

        int ans = upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
        cout << ans << endl;
    }
}
