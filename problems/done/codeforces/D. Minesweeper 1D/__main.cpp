#include<bits/stdc++.h>

using namespace std;

//declarations
long long g = 0;

map< pair<char,char>, vector<char> > mp;

void fillTheMap()
{
    mp[{'0', '0'}] = {'0'};
    mp[{'0', '1'}] = {'0', '*'};
    mp[{'0', '*'}] = {'1'};
    mp[{'0', '?'}] = {'0', '1', '*'};
    mp[{'0', '#'}] = {'0'};

    mp[{'1', '0'}] = {'0', '*'};
    mp[{'1', '1'}] = {'*'};
    mp[{'1', '2'}] = {'*'};
    mp[{'1', '*'}] = {'1', '*'};
    mp[{'1', '?'}] = {'0', '1', '*'};
    mp[{'1', '#'}] = {'0', '*'};

    mp[{'2', '1'}] = {'*'};
    mp[{'2', '2'}] = {'*'};
    mp[{'2', '*'}] = {'*'};
    mp[{'2', '?'}] = {'*'};
    mp[{'2', '#'}] = {'*'};

    mp[{'#', '0'}] = {'0'};
    mp[{'#', '1'}] = {'0', '*'};
    mp[{'#', '2'}] = {'*'};
    mp[{'#', '*'}] = {'1', '*'};
    mp[{'#', '?'}] = {'0', '1', '2', '*'};
    mp[{'#', '#'}] = {'0', '1', '2', '*'};

    mp[{'*', '0'}] = {'1'};
    mp[{'*', '1'}] = {'1', '*'};
    mp[{'*', '2'}] = {'*'};
    mp[{'*', '#'}] = {'1', '*'};
    mp[{'*', '?'}] = {'1', '2', '*'};
    mp[{'*', '*'}] = {'2', '*'};
}
bool goodToGo(string str, int l, int r)
{
    char c, _c, c_;
    int cnt, _cnt;

    for(int i = l; i < r; i++)
    {
        c  = str[i];
        _c = str[i-1];
        c_ = str[i+1];

        switch (c)
        {
        case '0':
            if (_c == '*' || c_ == '*')
                return 0; break;

        case '1':
            cnt  = (_c == '*') + (c_ == '*');
            _cnt = (c_ == '?') + (_c == '?');
            if (!((cnt == 1) || (!cnt && _cnt)))
                return 0; break;

        case '2':
            if ((c_ == '?') + (_c == '?') + (_c == '*') + (c_ == '*') < 2)
                return 0; break;
        }
    }
    return true;
}
void re(string str, int index, int sz)
{
    if (!goodToGo(str, max(index-3, 1), min(index+3, sz-1)))
        return;

    for (int i = index; i < sz; i++)
        if (str[i] == '?')
        {
            for ( auto c : mp[{str[i-1], str[i+1]}] )
            {
                str[i] = c;
                re(str, index +1, sz);
            }
            return;
        }
    g = (g+1) % 1000000007;
}
int main()
{
    string str;
    cin >> str;
    str = '#' + str + '#';

    fillTheMap();

    re(str, 1, str.size());
    cout << g;

    return 0;
}
