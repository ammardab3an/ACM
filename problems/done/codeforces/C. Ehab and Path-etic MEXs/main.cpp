// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

// Global Variables

const int MAX = 1e5 + 10;
vector<pii> adj[MAX];
int         ans[MAX];

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int u, v;  cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int nd = -1;

    for(int i = 0; i < n; i++){
        if(adj[i].size() >= 3){
            nd = i;
            break;
        }
    }

    if(nd == -1){
        for(int i = 0; i < n-1; i++)
            cout << i << endl;
    }
    else{
        memset(ans, -1, sizeof ans);

        int cnt = 0;

        for(int i = 0; i < 3; i++)
            ans[adj[nd][i].second] = cnt++;

        for(int i = 0; i < n-1; i++){
            ans[i] = (ans[i] != -1) ? ans[i] : cnt++;
            cout << ans[i] << endl;
        }
    }
}
