#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

signed main(){

    int n, p;
    cin >> n >> p;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    int mx = 0;
    int len = -1;
    int sm = accumulate(vec.begin(), vec.end(), 0ll);

    {
        auto tmp = vec;
        sort(tmp.begin(), tmp.end());

        int cur = 0;
        while(!tmp.empty() && cur*100 < p*sm){
            cur += tmp.back();
            tmp.pop_back();
        }

        if(cur*100 >= p*sm){
            len = vec.size()-tmp.size();
        }
    }

    assert(len != -1);

    vector<int> ans_sm;
    vector<vector<int>> ans;

    for(int i = 0; i < (1<<n); i++) if(__builtin_popcount(i)==len){

        int cur = 0;
        vector<int> cur_v;
        for(int j = 0; j < n; j++) if((i>>j)&1){
            cur += vec[j];
            cur_v.push_back(j);
        }

        if(cur*100 >= p*sm){
            ans_sm.push_back((cur*100)/sm);
            ans.push_back(cur_v);
        }
    }

    cout << len << ' ' << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans_sm[i] << ' ';
        for(int j = 0; j < ans[i].size(); j++){
            if(j) cout << ' ';
            cout << ans[i][j]+1;
        }
        cout << endl;
    }
}
