#include<bits/stdc++.h>

using namespace std;

bool allNine(string str)
{
    for(auto c : str)
        if(c != '9')
            return false;
    return true;
}
int main()
{
    int T;
    for(cin >> T; T; T--)
    {
        string inputNum;
        cin >> inputNum;

        int sz = inputNum.size();
        if(allNine(inputNum))
        {
            cout << '1' << string(sz-1, '0') << '1' << endl;
            continue;
        }

        int r = sz/2;
        int l = (sz%2) ? r : r-1;
        while(l >= 0 && inputNum[l] == inputNum[r])
        {
            l--; r++;
        }
        if(l < 0 || inputNum[l] < inputNum[r])
        {
            int r = sz/2;
            int l = (sz%2) ? r : r-1;
            int carry = 1;
            while(l >= 0)
            {
                int num = inputNum[l] - '0' + carry;
                carry = num / 10;
                inputNum[l] = num % 10 + '0';
                inputNum[r] = inputNum[l];
                l--; r++;
            }
        }
        else
        {
            while(l >= 0)
            {
                inputNum[r] = inputNum[l];
                l--; r++;
            }
        }
        cout << inputNum << endl;
    }
    return 0;
}
