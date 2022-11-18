#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for(auto &s : vec) cin >> s;

    map<string, int> mp;
    for(auto s : vec){

        int p = -1;
        for(int i = 0; i < s.size(); i++) if(s[i]=='*'){
            p = i;
            break;
        }
        assert(p+1);

        for(int i = 0; i < 26; i++){
            s[p] = 'a' + i;
            mp[s]++;
        }
    }

    pair<int, string> ans = {0, ""};

    for(auto [s, v] : mp){
        if(v > ans.first || (v==ans.first && s < ans.second)){
            ans = {v, s};
        }
    }

    cout << ans.second << ' ' << ans.first << endl;
}
