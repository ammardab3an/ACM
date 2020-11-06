#include<bits/stdc++.h>

using namespace std;

// declarations
#define MAX_FISH 20
double pro[(1 << MAX_FISH)];
double eatPro[MAX_FISH][MAX_FISH];

int nBits(int n)
{
    int n1s = 0;
    while(n)
    {
        n1s += n % 2;
        n /= 2;
    }

    return n1s;
}

int choose2(int n)
{
    return (n*(n - 1))/2;
}

void dp(int mask, int n)
{
    if (!mask) return;
    int combinations = choose2(nBits(mask));

    for (int f1 = 0; f1 < n; f1++)
        if (mask & (1LL<<f1))
            for (int f2 = 0; f2 < n; f2++)
                if ((f1 != f2) && (mask & (1LL<<f2)))
                    pro[mask ^ (1LL<<f2)] += (pro[mask] * eatPro[f1][f2]) / combinations;

    dp(mask -1, n);
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> eatPro[i][j];

    int max_mask = (1LL << n) - 1;
    pro[max_mask] = 1.0;

    dp(max_mask, n);

    for(int i = 0; i < n; i++)
        cout << fixed <<  setprecision(6) << pro[(1LL << i)] << " ";

    return 0;
}

