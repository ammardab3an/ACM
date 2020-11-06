#include <iostream>

using namespace std;

int main()
{
    int t, n, k;
    for(cin >> t; t--;)
    {
        cin >> n >> k; n--, k--;

        if(k > n/2)
            k = n-k;

        long long ans = 1; //ans = choose(n-1, k-1)
        for(int i = 1; i <= k; i++, n--)
        {
            ans *= n;
            ans /= i;
        }

        cout << ans << endl;
    }
}
