#include <bits/stdc++.h>

using namespace std;

int coins[] = {50, 25, 10, 5, 1};
int re(int v)
{
    if(!v) return 0;

    int mn = 1e10;
    for(auto c:coins) if(v >= c)
    {
        mn = min(mn, 1 + re(v - c));
    }
    return mn;
}
int main()
{
    for(int i; cin >> i;)
        cout << re(i) << endl;

    return 0;
}
