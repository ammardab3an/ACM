#include<bits/stdc++.h>

using namespace std ;

int n , m , tim , x , y ;

int dx[4]= { 1 , -1 , 0 , 0 };
int dy[4]= { 0 , 0 , -1 , 1 };

int power[200][200];
int path[200][200] ;
const int oo = 999999 ;


bool inside( int i , int j )
{
    return j >= 1 && i >= 1 && j <= n && i <= m ;
}

void dijkstra (  )
{
    queue < pair < int , int > > q ;
    q.push( make_pair( 1 , 1 ) ) ;
    path[1][1] = power[1][1] ;
    while( !q.empty() )
    {

        pair< int , int > ver ;
        ver = q.front() ;
        q.pop() ;

        int a=ver.first , b=ver.second ;
        for( int i = 0 ; i < 4 ; i++ )
        {
            int nx = a+dx[i] , ny = b+dy[i] ;

            if( inside ( nx , ny )  &&  ( path[a][b] + power[nx][ny] < path[nx][ny] )   )
            {
                path[nx][ny] = path[a][b] + power[nx][ny] ;
                q.push( make_pair( nx , ny ) ) ;
            }
        }
    }
}


int main()
{
    int t ;
    cin>>t ;
    while( t-- )
    {
       cin>>m>>n;
        for( int i = 1 ; i <= m ; i++ )
        {
            for( int j = 1 ; j <= n ; j++ )
            {
             cin>>power[i][j];
                path[i][j] = oo ;

            }
        }
  cin>>x>>y>>tim;

        dijkstra() ;

        if( tim - path[x][y] >= 0 )
        {
            cout<<"YES"<<endl<< tim - path[x][y] <<endl;
        }
        else
            cout<<"NO"<<endl;

    }


    return 0 ;

}
