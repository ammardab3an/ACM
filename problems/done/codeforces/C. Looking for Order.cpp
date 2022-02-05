// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

const int N   = 29;
const int MX  = 1 << 24;
const int inf = 1 << 30;

int n;
int x[N], y[N];
int dis[N][N];
int mem[MX];
int prv[MX];
int sol[MX][2];

int dp(int msk){

    int & ret = mem[msk];
    if(ret != -1) return ret;
    ret = inf;

    for(int i = 0; i < n; i++) if(msk & (1 << i)){

        int nDis = dp(msk - (1 << i)) + 2 * dis[n][i];

        if(nDis < ret){
            ret = nDis;
            sol[msk][0] = i;
            sol[msk][1] = -1;
            prv[msk] = msk - (1 << i);
        }

        for(int j = i+1; j < n; j++) if(msk & (1 << j)){

            int nDis = dp(msk - (1 << i) - (1 << j)) + dis[n][i] + dis[i][j] + dis[j][n];

            if(nDis < ret){
                ret = nDis;
                sol[msk][0] = i;
                sol[msk][1] = j;
                prv[msk] = msk - (1 << i) - (1 << j);
            }
        }
        break;
    }
    return ret;
}

void printPath(int msk){
    if(!msk) return;

    cout << sol[msk][0] + 1 << ' ';
    if(sol[msk][1] != -1)
        cout << sol[msk][1] + 1 << ' ';
    cout << 0 << ' ';

    printPath(prv[msk]);
}

int main(){

    int xs, ys;
    cin >> xs >> ys;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    x[n] = xs;
    y[n] = ys;

    for(int i = 0; i <= n; i++)
    for(int j = i; j <= n; j++)
        dis[i][j] = dis[j][i] = pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2);

    mem[0] = 0;
    fill_n(mem +1, MX, -1);
    cout << dp((1 << n) -1) << endl;

    cout << 0 << ' ';
    printPath((1 << n) -1);
}
