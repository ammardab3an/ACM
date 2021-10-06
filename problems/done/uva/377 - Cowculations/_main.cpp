#include<bits/stdc++.h>

using namespace std;

#define pcc pair<char,char>
#define S second
#define C first
map<pcc, pcc> mp;
void fillSumMp()
{
    mp[{'V', 'V'}] = {'V', 'V'};
    mp[{'V', 'U'}] = {'V', 'U'};
    mp[{'V', 'C'}] = {'V', 'C'};
    mp[{'V', 'D'}] = {'V', 'D'};
    mp[{'U', 'V'}] = {'V', 'U'};
    mp[{'U', 'U'}] = {'V', 'C'};
    mp[{'U', 'C'}] = {'V', 'D'};
    mp[{'U', 'D'}] = {'U', 'V'};
    mp[{'C', 'V'}] = {'V', 'C'};
    mp[{'C', 'U'}] = {'V', 'D'};
    mp[{'C', 'C'}] = {'U', 'V'};
    mp[{'C', 'D'}] = {'U', 'U'};
    mp[{'D', 'V'}] = {'V', 'D'};
    mp[{'D', 'U'}] = {'U', 'V'};
    mp[{'D', 'C'}] = {'U', 'U'};
    mp[{'D', 'D'}] = {'U', 'C'};
}
string sum(string num1, string num2)
{
    string answer = "VVVVVVVV";
    num1.insert(num1.begin(), 8 - num1.length(), 'V');
    num2.insert(num2.begin(), 8 - num2.length(), 'V');
    char carry  = 'V';
    pcc sm, _sm;
    for (int i = 0; i < 8; i++)
    {
        sm = mp[{num1[7 - i], num2[7 - i]}];
        _sm = mp[{sm.S, carry}];
        carry = mp[{_sm.C, sm.C}].S;
        answer[7 - i] = _sm.S;
    }
    return answer;
}
string shift_l(string num)
{
    num.insert(num.begin(), 8 - num.length(), 'V');
    for (int i = 0; i < 7; i++)
        num[i] = num[i+1];
    num[7] = 'V';
    return num;
}
string shift_r(string num)
{
    num.insert(num.begin(), 8 - num.length(), 'V');
    for (int i = 7; i > 0; i--)
        num[i] = num[i-1];
    num[0] = 'V';
    return num;
}
int main()
{
    fillSumMp();
    cout << "COWCULATIONS OUTPUT" << endl;
    int k;
    cin >> k;
    while (k--)
    {
        string num1 , num2;
        cin >> num1 >> num2;
        for(int i = 0; i < 3; i++)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'A':
                num2 = sum(num1, num2);
                break;
            case 'L':
                num2 = shift_l(num2);
                break;
            case 'R':
                num2 = shift_r(num2);
                break;
            }
        }
        string ans;
        cin >> ans;
        if (ans == num2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
