#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const ll INF = 1e18;
const int N = 1e3+10;

int n,m;
vector<pll>p[2][N];
ll dist[N];

int t[N];
int c[N];


void dik(int in,int st){
    for(int i=0 ;i <=n ;i ++){
        dist[i] = INF;
    }

    dist[st] = 0;
    priority_queue<pll,vector<pll>,greater<pll> >q;
    q.push({0,st});
    while(!q.empty()){
        pll t = q.top();
        q.pop();
        if(t.fr > dist[t.sc])continue;
        for(int i=0 ;i <p[in][t.sc].size() ; i++){
            int go = p[in][t.sc][i].fr;
            ll w = p[in][t.sc][i].sc;
            if(dist[go] <= w +t.fr)continue;
            dist[go] = w+t.fr;
            q.push({dist[go],go});
        }
    }
    if(!in){
        for(int i=1 ; i<=n ;i ++){
            if(i == st)continue;
            if(dist[i] <= t[st]){
                p[1][st].push_back({i,c[st]});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int st,en;
    cin>>st>>en;
    int x,y;
    ll w;
    for(int i=0 ;i <m ;i++){
        scanf("%d%d%lld",&x,&y,&w);
        p[0][x].push_back({y,w});
        p[0][y].push_back({x,w});
    }

    for(int i=1 ;i <=n ;i ++){
        scanf("%d%d",&t[i],&c[i]);
        dik(0,i);
    }
    dik(1,st);
    if(dist[en] < INF){
        printf("%lld\n",dist[en]);
    }
    else printf("-1\n");
    return 0;
}
