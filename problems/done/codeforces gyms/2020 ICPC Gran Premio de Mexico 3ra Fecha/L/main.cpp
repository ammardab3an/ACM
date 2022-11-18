#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    set<string> s;

    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        s.insert(x);
    }

    int ans = 0;

    while(!s.empty()){

        ans++;
        string cur = *s.begin();
        s.erase(s.begin());
        int len = cur.length();
        for(int i = 0; i < len; i++){
            char curr = cur.back();
            cur.pop_back();
            cur = curr + cur;
            s.erase(cur);
        }


    }

    cout << ans << endl;

    return 0;
}
