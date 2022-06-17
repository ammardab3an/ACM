#include<bits/stdc++.h>

#define int int64_t

using namespace std;

#define endl '\n'

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    #define pp pair<int, pair<int, int>>

    //.second.first = attack
    //.second.second = health

    vector<pp> vec(n);
    for(int i = 0; i < n; i++){
        vec[i].first = i;
        cin >> vec[i].second.first;
        cin >> vec[i].second.second;
    }

    sort(vec.begin(), vec.end(), [](pp &a, pp &b){
         return a.second.second < b.second.second;
    });

    int og_ans = 0;
    for(auto p : vec){
        og_ans += p.second.first;
    }

    set<pp> st, ts;

    // st.rbegin = max attack
    // ts.rbegin = max helth

    st.insert({vec[0].second.first, {vec[0].first, vec[0].second.second}});
    ts.insert({vec[0].second.second, {vec[0].first, vec[0].second.first}});

    int ans = og_ans;
    pair<int, int> ans_p = {0, 1};

    for(int i = 1; i < n; i++){

        auto &p = vec[i];
        int idx = p.first;
        int att = p.second.first;
        int hel = p.second.second;

        auto it = st.rbegin();
        int cans = og_ans - att;
        if(it->first >= hel) cans -= it->first;

        if(ans > cans){
            ans = cans;
            ans_p = {idx, it->second}
        }
    }
}

