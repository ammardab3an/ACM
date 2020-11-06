#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 30;
const int inf = 1e9;

int n , m;
char a[N][N];
int dis[N][N];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
priority_queue< pair<int,pair<int,int>> >pq;

bool in(int x,int y){
    return 0<=x&&x<n && 0<=y&&y<m;
}

int cost(char c){
    if( '0'<=c&&c<='9' )
        return c-'0';
    if( c == 'D' )return 0;
    return inf;
}

int main(){

while(1){
        scanf("%d %d",&m,&n);
        if( !n && !m )break;

        for(int i=0;i<n;i++)
             scanf("%s",a[i]);

        int Sx=0,Sy=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if( a[i][j]=='S' ){
                    Sx=i;Sy=j;
                }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    dis[i][j]=inf;

        while(!pq.empty())pq.pop();

        dis[Sx][Sy]=0;
        pq.push( {0,{Sx,Sy}} );

        while(!pq.empty()){
              int d = -pq.top().first;
              int x =  pq.top().second.first;
              int y =  pq.top().second.second;
              pq.pop();

              if( dis[x][y] != d )continue;

              for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if( !in(nx,ny) )continue;
                if( a[nx][ny] == 'X' )continue;
                if( dis[nx][ny] > dis[x][y] + cost(a[nx][ny]) ){
                    dis[nx][ny] = dis[x][y] + cost(a[nx][ny]);
                    pq.push({ -dis[nx][ny] , {nx,ny} });
                }
              }
        }

        int ans=inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if( a[i][j]=='D' )
                    ans=dis[i][j];

        printf("%d\n",ans);
}


return 0;
}
