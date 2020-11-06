#include <bits/stdc++.h>

using namespace std;

//declaration
bool con[10][10][10][10];
bool vis[10][10][10][10];
array<int, 4> si, ti, fi;

int bfs()
{
    memset(vis, 0, sizeof vis);
    vis[si[0]][si[1]][si[2]][si[3]] = true;

    queue< pair<array<int, 4>, int> > que;
    que.push({si, 0});

    while(!que.empty())
    {
        pair<array<int, 4>, int> fr = que.front(); que.pop();

        if(fr.first == ti)
            return fr.second;

        array<int, 4> na = fr.first;

        for(int k = 0; k < 4; k++)
        {

            na[k] = (na[k]+1)%10;

            bool b = true;

            label: if(!con[na[0]][na[1]][na[2]][na[3]] && !vis[na[0]][na[1]][na[2]][na[3]])
            {
                que.push({na, fr.second+1});
                vis[na[0]][na[1]][na[2]][na[3]] = true;
            }

            if(b)
            {
                b = false;
                na[k] = (na[k]+8)%10;
                goto label;
            }

            na[k] = (na[k]+1)%10;
        }

    }

    return -1;
}
int main()
{
    int T, N;
    for(cin >> T; T; T--)
    {
        cin >> si[0] >> si[1] >> si[2] >> si[3];
        cin >> ti[0] >> ti[1] >> ti[2] >> ti[3];

        memset(con, 0, sizeof con);

        for(cin >> N; N; N--)
        {
            cin >> fi[0] >> fi[1] >> fi[2] >> fi[3];
            con[fi[0]][fi[1]][fi[2]][fi[3]] = true;
        }

        cout << bfs() << endl;
    }
}
