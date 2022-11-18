#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    cin >> s;
    int n = s.length();

    vector<int> need(10, 0), del(10, 0);
    for(int i = 0; i < n; i++){
        need[s[i]-'0']++;
    }

    int len = 0;
    for(int i = 1; i <= 9; i++){
        int x;
        cin >> x;
        need[i] -= x;
        len += need[i];
        del[i] = x;
    }

    string ans = "";

    for(int i = 0; i < len; i++){
        // cout << "s " << s << endl;
        for(int d = 9; d >= 1; d--){
            if(need[d] == 0) continue;
            vector<int> temp(10, 0);
            for(int j = 0; j < n; j++){
                if(s[j] - '0' == d) break;
                temp[s[j]-'0']++;
            }
            bool ok = 1;
            for(int i = 1; i <= 9; i++){
                if(temp[i] > del[i]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                // cout << "D " << d << endl;
                int idx = -1;
                for(int j = 0; j < n; j++){
                    if(s[j] - '0' == d){
                        idx = j;
                        break;
                    }
                    del[s[j]-'0']--;
                }
                char cur = d + '0';
                cout << cur;
                // ans += cur;
                s = s.substr(idx+1);
                // cout << "s " << s << " idx " << idx << endl;
                n = s.length();
                need[d]--;
                break;
            }
        }
    }

    // cout << "herE" << endl;
    // cout << puts(ans.c_str());

    return 0;
}
