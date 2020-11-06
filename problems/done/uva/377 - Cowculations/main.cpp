#include<bits/stdc++.h>

using namespace std;

int toInt(string num)
{
    int result = 0;
    int sz = num.size();
    map<char, int> mp = {{'V', 0}, {'U', 1}, {'C' ,2}, {'D', 3}};
    for(int i = 0; i < sz; i++)
        result += mp[num[sz-1-i]] * pow(4,i);
    return result;
}

string toFou(int num)
{
    string result = "";
    map<pair<bool, bool>, char> mp = {{{0,0},'V'}, {{0,1},'U'}, {{1,0},'C'}, {{1,1},'D'}};
    for(int i = 0; i < 8; i++)
        result.insert(result.begin(), mp[{num & (1 << i*2+1), num & (1 << i*2)}]);
    return result;
}

int main()
{
    string _num1 , _num2, ans;
    int k, num1, num2;
    char c;

    cout << "COWCULATIONS OUTPUT" << endl;
    cin >> k;
    while (k--)
    {
        cin >> _num1 >> _num2;
        num1 = toInt(_num1);
        num2 = toInt(_num2);

        for(int i = 0; i < 3; i++)
        {
            cin >> c;
            switch (c)
            {
            case 'A':
                num2 = num1 + num2;
                break;
            case 'L':
                num2 = num2 << 2;
                break;
            case 'R':
                num2 = num2 >> 2;
                break;
            }
        }

        cin >> ans;
        if (ans == toFou(num2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
