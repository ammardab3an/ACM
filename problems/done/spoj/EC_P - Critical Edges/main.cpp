// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

// Global Variables

const int nMAX = 3400;

int n, m;
vector<int> adj[nMAX];

int timer;
int Num[nMAX];
int Low[nMAX];

vector<pii> ans;

// -----------------------------------------------------------------

void dfs(int u, int p){

    Low[u] = Num[u] = timer++;

    for(auto v : adj[u]) if(v != p){

        if(!Num[v]){

            dfs(v, u);

            if(Num[u] < Low[v])
                ans.push_back({min(u, v), max(u, v)});

            Low[u] = min(Low[u], Low[v]);
        }
        else
            Low[u] = min(Low[u], Num[v]);
    }
}

void solve(){

    timer = 0;
    memset(Num, 0, sizeof Num);
    memset(Low, 0, sizeof Low);

    for(int i = 1; i <= n; i++)
        adj[i].clear();

    scanf("%d %d", &n, &m);

    while(m--){

        int u, v;
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans.clear();
    dfs(1, 0);

    if(ans.empty()){
        printf("Sin bloqueos\n");
        return;
    }

    printf("%d\n", ans.size());

    sort(ans.begin(), ans.end());
    for(auto br : ans)
        printf("%d %d\n", br.first, br.second);
}

int main(){

    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        printf("Caso #%d\n", i);
        solve();
    }
}
