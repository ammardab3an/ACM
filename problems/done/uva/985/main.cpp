#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ppi pair<pii, int>

int R, C;
bool grid[510][510][4];
bool vist[510][510][4];
pii  mvLst[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool in(int i, int j){
    return 0 <= i && i < R &&
           0 <= j && j < C;
}
void bfs(){
    memset(vist, 0, sizeof vist);
    vist[0][0][0] = true;

    queue<ppi> q;
    q.push({{0, 0}, 0});

    while(!q.empty())
    {
        ppi tp = q.front(); q.pop();

        int i = tp.first.first;
        int j = tp.first.second;
        int t = tp.second;

        if(i == (R-1) && j == (C-1))
        {
            cout << t << endl;
            return;
        }

        for(int k = 0; k < 4; k++)
            if(grid[i][j][k])
            {
                int ni = i + mvLst[(t+k)%4].first;
                int nj = j + mvLst[(t+k)%4].second;
                if(in(ni, nj) && !vist[ni][nj][(t+1)%4])
                {
                    vist[ni][nj][(t+1)%4] = true;
                    q.push({{ni, nj}, t+1});
                }
            }
    }
    cout << "no path to exit" << endl;
}

int main()
{
    string inputStr;
    map<char, int> mp;
    mp['N'] = 0;
    mp['E'] = 1;
    mp['S'] = 2;
    mp['W'] = 3;

    while(cin >> R >> C){

        memset(grid, 0, sizeof grid);

        for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(!(i == (R-1) && j == (C-1)))
            {
                cin >> inputStr;
                for(auto c : inputStr)
                    grid[i][j][mp[c]] = true;
            }

        bfs();
    }
}
