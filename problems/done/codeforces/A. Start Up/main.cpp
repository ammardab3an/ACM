#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<char, bool> mp; string d;

    d = "AHIMOTUVWXY";
    for(auto c : d)
        mp[c] = false;

    d = "BCDEFGJKLNPQRSZ";
    for(auto c : d)
        mp[c] = true;


    string str;
    cin >> str;

    int l = 0;
    int r = str.size() -1;

    while (r >= l)
    {
        if (str[l] != str[r] || mp[str[l]])
        {
            cout << "NO";
            return 0;
        }
        l++;
        r--;
    }
    cout << "YES";
    return 0;
}
