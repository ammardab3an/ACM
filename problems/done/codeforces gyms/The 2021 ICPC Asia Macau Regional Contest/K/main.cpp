#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v[100010];
int clr[100010];

int dfs(int cur, int pre, int mid, vector<int> &cur_ans, vector<int> &cur_e, int edge){

    if(clr[cur] == 2) return 0;
    cur_ans.push_back(cur);
    cur_e.push_back(edge);
    if(clr[cur] == 1){
        vector<int> temp, temp1;
        temp.push_back(cur);
        temp1.push_back(edge);
        cur_ans.pop_back();
        cur_e.pop_back();
        while(cur_ans.back() != cur){
            temp.push_back(cur_ans.back());
            cur_ans.pop_back();
            temp1.push_back(cur_e.back());
            cur_e.pop_back();
        }
        temp.push_back(cur_ans.back());
        cur_ans.pop_back();
        cur_e = temp1;
        cur_ans = temp;
        return 1;
    }
    clr[cur] = 1;
    for(auto [x, i] : v[cur]){
        if(i > mid) continue;
        if(x == pre) continue;
        int can1 = dfs(x, cur, mid, cur_ans, cur_e, i);
        if(can1) return 1;
    }

    cur_ans.pop_back();
    cur_e.pop_back();
    clr[cur] = 2;
    return 0;

}

bool can(int mid, int n, vector<int> &cur_ans, vector<int> &cur_e){

    for(int i = 0; i <= n+3; i++){
        clr[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        if(clr[i]) continue;
        if(dfs(i, -1, mid, cur_ans, cur_e, -1)) return 1;
    }

    return 0;

}

int main()
{

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        for(int i = 0; i <= n+3; i++){
            v[i].clear();
        }

        for(int i = 0; i < m; i++){

            int x, y;
            cin >> x >> y;

            v[x].push_back({y, i});
            v[y].push_back({x, i});

        }

        int l = 1, r = m;
        vector<int> ans;
        while(l <= r){

            int mid = (l+r)/2;
            vector<int> cur_ans, cur_e;
            if(can(mid, n, cur_ans, cur_e)){

                r = mid-1;
                ans = cur_e;

            } else l = mid+1;

        }

        if(ans.empty()) cout << "-1\n";
        else {
            set<int> anss(ans.begin(), ans.end());
            for(auto itr = anss.begin(); itr != anss.end();){
                int c = *itr;
                cout << c+1;
                itr++;
                if(itr != anss.end()) cout << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}
