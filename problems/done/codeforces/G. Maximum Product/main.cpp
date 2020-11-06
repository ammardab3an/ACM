// by AmmarDab3an - Aleppo University

#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

lli calc(string num)
{
    lli ans = 1;
    for(char c : num)
        ans *= c - '0';
    return ans;
}
int main()
{
    lli a, b;
    cin >> a >> b;

    string strA = to_string(a);
    string strB = to_string(b);

    lli calcA = calc(strA);
    lli calcB = calc(strB);

    lli ans  = b;
    lli cAns = calcB;

    string tmp = strB;
    for(int sz = strB.size(), i = 0; i < sz; i++) if(strB[i] - '0')
    {
        strB = tmp;

        strB[i] -= 1;
        for(int j = i+1; j < sz; j++)
            strB[j] = '9';

        b     = stoll(strB);
        calcB = calc(to_string(b));

        if(b >= a && calcB > cAns)
        {
            ans  = b;
            cAns = calcB;
        }
    }
    cout << ans;
}
