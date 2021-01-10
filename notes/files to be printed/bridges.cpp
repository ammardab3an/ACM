#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3400;
int n , m ;
vector< pair< int, int > >adj[N];

int Low[N] , Num[N] , timer;
vector< pair<int,int> >out;


void dfs(int u,int p){
Low[u] = Num[u] = ++timer;

for(auto edg:adj[u]){
        int  v  = edg.first;
        int idx = edg.second;

        if( v == p )continue;
        if( !Num[v] ){ //not visited
            dfs(v,u);
            if( Num[u] < Low[v] )
                out.push_back( { u , v } );

            Low[u] = min( Low[u] , Low[v] );
        }else
            Low[u] = min( Low[u] , Num[v] );
    }

}


void solve(){

timer=0;
memset(Num,0,sizeof Num);
memset(Low,0,sizeof Low);
for(int i=1;i<=n;i++)adj[i].clear();
out.clear();

scanf("%d %d",&n,&m);
for(int i=1;i<=m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    adj[u].push_back( {v,i} );
    adj[v].push_back( {u,i} );
}

dfs(1,0);// find bridges in graph

if( out.empty() ){
    printf("Sin bloqueos\n");
    return;
}

for(auto &br:out)
    if( br.first > br.second )
        swap( br.first , br.second );

sort(out.begin(),out.end());

printf("%d\n",(int)out.size());
for(auto br:out)
    printf("%d %d\n",br.first,br.second);

}

int main(){

int tc;
scanf("%d",&tc);
for(int i=1;i<=tc;i++){
        printf("Caso #%d\n",i);
        solve();
}

return 0;
}
