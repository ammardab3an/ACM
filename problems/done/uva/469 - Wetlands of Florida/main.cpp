#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int R, C;
char grid[100][100];
int  vist[100][100];
map<int, int> mp;

pii mvArr[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool in(int i, int j )
{
    return 0 <= i && i < R &&
           0 <= j && j < C;
}

int bfs(int i, int j, int m)
{
    vist[i][j] = m;

    int cnt = 1;

    queue<pii> que; que.push({i, j});

    while(!que.empty())
    {
        pii fr = que.front(); que.pop();

        for(auto p : mvArr)
        {
            int ni = fr.first  + p.first;
            int nj = fr.second + p.second;

            if(in(ni, nj) && (vist[ni][nj] == -1) && (grid[ni][nj] == 'W'))
            {
                vist[ni][nj] = m;
                que.push({ni, nj});
                cnt++;
            }
        }
    }
    return mp[m] = cnt;
}
int main()
{
    int T, I, J;
    cin >> T;

    string inputLine;
    cin.ignore(INT_MAX, '\n');
    getline(cin, inputLine);

    while(T--)
    {
        mp.clear();
        memset(vist, -1, sizeof vist);

        for(int r = 0, m = 0; true;)
        {
            getline(cin, inputLine);
            stringstream ss(inputLine);

            if(inputLine.empty())
                break;

            if((inputLine[0] == 'L') || (inputLine[0] == 'W'))
                ss >> grid[r++];

            else
            {
                C = strlen(grid[0]); R = r;

                ss >> I >> J; I--; J--;

                if(vist[I][J] != -1)
                    cout << mp[vist[I][J]] << endl;
                else
                    cout << bfs(I, J, m++) << endl;
            }
        }
        if(T) cout << endl;
    }
}
