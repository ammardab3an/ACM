#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

const int MOD = 1e9+7;

int add(int x, int y){
    return (1ll*x+y)%MOD;
}

int n, m;
int grid[1010][1010];
pair<int, int> mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int mem[1010][1010][4];

int go(int i, int j, int k){

    if(k < 0) k = 0;
    int &ret = mem[i][j][k];
    if(ret+1) return ret;

    int ans = 0;
    bool found = false;
    int cur = grid[i][j];

    for(auto [di, dj] : mvArr){
        int ni = i + di;
        int nj = j + dj;
        if(in(ni, nj) && grid[ni][nj]==cur+1){
            ans = add(ans, go(ni, nj, k-1));
            found = true;
        }
    }

    if(!found && !k){
        ans = 1;
    }

    return ret = ans;
}

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        cin >> grid[i][j];
    }

    memset(mem, -1, sizeof mem);

    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){

        bool found = false;
        int cur = grid[i][j];
        for(auto [di, dj] : mvArr){
            int ni = i + di;
            int nj = j + dj;
            if(in(ni, nj) && grid[ni][nj]==cur-1){
                found = true;
                break;
            }
        }

        if(!found){
            ans = add(ans, go(i, j, 3));
        }
    }

    cout << ans << endl;
}
