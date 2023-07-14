#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base:sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<string> v(n);
        for(auto &x : v) cin >> x;

        vector<string> ans;

        while(!v.empty()){
            vector<string> v1;
            int n = v.size();
            vector<int> cnt(26);
            for(int i = 0; i < n; i++){
                cnt[v[i]-'A']++;
            }
            int mx = 0;
            for(int c : cnt) mx = max(mx, c);

            for(int i = 0; i < 26; i++){

            }

            for(int i = 0; i < n; i++){
                string cur = "";
                for(char c : v[i]){
                    if(cnt[c-'A'] == mx) cur += c;
                }
                if(cur.length() > 0) v1.push_back(cur);
            }
            string del = "";
            for(int i = 0; i < 26; i++){
                if(cnt[i] != mx && cnt[i] != 0){
                    del += char('A' + i);
                }
            }
            ans.push_back(del);
            v = v1;
        }

    }

    return 0;
}
