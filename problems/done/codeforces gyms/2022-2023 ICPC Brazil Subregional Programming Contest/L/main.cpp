#include<bits/stdc++.h>

using namespace std;

const int NMAX = 1E5 + 10;

int n;
int col[NMAX];
vector<pair<int, int>> adj[NMAX];
int frq[NMAX];
int ans[NMAX];
int cans;

pair<int, map<int, int>> go(int u, int p, int i){

    pair<int, map<int, int>> cur;
    cur.second[col[u]]++;
    cur.first += frq[col[u]]-1;

    for(auto [v, j] : adj[u]) if(v != p){

        auto nxt = go(v, u, j);

        if(nxt.second.size() > cur.second.size()){
            swap(cur.first, nxt.first);
            swap(cur.second, nxt.second);
        }

        for(auto [v, f] : nxt.second){

            cur.second[v];
            auto it = cur.second.find(v);

            cur.first -= it->second*(frq[v]-it->second);
            it->second += f;
            cur.first += it->second*(frq[v]-it->second);
        }
    }

    if(p != -1){
        ans[i] = cur.first;
    }

    return cur;
}

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> col[i];
        col[i]--;
    }

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for(int i = 0; i < n; i++){
        frq[col[i]]++;
    }

    go(0, -1, -1);

    for(int i = 0; i < n-1; i++) cout << ans[i] << ' '; cout << endl;
}
