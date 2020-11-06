#include <bits/stdc++.h>

using namespace std;

int N, mxMsk;
bool grid[20][20];
long long mem[1 << 21];

long long go(int bitMsk)
{
    int i =__builtin_popcount(bitMsk);

    if(i == N && bitMsk == mxMsk)
        return 1;

    if(mem[bitMsk] != -1)
        return mem[bitMsk];

    long long cnt = 0;

    for(int j = 0; j < N; j++)
        if(grid[i][j] && !(bitMsk & (1 << j)))
            cnt += go(bitMsk | (1 << j));

    return mem[bitMsk] = cnt;
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

        mxMsk = (1 << N) - 1;
        cout << go(0) << endl;
    }
}
