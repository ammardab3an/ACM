#include<bits/stdc++.h>

using namespace std;

int main()
{
    int inputInt, I, re, k = 1;
    while(k++)
    {
        cin >> inputInt;
        if (!inputInt) break;
        cout << "Case " << k-1 << ": ";
        I = inputInt +1;
        while(I--)
        {
            re = 0;
            for(int i = 1; i <= I; i++)
            {
                if (!(I % i)) re += i;
            }
            if (re == inputInt)
            {
                cout << I << endl;
                goto done;
            }
        }
        cout << -1 << endl;
        done: ;
    }
    return 0;
}
