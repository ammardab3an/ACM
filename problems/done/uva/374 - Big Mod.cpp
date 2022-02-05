#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
ull B, P, M;
ull pow_B(ull P)
{
    return (P) ? ((((pow_B(P/2) * pow_B(P/2))%M) * ((P%2) ? B : 1))%M) : 1;
}
int main()
{
    while(cin >> B >> P >> M)
    {
        B %= M;
        cout << pow_B(P) << endl;
    }
    return 0;
}
