// by AmmarDab3an - Aleppo University

#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

lli calc(string str)
{
    lli ans = 1, sz = str.size();
    for(int i = (str[0] == '0'); i < sz; i++)
        ans *= str[i] - '0';
    return ans;
}
int main()
{
    string a, b;
    cin >> a >> b;

    int aSz = a.size();
    int bSz = b.size();
    int dif = bSz - aSz;

    if(dif)
        a.insert(0, dif, '0');

    string tmp = b;
    string ans = b;
    lli   xAns = calc(b);

    for(int i = 0; i < bSz; i++) if(b[i] - '0')
    {
        b = tmp;

        b[i] -= 1;
        for(int j = i+1; j < bSz; j++)
            b[j] = '9';

        lli xCur = calc(b);

        if(stoll(b) >= stoll(a) && xCur > xAns)
        {
            ans  = b;
            xAns = xCur;
        }
    }

    for(int i = (ans[0] == '0'); i < bSz; i++)
        cout << ans[i];
}
