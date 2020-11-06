#include <bits/stdc++.h>
using namespace std;
const int N =100100;
vector<int>adj[N];
int d[N] , par[N];
int n;

int bfs(int ver){
int ret;
memset(d,0,sizeof d);
memset(par,0,sizeof par);
queue<int>Q;
Q.push(ver);
d[ver]=0;
par[ver]=ver;

while(!Q.empty() ){
    ver=Q.front();
    Q.pop();
ret=ver;
    for(auto nxt:adj[ver])if( nxt!=par[ver] ){
        par[nxt]=ver;
        d[nxt]=1+d[ver];
        Q.push(nxt);
    }
}
return ret;
}

int main(){

scanf("%d",&n);
for(int i=1;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int far=bfs(bfs(1));
printf("%d\n",d[far]);

return 0;
}
