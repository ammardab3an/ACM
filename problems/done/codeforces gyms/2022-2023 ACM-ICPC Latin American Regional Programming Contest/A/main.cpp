#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N=1e3+10;

int n;
int dis[N],cnt[N],to[N][2];
bool win[N];

void bfs(int root){
    queue<pair<ll,ll>>q;
    for(int i=1;i<N;i++){
        cnt[i]=0;
        dis[i]=1e7;
    }
    q.push({root,1});
    while(q.size()){
        int nd=q.front().first;
        int d=q.front().second;
        q.pop();
        if(d>dis[nd]){
            continue;
        }else if(d==dis[nd]){
            cnt[nd]++;
            continue;
        }
        dis[nd]=d;
        cnt[nd]=1;
        q.push({to[nd][0],d+1});
        q.push({to[nd][1],d+1});
    }
    for(int i=1;i<=n;i++){
        int cntt=2;
        if(dis[i]>1e6)continue;
        for(int j=0;j<2;j++){
            if(dis[to[i][j]]<dis[i]+1||cnt[to[i][j]]>1)cntt--;
        }
        if(!cntt){
            win[i]=0;
        }
    }

}



int solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        win[i]=1;
        cin>>to[i][0]>>to[i][1];
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    for(int i=1;i<=n;i++){
        if(!win[i])cout<<"Y";
        else cout<<"N";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
