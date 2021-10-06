#include<bits/stdc++.h>

using namespace std;

bool larger(string s1, string s2)
{
    int d = s1.size() - s2.size();
    if(d != 0)
        return d > 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] > s2[i])
            return true;
        if(s1[i] < s2[i])
            return false;
    }
    return false;
}
int main()
{
    freopen("D:\\input.txt", "r", stdin);
    freopen("D:\\output.txt", "w", stdout);

    int T;
    for(cin >> T; T; T--)
    {
        string inputStr;
        cin >> inputStr;

        int sz = inputStr.size();
        if(to_string(stoi(inputStr)+1).size() > sz)
        {
            cout << '1' << string(sz-1, '0') << '1' << endl;
            continue;
        }

        int l = 0, r = 0;
        for(int i = 0; i < sz; i++)
            if(inputStr[i] != '0')
            {
                l += i;
                break;
            }
        for(int i = sz-1; i >= 0; i--)
            if(inputStr[i] != '0')
            {
                r += sz-1-i;
                break;
            }
        if(l)
        {
            inputStr.erase(0, l);
            sz = inputStr.size();
        }
        if(r)
        {
            inputStr.erase(sz-r, r);
            sz = inputStr.size();
        }

        bool b = false;
        if(sz % 2)
        {
            inputStr.insert(sz/2, string(1,inputStr[sz/2]));
            b = true;
            sz++;
        }

        for(int half = stoi(inputStr.substr(0, sz/2)); true; half++)
        {
            string halfStr = to_string(half);
            string _halfStr = halfStr;
            reverse(halfStr.begin(), halfStr.end());
            _halfStr.append(halfStr);


            if(larger(_halfStr, inputStr))
            {
                if(b)
                    _halfStr.erase(sz/2, 1);
                cout << _halfStr << endl;
                goto endFor;
            }
        }
        endFor:;
    }
    return 0;
}
