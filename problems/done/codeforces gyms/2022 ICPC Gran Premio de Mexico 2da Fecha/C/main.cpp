#include<bits/stdc++.h>

#define int int64_t

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, vector<int>> mp;
    vector<pair<int, vector<int>>> ans;

    while(n--){

        int id;
        cin >> id;

        int sz;
        cin >> sz;

        vector<int> cur(sz);
        for(auto &i : cur) cin >> i;
        sort(cur.begin(), cur.end());

        mp[id] = cur;
    }

    while(m--){

        int id;
        cin >> id;

        int sz;
        cin >> sz;

        vector<int> cur(sz);
        for(auto &i : cur) cin >> i;
        sort(cur.begin(), cur.end());

        auto it = mp.find(id);

        if(it == mp.end()){
            for(auto &i : cur) i *= -1;
            ans.push_back({id, cur});
            continue;
        }

        vector<int> v0 = it->second;
        vector<int> v1 = cur;
        mp.erase(it);

        reverse(v0.begin(), v0.end());
        reverse(v1.begin(), v1.end());

        vector<int> cans;
        while(!v0.empty() && !v1.empty()){

            if(v0.back()==v1.back()){
                v0.pop_back();
                v1.pop_back();
            }
            else if(v0.back() < v1.back()){
                cans.push_back(v0.back());
                v0.pop_back();
            }
            else if(v1.back() < v0.back()){
                cans.push_back(-v1.back());
                v1.pop_back();
            }
        }

        while(!v0.empty()){
            cans.push_back(v0.back());
            v0.pop_back();
        }
        while(!v1.empty()){
            cans.push_back(-v1.back());
            v1.pop_back();
        }

        if(!cans.empty()){
            ans.push_back({id, cans});
        }
    }

    for(auto &[id, v] : mp){
        ans.push_back({id, v});
    }

    int missed = 0;
    int not_required = 0;
    for(auto &[id, v] : ans){
        for(auto e : v){
            if(e < 0){
                not_required++;
            }
            else{
                missed++;
            }
        }
    }

    sort(ans.begin(), ans.end());

    if(ans.empty()){
        cout << "GREAT WORK! NO MISTAKES FOUND!" << endl;
    }
    else{
        for(auto &[id, v] : ans){
            cout << id << ' ';
            for(auto e : v) cout << "+-"[e<0] << abs(e) << ' ';
            cout << endl;
        }
        cout << "MISTAKES IN " << ans.size() << " STUDENTS: " << not_required << " NOT REQUESTED, " << missed << " MISSED" << endl;
    }

}
