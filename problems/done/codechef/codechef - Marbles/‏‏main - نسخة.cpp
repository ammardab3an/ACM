// By AmmarDab3an - Aleppo University

#include <iostream>

using namespace std;

int main()
{
    int t, n, k;
    for(cin >> t; t--;)
    {
        cin >> n >> k;

        int R = n-k;    // number of wanted marbles
        int N = k;      // number of colors

        N = N + R -1;

        if(R > N/2)
            R = N-R;

        // ans = (n+r-1)Cr where n equal to the number of wanted items and r equal to the number of colors.
        // https://en.wikipedia.org/wiki/Combination#Number_of_combinations_with_repetition
        long long ans = 1;
        for(int i = 1; i <= R; i++)
        {
            ans *= N;
            ans /= i;
            N--;
        }
        cout << ans << endl;
    }
}
