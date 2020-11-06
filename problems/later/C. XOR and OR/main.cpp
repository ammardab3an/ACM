#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str_1, str_2;
    cin >> str_1 >> str_2;

    if(str_1.size() != str_2.size())
    {
        cout << "No";
        return 0;
    }

    bool xOr, Or;

    for(int i = 0; i < str_1.size(); i++)
    if(str_1[i] != str_2[i])
    {
        bool b = false;
        if(i+1 < str_1.size())
        {
            xOr = (str_1[i] - '0') ^ (str_1[i+1] - '0');
            Or  = (str_1[i] - '0') | (str_1[i+1] - '0');
            if(((str_2[i] - '0') == xOr && (str_2[i+1] - '0') == Or) || ((str_2[i+1] - '0') == xOr && (str_2[i] - '0') == Or))
                b = true;
        }
        if(i)
        {
            xOr = (str_1[i] - '0') ^ (str_1[i-1] - '0');
            Or  = (str_1[i] - '0') | (str_1[i-1] - '0');
            if(((str_2[i] - '0') == xOr && (str_2[i-1] - '0') == Or) || ((str_2[i-1] - '0') == xOr && (str_2[i] - '0') == Or))
                b = true;
        }

        if(!b)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
