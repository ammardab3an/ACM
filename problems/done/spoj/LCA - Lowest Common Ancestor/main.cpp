// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int  n;
int  par[N];
bool vis[N];

int lca(int x, int y){

    memset(vis, false, sizeof vis);

    vis[x] = true;
    while(par[x] != x){
        x = par[x];
        vis[x] = true;
    }

    while(vis[y] != true)
        y = par[y];

    return y;
}

int main(){

    int T; cin >> T;
    for(int t = 1; t <= T; t++){

        cout << "Case " << t << ":\n";

        cin >> n;
        for(int i = 1; i <= n; i++)
            par[i] = i;

        for(int i = 1; i <= n; i++){
            int m; cin >> m; while(m--){
                int nd; cin >> nd; par[nd] = i;
            }
        }

        int q; cin >> q; while(q--){
            int x, y; cin >> x >> y;
            cout << lca(x, y) << endl;
        }
    }
}
