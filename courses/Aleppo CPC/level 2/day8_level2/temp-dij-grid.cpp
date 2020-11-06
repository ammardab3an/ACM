#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int dx[4]= { 1 , -1 , 0 , 0 };
int dy[4]= { 0 , 0 , -1 , 1 };
int a[200][200] , n , m;
int dis[200][200] ;
map< pair< int , int > , pair< int , int > > par ;
const int oo = 999999 ;
bool inside( int i , int j )
{
    return j >= 1 && i >= 1 && i <= n && j <= m ;
}
int tx , ty ;
void dij( )
{
    dis[1][1] = a[1][1] ;
    priority_queue< pair< int ,pair< int , int > > > q ;
    q.push({-1*dis[1][1] , {1,1}}) ;
    while( !q.empty() )
    {
        int x = q.top().second.first ;
        int y = q.top().second.second ;
        int d = q.top().first*-1 ;
        q.pop() ;
        if( x == tx && y == ty )break ;
        for( int i = 0 ; i < 4 ; ++i )
        {
            int nx = x + dx[i] ;
            int ny = y + dy[i] ;
            if( !inside(nx,ny) )continue ;
            if( dis[nx][ny] > dis[x][y] + a[nx][ny] )
            {
                dis[nx][ny] = d + a[nx][ny] ;
                par[ {nx,ny} ] = { x , y } ;
                q.push( { -1*dis[nx][ny] , {nx,ny} } ) ;
            }
        }
    }
}
int main()
{
    int T ;
    cin>>T ;
    while( T-- )
    {
        cin>>n>>m ;
        for( int i = 1 ; i <= n ; ++i )
        {
            for( int j = 1 ; j <= m ; ++j )
            {
                cin>>a[i][j] ;
                dis[i][j] = INF ;
            }
        }
        int t ;
        cin>>tx>>ty>>t ;
        dij() ;
        if( dis[tx][ty] <= t )
        {
            cout<<"Yes\n";
            cout<<t-dis[tx][ty]<<endl;
            while( par.count({tx,ty}) )
            {
                cout<<tx<<" "<<ty<<endl;
                pair< int , int > p = par[ {tx,ty}] ;
                tx = p.first ;
                ty = p.second ;
            }
            cout<<tx<<" "<<ty<<endl;
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
