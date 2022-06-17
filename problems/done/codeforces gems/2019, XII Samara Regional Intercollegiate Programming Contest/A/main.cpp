#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main()
{

    int n;
    cin >> n;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    map<int, int> mp;
    vector<int> ans(n);

    deque<pair<int, int> > tmp;

    for(int i = n-1; i >= 0; i--){

        if(vec[i] > 0){
            mp[vec[i]] = i;
            tmp.push_back({vec[i], i});
        }
        else{
            auto it = mp.find(-vec[i]);
            if(it != mp.end()){
                int idx = it->second;
                while(tmp.size() && tmp.front().second >= idx){
                    tmp.pop_front();
                }
            }
            tmp.push_back({vec[i], i});
        }

        ans[i] = tmp.size();
    }

    for(int i : ans) cout << i << ' '; cout << endl;
}
