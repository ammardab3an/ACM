#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const int N = 1e5+10;
const ll INF = 1e18;
int n,m,k;
vector<pii>p[N];
int s[N];
int y[N];
ll dist[N];
int rep[N];

int dik(){
    for(int i=0 ;i <=n ;i ++){
        dist[i] = INF;
    }
    dist[1] = 0;
    rep[1] = 1;
    priority_queue<pll,vector<pll>,greater<pll> >q;

    for(int i=0 ;i <k ;i ++){
        dist[s[i]] = min((ll)y[i],dist[s[i]]);
        rep[s[i]] = 1;
    }
    for(int i=1 ;i <=n ;i ++){
        if(dist[i] == INF)continue;
        q.push({dist[i],i});
    }


    while(!q.empty()){
        ll ds = q.top().fr;
        int x = q.top().sc;
        q.pop();
        if(ds > dist[x])continue;

        for(int i=0 ;i <p[x].size() ; i++){
            int go = p[x][i].fr;
            ll cost = p[x][i].sc;

            if(dist[go] < ds + cost)continue;
            if(dist[go] == ds + cost){
                rep[go]++;
                continue;
            }
            rep[go] = 1;
            dist[go] = ds + cost;
            q.push({dist[go],go});
        }
    }
    int del = 0;
    for(int i=0 ; i<k ;i ++){
        if(dist[s[i]] == y[i] && rep[s[i]] == 1){
            dist[s[i]] = INF;
            continue;
        }
        if(dist[s[i]] != y[i] || rep[s[i]] != 1)
            del++;
    }
    return del;
}

int main(){
    cin>>n>>m>>k;
    int u,v,x;
    for(int i=0 ;i <m ;i ++){
        scanf("%d%d%d",&u,&v,&x);
        p[u].push_back({v,x});
        p[v].push_back({u,x});
    }

    for(int i=0 ;i <k ;i ++){
        scanf("%d",&s[i]);
        scanf("%d",&y[i]);
    }

    cout<<dik()<<endl;

    return 0;
}
