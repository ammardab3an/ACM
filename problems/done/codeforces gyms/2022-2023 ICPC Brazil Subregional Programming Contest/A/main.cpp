#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio();cin.tie(0); cout.tie(0);
    string s;
    int n;
    cin>>n;
    cin>>s;

    int cnt = 0, ans =0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'a') cnt++;
        else
        {
            if(cnt>1) ans += cnt;
            cnt = 0;
        }
    }
    if(cnt>1) ans += cnt;
    cout<<ans;
    return 0;
}
