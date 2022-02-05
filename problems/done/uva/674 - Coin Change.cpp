#include <bits/stdc++.h>

using namespace std;

long long mem[7500][5];
int coins[] = {1, 5, 10, 25, 50};
long long re(int v, int i)
{
    if(v == 0)  return 1;
    if(i == 5)  return 0;

    if(mem[v][i] != -1)
        return mem[v][i];

    long long path_1 = 0, path_2 = 0;
    if(v >= coins[i])
    {
        path_1 = re(v - coins[i], i);
        path_2 = re(v,          i+1);
    }

    return mem[v][i] = path_1 + path_2;
}
int main()
{
    memset(mem, -1, sizeof mem);
    for(int i; cin >> i;)
        cout << re(i, 0) << endl;

    return 0;
}
