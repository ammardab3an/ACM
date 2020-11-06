#include<bits/stdc++.h>

using namespace std;

const int N = 10010;

int  n;
int  dis[N][N];
int  par[N];
int  vis[N];

int dist(int a, int b){

    memset(vis, false, sizeof vis);

    int ans = 0;

    vis[a] = 0;
    while(par[a] != a){
        vis[par[a]] = vis[a] + dis[a][par[a]];
        a = par[a];
    }

    vis[b] = 0;
    while(par[b] != b){
        if(vis[par[b]]){
            ans += vis[par[b]] + vis[b] + dis[b][par[b]];
        }
        else
            vis[par[b]] = vis[b] + dis[b][par[b]];
    }

    return ans;
}

int main(){

    int t; cin >> t; while(t--){

        cin >> n;

        for(int i = 1; i <= n; i++)
            par[i] = i;

        for(int i = 1; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            dis[a][b] = dis[b][a] = c;
        }

        for(string fn; cin >> fn;)

            int a, b, c;
            if(fn == "DIST"){
                cin >> a >> b;
                cout << dist(a, b) << endl;
            }
            else if(fn == "KTH"){
                cin >> a >> b >> c;
                cout << kth(a, b, c) << endl;
            }
            else break;
        }
    }
}
