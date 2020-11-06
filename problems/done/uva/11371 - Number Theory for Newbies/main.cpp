#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str, _str;
    long long i, _i;

    while(getline(cin, str))
    {
        sort(str.begin(), str.end(), [](int x, int y){return x>y;});

        _str = str;
        reverse(_str.begin(), _str.end());        _str = to_string(stoll(_str));
        _str.insert(1,string(str.size() - _str.size(), '0'));

        i = stoll(str);
        _i = stoll(_str);

        printf("%lld - %lld = %lld = 9 * %lld\n", i, _i, (i-_i), (i-_i)/9);
    }
    return 0;
}
