#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int eig = 0;
    int dif = n - 11;

    for(int i = 11; i <= n; i++)
    {
        char c; cin >> c;
        eig += (c == '8');
    }

    cout << ((eig > dif/2) ? "YES" : "NO");
}
