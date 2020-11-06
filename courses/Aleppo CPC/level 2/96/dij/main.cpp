#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pip pair<int, pii>

const int R = 10, C = 10;
pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int dist[R][C];

bool in(int i, int j)
{
    return 0 <= i && i < R &&
           0 <= j && j < C;
}
void printDist()
{
    system("CLS");
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            cout << ((dist[i][j] == INT_MAX) ? 0 : dist[i][j]) << '\t';
        cout << endl << endl;
    }
    system("PAUSE");
}
void dij()
{
    for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
        dist[i][j] = INT_MAX;
    dist[5][5] = 0;

    priority_queue< pip, vector<pip>, greater<pip> > que; que.push({0, {5, 5}});
    while(!que.empty())
    {
        printDist();

        pip cur = que.top(); que.pop();

        if(dist[cur.second.first][cur.second.second] < cur.first)
            continue;

        for(auto p : mvArr)
        {
            int ni = cur.second.first  + p.first;
            int nj = cur.second.second + p.second;

            if(in(ni, nj) && (dist[ni][nj] > cur.first +1))
            {
                dist[ni][nj] = cur.first +1;
                que.push({dist[ni][nj], {ni, nj}});
            }
        }
    }
}
int main()
{
    dij();
}
