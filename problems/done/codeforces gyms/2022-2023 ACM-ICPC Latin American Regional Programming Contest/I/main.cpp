#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
int grid[111][111];
bool vis[111][111];
pair<int, int> pos[111*111];
pair<int, int> mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int check(int bg){

    memset(vis, 0, sizeof vis);

    int ans = 0;

    for(int i = bg; i < n*m; i++){

        auto [x, y] = pos[i];

        if(i==bg || vis[x][y]){

            ans++;

            for(auto [dx, dy] : mvArr){
                int nx = x+dx;
                int ny = y+dy;
                if(in(nx, ny)){
                    vis[nx][ny] = true;
                }
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        cin >> grid[i][j];
        grid[i][j]--;
        pos[grid[i][j]] = {i, j};
    }

    int ans = 0;
    for(int i = 0; i < n*m; i++){
        ans = max(ans, check(i));
    }

    cout << ans << endl;
}
