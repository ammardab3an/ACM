#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("D:\\input.txt", "r", stdin);

    string _str, str;
    bool f = false;
    while(getline(cin, str))
    {
        _str = "";
        for(auto c : str)
        {
            if(c == '"')
            {
                if(f)
                {
                    _str += "''";
                    f = false;
                }
                else
                {
                    _str += "``";
                    f = true;
                }
            }
            else
                _str += c;
        }
        cout << _str << endl;
    }
    return 0;
}
