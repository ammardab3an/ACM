#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    for(cin >> T; T--;)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        long long ans = abs(a-b) + abs(a-c) + abs(b-c);

        for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++)
        for(int k = -1; k < 2; k++)
        {
            long long _a = a + i;
            long long _b = b + j;
            long long _c = c + k;
            ans = min(ans,  abs(_a-_b) + abs(_a-_c) + abs(_b-_c));
        }
        cout << ans << endl;
    }
}
