// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 250 + 10;

int arr[MAX][10];
array<vector<int>, MAX> adj;
int dis[MAX];

void solve(){

    int n, s, e;
    cin >> n >> s >> e;

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(char c : str)
            arr[i][c - '0']++;
    }

    for(int i = 0;   i < n; i++)
    for(int j = i+1; j < n; j++){

        int sm = 0;
        for(int k = 0; k < 10; k++)
            sm += min(arr[i][k], arr[j][k]);

        if(sm == 17){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    queue<int> que;
    que.push(s-1);
    dis[s-1] = 0;

    while(!que.empty()){
        int frm = que.front(); que.pop();
        for(auto to : adj[frm]) if(dis[to] == -1){
            dis[to] = 1 + dis[frm];
            que.push(to);
        }
    }

    cout << dis[e-1] << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){

        adj.fill({});
        memset(arr,  0, sizeof arr);
        memset(dis, -1, sizeof dis);

		solve();
	}
}
