#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main()
{


    int n, m;
    cin >> n >> m;

    #define pp pair<int, pair<int, int>>

    vector<pp> vec(n);
    for(int i = 0; i < n; i++){
        vec[i].first = i;
        cin >> vec[i].second.first;
        cin >> vec[i].second.second;
    }

    sort(vec.begin(), vec.end(), [](pp &a, pp &b)
    {
        if(a.second.first != b.second.first){
                return a.second.first < b.second.first;
         }

         return a.second.second > b.second.second;
    });

    reverse(vec.begin(), vec.end());

    bool bad = false;
    vector<int> ans_pos;

    if(vec.back().second.first > 1){
        cout << "NO" << endl;
        return 0;
    }

    int cur = vec.back().second.second;
    ans_pos.push_back(vec.back().first);
    vec.pop_back();

    while(vec.size() && cur < m){

        vector<pp> tmp;

//        cout << vec.back().second.first << ' ' << vec.back().second.second << endl;

        while(vec.size() && vec.back().second.first <= cur+1){
            tmp.push_back(vec.back());
            vec.pop_back();
        }

        int mx_r = cur;
        int mx_pos = -1;

        for(auto p : tmp){

            int pos = p.first;
            int r = p.second.second;

            if(r > mx_r){
                mx_r = r;
                mx_pos = pos;
            }
        }

        if(mx_pos == -1){
            bad = true;
            break;
        }

        cur = mx_r;
        ans_pos.push_back(mx_pos);
    }

    if(cur != m){
        bad = true;
    }

    if(!bad){
        cout << "YES" << endl;
        sort(ans_pos.begin(), ans_pos.end());
        cout << ans_pos.size() << endl;
        for(auto i : ans_pos) cout << i+1 << ' '; cout << endl;
    }
    else{
        cout << "NO" << endl;
    }

}
