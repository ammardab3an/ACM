// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

// Global Variables

const int nMAX = 3e5 + 10;

vector<int> adj[nMAX];
int Num[nMAX], Low[nMAX], clk;
int ans;

void dfs(int u, int par){

    Num[u] = Low[u] = clk++;

    for(auto v : adj[u]) if(v != par){

        if(!Num[v]){

            dfs(v, u);
            ans += Num[u] < Low[v];
            Low[u] = min(Low[u], Low[v]);
        }
        else{
            Low[u] = min(Low[u], Num[v]);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans;
}
