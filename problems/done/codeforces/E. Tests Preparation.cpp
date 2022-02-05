#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt" , "r", stdin );
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    long long tests[22];
    memset(tests, 0, sizeof tests);

    for(int tst = 0; tst < n; tst++)
    {
        int k;
        for(cin >> k; k--;)
        {
            int sl; cin >> sl; sl--;
            tests[tst] |= (1LL << sl);
        }
    }

    int mnBitMsk;
    int mnBitMskSz = INT_MAX;

    for(int bitMsk = 0; bitMsk < (1 << n); bitMsk++)
    {
        long long cuSum = 0;

        for(int i = 0; i < n; i++)
            if(bitMsk & (1 << i))
                cuSum |= tests[i];

        if(cuSum == ((1LL << m) -1))
        {
            int cuBitMskSz = __builtin_popcountll(bitMsk);

            if(cuBitMskSz < mnBitMskSz)
            {
                mnBitMsk   = bitMsk;
                mnBitMskSz = cuBitMskSz;
            }
        }
    }


    cout << mnBitMskSz << endl;

    for(int tst = 0; tst < n; tst++)
    {
        if(mnBitMsk & (1 << tst))
            cout << tst +1 << " ";
    }
}
