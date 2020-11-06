#include <bits/stdc++.h>

using namespace std;

int main()
{
    string code, arr[10];
    cin >> code;
    for(int i = 0; i < 10; i++)
        cin >> arr[i];

    for(int a = 0; a < 71; a += 10)
    for(int n = 0; n < 10; n++)
    {
        for(int i = 0; i < 10; i++)
            if(code[a+i] != arr[n][i])
                goto Next;

        cout << n; break;

        Next:;
    }
}
