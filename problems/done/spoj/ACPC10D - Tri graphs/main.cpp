#include <bits/stdc++.h>

using namespace std;

//declaration
int n;
int dis[100001][3];
int a[100001][3];

int mx[] = {0, 1, 1, 1};
int my[] = {1, 1, 0,-1};

bool in(int x,int y)
{
    return 0 <= x && x < n && 0 <= y && y < 3;
}
void DIJ()
{
    //x = 0, y = 1
    dis[0][1] = a[0][1];
    priority_queue < pair<pair<int,int>,int> >pq;

    pq.push({{0,-1}, -dis[0][1]});

    while(!pq.empty())
    {
        int x = -pq.top().first.first;
        int y = -pq.top().first.second;
        int d = -pq.top().second;
        pq.pop();

        if(x == n-1 && y == 1)
            break;
        if(dis[x][y] < d)// to prevent unnecessary repetition
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];

            if(!in(nx, ny))
                continue;

            int value = a[nx][ny];
            if(dis[nx][ny] > dis[x][y] + value )
            {
                dis[nx][ny] = dis[x][y] + value;

                pq.push({{-nx, -ny}, -dis[nx][ny]});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(true)
    {
        cin >> n;
        if(!n)
            return 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            dis[i][0] = dis[i][1] = dis[i][2] = INT_MAX;
        }
        DIJ();
        cout << t << ". " << dis[n-1][1] << endl;
        t++;
    }
}
