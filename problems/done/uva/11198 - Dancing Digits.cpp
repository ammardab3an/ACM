#include<bits/stdc++.h>

using namespace std;

#define ai array<int,8>
#define paii pair<ai, int>
#define V first
#define N second
bool prime[20];
bool can[8][8];
ai inArr, arr;

void fillPrimeArr()
{
    memset(prime, true, sizeof prime);
    for(int i = 2; i < 20; i++) if(prime[i])
        for(int j = i*i; j < 20; j += i)
            prime[j] = false;
}
ai Swap(ai arr, int f, int t)
{
    if(f < t)
    {
        for(int i = f; i < t; i++)
            swap(arr[i], arr[i+1]);
    }
    else
    {
        for(int i = f; i > t; i--)
            swap(arr[i], arr[i-1]);
    }
    return arr;
}
 bool isSeq(ai arr)
{
    for(int i = 0; i < 8; i++)
        if(arr[i] != i)
            return false;
    return true;
}

bool _vis[8][8][8][8][8][8][8][8];
void visSet(ai arr)
{
    _vis[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6]][arr[7]] = true;
}
bool vis(ai arr)
{
    return _vis[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6]][arr[7]];
}

int bfs()
{
    queue<paii> q;
    q.push({arr, 0});
    while(!q.empty())
    {
        paii f = q.front(); q.pop();

        if(isSeq(f.V))
            return f.N;

        if(vis(f.V)) continue;
        visSet(f.V);

        for(int i = 0+0; i < 8; i++)
        for(int j = i+1; j < 8; j++)
        if(can[f.V[i]][f.V[j]])
        {
            ai af[4] = {Swap(f.V, i, j-1), Swap(f.V, i, j), Swap(f.V, j, i+1), Swap(f.V, j, i)};
            for(auto afi : af)
                 q.push({afi, f.N+1});
        }
    }
    return -1;
}
int main()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);

    fillPrimeArr();
    for(int T = 1; true; T++)
    {
        cin >> inArr[0];
        if(!inArr[0]) break;
        for(int i = 1; i < 8; i++)
            cin >> inArr[i];
        for(int i = 0; i < 8; i++)
            arr[i] = abs(inArr[i])-1;

        memset(can, 0, sizeof can);
        memset(_vis, 0, sizeof _vis);

        for(int i = 0+0; i < 8; i++)
        for(int j = i+1; j < 8; j++)
                can[arr[i]][arr[j]] = can[arr[j]][arr[i]] =
                (inArr[i] * inArr[j] < 0 && prime[abs(inArr[i]) + abs(inArr[j])]);

        printf("Case %d: %d\n", T, bfs());
    }
    return 0;
}
