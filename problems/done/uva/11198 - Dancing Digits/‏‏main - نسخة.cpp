#include<bits/stdc++.h>

using namespace std;

#define ai array<int, 8>
#define V first
#define N second
ai arr;
bool prime[100];

void fillPrimeArr()
{
    memset(prime, true, sizeof prime);
    for(int i = 2; i < 100; i++) if(prime[i])
        for(int j = i*i; j < 100; j += i)
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
        if(arr[i] != i+1 && -arr[i] != i+1)
            return false;
    return true;
}
void pai(ai arr)
{
    for(auto it : arr)
        cout << it << " ";
    cout << endl;
}

int bfs()
{
    map<ai, bool> vis;
    queue< pair<ai,int> > q;
    q.push({arr, 0});
    while(!q.empty())
    {
        pair<ai,int> f = q.front(); q.pop();
        if(isSeq(f.V))
            return f.N;
        vis[f.V];

        for(int i = 0+0; i < 8; i++)
        for(int j = i+1; j < 8; j++)
        if(f.V[i] * f.V[j] < 0 && prime[abs(f.V[i]) + abs(f.V[j])])
        {
            ai af[4] = {Swap(f.V, i, j-1), Swap(f.V, i, j), Swap(f.V, j, i+1), Swap(f.V, j, i)};
            //cout << f.V[i] << " " << f.V[j] << " " << f.N <<  endl;
            for(auto afi : af)
                if(!vis.count(afi))
                    q.push({afi, f.N+1});
        }
    }
    return -1;
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    fillPrimeArr();
    for(int T = 1; true; T++)
    {
        cin >> arr[0];
        if(!arr[0]) break;
        for(int i = 1; i < 8; i++)
            cin >> arr[i];
        printf("Case %d: %d\n", T, bfs());
    }
    return 0;
}
