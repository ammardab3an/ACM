#include <bits/stdc++.h>
using namespace std;

const int N =10100 , L=16 , inf = 1<<30 ;
vector<int>adj[N] , cost[N] ;
int p[L][N] , depth[N] , sum[N];

void dfs(int ver,int par,int dep,int CC){
depth[ver]=dep;
sum[ver]=CC;
p[0][ver]=par;

for(int i=0;i<adj[ver].size();i++){
int son=adj[ver][i] , _c=cost[ver][i] ;
if( son == par )continue;
    dfs(son,ver,dep+1,CC+_c);
}
}



int LCA(int u,int v){
if( depth[u] < depth[v] )swap(u,v);
int diff=depth[u]-depth[v];

for(int i=0;i<L;i++)if( diff&(1<<i) )u=p[i][u];

if( u == v )return u;

for(int i=L-1;i>=0;i--)
if( p[i][u]!=p[i][v] ){
    u=p[i][u];
    v=p[i][v];
}
return p[0][u];
}


int solve(int u,int v){
int lca=LCA(u,v);
return  sum[v]+sum[u]-2*sum[lca] ;
}

int up(int u,int k){
for(int i=0;i<L;i++)
    if( k&(1<<i) )
    u=p[i][u];
return u;
}


int kth(int u,int v,int k){

if( k ==1 )return u;
k--;
int lca = LCA(u,v);

int diff = depth[u] - depth[lca];

if( diff < k ){
    k-=diff;
    return up(v,depth[v]-depth[lca]-k);
}else
    return up(u,k);
}


int main(){

int t;
scanf("%d",&t);
while( t-- ){

    // --------------- initialization

    for(int i=0;i<N;i++){
        sum[i]=0;
        adj[i].clear();
        cost[i].clear();
        for(int j=0;j<L;j++)p[j][i]=-1;
    }

    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a , b , c ;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(b);
        cost[a].push_back(c);
        adj[b].push_back(a);
        cost[b].push_back(c);
        }

    dfs(1,-1,0,0);

    // --------------  LCA-build
    for(int i=1;i<L;i++)
        for(int j=1;j<=n;j++)
        if( p[i-1][j]!=-1 )
        p[i][j]=p[i-1][ p[i-1][j] ];

    while( 1 ){
      char s[10] ;
      scanf("%s",s);
      if(s[1]=='O')break;

      int u , v , k ;
      scanf("%d %d",&u,&v);
      if( s[0]=='K' ){
            scanf("%d",&k);
            printf("%d\n",kth(u,v,k));
      }else
        printf("%d\n",solve(u,v));
    }
}
return 0;
}
