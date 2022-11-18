#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        int k;
        cin >> s >> k;
        int n = s.length();
        int len = 0;
        string ans = "";
        for(int i = 0; i < n && len <= k; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
                len++;
                continue;
            } else {
                int num = 0;
                int j = i;
                while(s[j] >= '0' && s[j] <= '9') j++, num++;
                if(num >= 7){
                    len = 1e9;
                    break;
                }
                int toAdd = 0;
                for(int l = 0; l < num; l++){
                    toAdd *= 10;
                    toAdd += s[i+l]-'0';
                }
                len += toAdd;
                if(len > k) break;
                i = j;
                for(int l = 0; l < toAdd; l++){
                    ans += s[j];
                }
            }
        }

        if(len > k){
            puts("unfeasible");
            continue;
        } else puts(ans.c_str());

    }

    return 0;
}
