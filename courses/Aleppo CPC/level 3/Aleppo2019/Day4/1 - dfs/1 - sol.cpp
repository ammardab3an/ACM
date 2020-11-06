#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vis[123][123];
char c[123][123];
int n , m , k;
priority_queue<pair<int,int>>Q;
vector<pair<int,int>>v[1234];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int cnt;


bool in(int i,int j){ return 1<=i&&i<=n&&1<=j&&j<=m; }

void dfs(int i,int j){
vis[i][j]=1;
v[cnt].push_back({i,j});

for(int k=0;k<4;k++){
    int x=i+dx[k];
    int y=j+dy[k];
    if( !in(x,y) )continue;
    if( vis[x][y] )continue;
    if( c[x][y]!='.' )continue;
    dfs(x,y);
}

}

int main(){


cin>>n>>m>>k;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cin>>c[i][j];

for(int i=1;i<=n;i++){
    if( c[i][1]=='.' && !vis[i][1]){
        dfs(i,1);
    }
    if( c[i][m]=='.' && !vis[i][m] ){
        dfs(i,m);
    }
}
for(int i=1;i<=m;i++){
    if( c[1][i]=='.' && !vis[1][i]){
        dfs(1,i);
    }
    if( c[n][i]=='.' && !vis[n][i] ){
        dfs(n,i);
    }
}

for(int i=2;i<n;i++)
    for(int j=2;j<m;j++)
if( !vis[i][j] && c[i][j]=='.' ){
    cnt++;
    dfs(i,j);
}

for(int i=1;i<=cnt;i++)Q.push( {-(v[i].size()),i} );

int stp=0;
while( Q.size()>k ){

int i=Q.top().second;
Q.pop();

for(int j=0;j<v[i].size();j++){
    int x=v[i][j].first;
    int y=v[i][j].second;
    c[x][y]='*';
    stp++;
}

}
cout<<stp<<endl;
for(int i=1;i<=n;i++,cout<<endl)
    for(int j=1;j<=m;j++)
        cout<<c[i][j];

return 0;
}