// this is BFS

#include <bits/stdc++.h>

using namespace std;


int n , m ;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
char maze[1001][1001];
bool vis[1001][1001];
int xs , ys ;

bool inside( int i , int j  ){ return 1<=i && i<=n && 1<=j && j<=m ; }
bool edge(int i ,int j){ return i==1 || i==n || j==1 || j==m ; }



bool bfs(int a , int b){
vis[a][b]=1;
queue<pair<int,int> >q;
q.push( make_pair(a,b) );
pair<int,int>p;
while( ! q.empty() ){
p=q.front();
q.pop();

int x=p.first , y=p.second;

for(int k=0;k<4;k++){
int X=x+dx[k] , Y=y+dy[k] ;

if( inside(X,Y) && vis[X][Y] == 0 &&  maze[X][Y]=='.' ){

if( edge(X,Y) )return 1;
q.push( make_pair(X,Y) );
vis[X][Y]=1;
}

}

}
return 0;
}

int main()
{

    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d",&n,&m);
int c=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{cin>>maze[i][j];
vis[i][j]=0;
if( maze[i][j]=='.' && edge(i,j) ){c++; xs=i ; ys=j;  }
}

     if( c != 2 ){printf("invalid\n");continue;}

    if( bfs(xs,ys) )  {printf("valid\n");}
    else             {printf("invalid\n");}


    }
    return 0;
}
