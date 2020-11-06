#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int  vist[5][5];
pii  mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool in(int i, int j)
{
    return 0 <= i && i < 5 &&
           0 <= j && j < 5;
}
void printTheGrid()
{
    system("CLS");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << vist[i][j] << '\t';
        cout << endl << endl;
    }
    system("PAUSE");
}
int main()
{
    memset(vist, 0, sizeof vist); vist[0][0] = true;

    queue<pii> que; que.push({0, 0});

    while(!que.empty())
    {
        printTheGrid();

        pii fr = que.front(); que.pop();

        if(fr == (pii){4, 4}) break;

        for(auto p : mvArr)
        {
            int ni = fr.first  + p.first;
            int nj = fr.second + p.second;

            if(in(ni, nj) && !vist[ni][nj])
            {
                vist[ni][nj] = vist[fr.first][fr.second] +1;
                que.push({ni, nj});
            }
        }
    }
}
