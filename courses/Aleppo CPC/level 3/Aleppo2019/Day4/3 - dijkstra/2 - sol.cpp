#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 10010;
const int inf = 1e9;

int n , m ;
int dis[N];
vector< pair<int,int> >adj[N];
priority_queue< pair<int,int>,vector< pair<int,int> >,greater<pair<int,int>>
               >pq;

void solve(){

    scanf("%d %d",&n,&m);

    for(int i=0;i<=n;i++){
            adj[i].clear();
            dis[i]=inf;
        }
    while(!pq.empty())pq.pop();

    while( m-- ){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

    int src , des;
    scanf("%d %d",&src,&des);

    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if( dis[u] != d )continue;

        for(auto p:adj[u]){
            int v = p.first;
            int c = p.second;
            if( dis[v] > dis[u]+c ){
                dis[v] = dis[u]+c;
                pq.push({dis[v],v});
            }
        }

    }
    if( dis[des] >= inf )  printf("NO\n");
    else          printf("%d\n",dis[des]);
}

int main(){


int t;
scanf("%d",&t);
while( t-- )solve();

return 0;
}
