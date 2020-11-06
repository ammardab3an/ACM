//IOIPALIN - Palindrome 2000

#include<bits/stdc++.h>

using namespace std;
int m[5000][5000];
string s;
int ln;

int dp(int l, int r)
{
    if (l >= r)
        return 0;

    if (m[l][r] != -1)
        return m[l][r];

    if (s[l] == s[r])
        return dp(l+1, r-1);

    int path_1 = 1+ dp(l+1, r);
    int path_2 = 1+ dp(l, r-1);

    return m[l][r] = min(path_1, path_2);

}
int main()
{
    memset(m, -1, sizeof m);
    cin >>ln;
    cin >>s;
    cout << dp(0,ln-1);
    return 0;
}
