#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    for(cin >> T;T;T--)
    {
        int lower, upper;
        cin >> lower >> upper;

        int P = 0, D = 0;
        for(int p = lower; p <= upper; p++)
        {
            int d = 0;
            for(int i = 1; i <= sqrt(p); i++)
                if(p%i == 0)
                    d++;
            d *= 2;
            if(int(sqrt(p)) == sqrt(p))
                d--;
            if(d > D)
            {
                P = p;
                D = d;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", lower, upper, P, D);
    }
    return 0;
}

