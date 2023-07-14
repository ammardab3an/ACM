#include<bits/stdc++.h>


#define int long long

using namespace std;

 main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    multiset<pair<int, int>> mst;
    int water_level = 0;

    for(int i = 0; i < n; i++){
        mst.insert({vec[i], i});
    }

    int mx = 5*n;
    bool good = false;

    while(mx-- && !good){

        auto tmp = *mst.rbegin();
        mst.erase(mst.find(tmp));
        tmp.first += water_level;

        if(tmp.first < n-1){
            tmp.first -= water_level;
            mst.insert(tmp);
            good = true;
            break;
        }

        int cnt = tmp.first/(n-1);
        tmp.first -= cnt * (n-1);
        water_level += cnt;

        tmp.first -= water_level;
        mst.insert(tmp);
    }

    if(!good){
        cout << "Recurrent";
    }
    else{
        vector<int> ans(n);
        for(auto [v, i] : mst){
            ans[i] = v+water_level;
        }
        for(int i = 0; i < n; i++){
            if(i) cout << " ";
            cout << ans[i];
        }
    }
}
