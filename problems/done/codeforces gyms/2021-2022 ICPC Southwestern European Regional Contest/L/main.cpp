#include <bits/stdc++.h>
using namespace std;

const int NR = 44, NT = 733;
bool cell[NR][NT];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pair<int, int> dsu[NR][NT];
int sz[NR][NT];

pair<int, int> fnd(pair<int, int> x){
    if(dsu[x.first][x.second] == x) return x;
    return dsu[x.first][x.second] = fnd(dsu[x.first][x.second]);
}

void add(pair<int, int> a, pair<int, int> b){
    a = fnd(a);
    b = fnd(b);
    if(a == b) return;
    if(sz[a.first][a.second] > sz[b.first][b.second]) swap(a, b);
    sz[b.first][b.second] += sz[a.first][a.second];
    dsu[a.first][a.second] = b;
}

void block(int r, int st, int en)
{
    for(int i=st; i<=en; i++)
        cell[r][i] = 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(cell, 0, sizeof cell);
        for(int i = 0; i < NR; i++){
            for(int j = 0; j < NT; j++){
                dsu[i][j] = {i, j};
                sz[i][j] = 1;
            }
        }

        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            char c;
            cin>>c;
            if(c=='C')
            {
                int r, t1, t2;
                cin>>r>>t1>>t2;
                r *= 2;
                t1 *= 2;
                t2 *= 2;

                if(t1>t2)
                {
                    block(r, t1, 2*359 + 1);
                    block(r, 0, t2);
                }
                else
                {
                    block(r, t1, t2);
                }
            }
            else
            {
                int r1,r2,t;
                cin>>r1>>r2>>t;
                r1 *= 2; r2 *= 2;
                t *= 2;
                for(int j = r1; j<=r2; j++)
                {
                    cell[j][t] = 1;
                }
            }
        }

        for(int i = 0; i < 43; i++){
            for(int j = 0; j < 2*360; j++){
                if(cell[i][j]) continue;
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 0) continue;
                    y %= 2*360;
                    if(cell[x][y]) continue;
                    add({i, j}, {x, y});
                }
            }
        }
        //cout << "here" << endl;

        int ans = 0;
        pair<int, int> src = fnd({0, 0});
        for(int i = 0; i < 2*360; i++){
            pair<int, int> dist = fnd({41, i});
            if(dist == src) ans = 1;
        }

        puts(ans ? "YES" : "NO");


    }
    return 0;
}
