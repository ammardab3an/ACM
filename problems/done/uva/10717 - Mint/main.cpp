#include<bits/stdc++.h>

using namespace std;

int lcm(int a, int b)
{
    return (a*b) / __gcd(a,b);
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);
    while(true)
    {
        int n, t;
        cin >> n >> t;
        if(!n && !t) break;

        int coin[50];
        for(int i = 0; i < n; i++)
            cin >> coin[i];

        int table[10];
        for(int i = 0; i < t; i++)
            cin >> table[i];

        array<pair<int, int>,10> tables;
        tables.fill({INT_MIN, INT_MAX});

        for(int i = 0+0; i < n; i++)
        for(int j = i+1; j < n; j++)
        for(int k = j+1; k < n; k++)
        for(int l = k+1; l < n; l++)
        {
            int Lcm = lcm(coin[i], lcm(coin[j], lcm(coin[k], coin[l])));
            for(int m = 0; m < t; m++)
            {

                int tmp = table[m]-(table[m]%Lcm);
                tables[m].first = max(tables[m].first, tmp);
                tables[m].second = (tmp == table[m]) ? tmp : min(tables[m].second, tmp+Lcm);
            }
        }
        for(int m = 0; m < t; m++)
            cout << tables[m].first << " " << tables[m].second << endl;
    }
    return 0;
}
