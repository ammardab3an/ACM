#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int  n, fi, fj, ti, tj;
set<pii> vec[2];
bool  arr[50][50];
bool vist[50][50];

pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool in(int i, int j)
{
    return 0 <= i && i < n &&
           0 <= j && j < n;
}

void bfs(int i, int j, bool b)
{
    memset(vist, false, sizeof vist);
    vist[i][j] = true;

    queue<pii> que; que.push({i, j});

    while(!que.empty())
    {
        pii fr = que.front(); que.pop();
        int ci = fr.first;
        int cj = fr.second;

        vec[b].insert({ci, cj});

        for(auto p : mvArr)
        {
            int ni = ci + p.first;
            int nj = cj + p.second;
            if(in(ni, nj) && !arr[ni][nj] && !vist[ni][nj]++)
                que.push({ni, nj});
        }
    }
}
int go()
{
    bfs(fi, fj, 0);

    if(vist[ti][tj])
        return 0;

    bfs(ti, tj, 1);

    int mn = INT_MAX;

    for(pii fr : vec[0])
    for(pii to : vec[1])
    {
        int cost = pow((fr.first - to.first), 2) + pow((fr.second - to.second), 2);
        mn = min(mn, cost);
    }

    return mn;
}
int main()
{
    cin >> n;
    cin >> fi >> fj >> ti >> tj;
    fi--, fj--, ti--, tj--;

    string inputStr;
    for(int i = 0; i < n; i++)
    {
        cin >> inputStr;
        for(int j = 0 ; j < n; j++)
            arr[i][j] = (inputStr[j] == '0' ? 0 : 1);
    }

    cout << go();
}

