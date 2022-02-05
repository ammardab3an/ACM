#include <bits/stdc++.h>

using namespace std;

int M, C;
array<vector<int>, 20> garment;
int mem[200][20];

int re(int money_left, int garment_id)
{
    if(mem[money_left][garment_id] != -1)
        return mem[money_left][garment_id];

    if(garment_id == C)
        return money_left;

    int mn = INT_MAX;
    for(auto cost : garment[garment_id])
        if(cost <= money_left)
            mn = min(mn, re(money_left - cost, garment_id +1));

    return mem[money_left][garment_id] = mn;
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    int T;
    for(cin >> T;T;T--)
    {
        garment.fill({});
        memset(mem, -1, sizeof mem);

        cin >> M >> C;
        for(int K, i = 0; (i < C) && (cin >> K); i++)
        for(int P, j = 0; (j < K) && (cin >> P); j++)
            garment[i].push_back(P);

        int ans = re(M, 0);

        if(ans == INT_MAX)
            cout << "no solution" << endl;
        else
            cout << M - ans << endl;
    }
    return 0;
}
