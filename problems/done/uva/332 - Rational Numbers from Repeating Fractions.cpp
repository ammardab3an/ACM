#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main()
{
    string str;
    for(int j, T = 1; (cin >> j) && (j != -1) && (cin >> str); T++)
    {
        int k = str.length() -j -2;

        ll a = stoll(str.substr(2, str.npos));
        ll b = (k) ? stoll(str.substr(2, k)) : 0;
        ll c = round(pow(10, j+k));

        if(j) a -= b, c -= pow(10, k);
        ll gcd = __gcd(a, c);

        printf("Case %d: %lld/%lld\n", T, a/gcd, c/gcd);
    }
    return 0;
}
