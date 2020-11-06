#include <bits/stdc++.h>

using namespace std;

int N;
bool grid[20][20];
long long mem[1 << 21];

void go(int bitMsk)
{
    int i = __builtin_popcount(bitMsk);

    if(i == N)
    {
        mem[bitMsk] = (bitMsk == (1 << N)-1) ? 1 : 0;
        return;
    }

    if(mem[bitMsk] == -1)
    {
        mem[bitMsk]++;

        for(int j = 0; j < N; j++)
        if(grid[i][j] && !(bitMsk & (1 << j)))
        {

            go(bitMsk | (1 << j));
            mem[bitMsk] += mem[bitMsk | (1 << j)];
        }
    }
}
int main()
{
    int T;
    cin.tie(NULL);
    for(cin >> T;T;T--)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];

        memset(mem, -1, sizeof mem);

        go(0);
        cout << mem[0] << endl;
    }
}
