// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

// Global Variables

const int nMAX = 3e5 + 10;

int n, m;
vector<pii> adj[nMAX];

int timer;
bool bridge;
int Vis[nMAX];
int Low[nMAX];

int vis[nMAX];
pii out[nMAX];

void Dfs_0(int u, int p){

    if(bridge) return;

    Low[u] = Vis[u] = timer++;

    for(auto nd : adj[u]){

        int v = nd.first;
        if(v == p) continue;

        if(!Vis[v]){

            Dfs_0(v, u);
            if(Vis[u] < Low[v])
                bridge = true;

            Low[u] = min(Low[u], Low[v]);
        }
        else
            Low[u] = min(Low[u], Vis[v]);
    }
}

void Dfs_1(int u, int p){

    vis[u] = true;
    for(auto nd : adj[u]) {

        int v = nd.first;
        int i = nd.second;
        if(v == p) continue;

        if(!out[i].first)
            out[i] = {u, v};

        if(!vis[v])
            Dfs_1(v, u);
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    Dfs_0(1, 0);

    if(bridge)
        printf("0");
    else{
        Dfs_1(1, 0);
        for(int i = 1; i <= m; i++)
            printf("%d %d\n", out[i].first, out[i].second);
    }
}
