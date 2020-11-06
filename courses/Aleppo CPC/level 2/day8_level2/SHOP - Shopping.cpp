#include <bits/stdc++.h>

using namespace std;
int xd[4] = { 0 , 0 , 1 , -1 } ;
int yd[4] = { 1 , -1 , 0 , 0 };
int value[30][30] ;
int xD , xS , yD , yS ;
int n , m ;
char shop [27][27] = { '.' } ;

inline bool inside (int i , int j ){ return 0<=i && i < m && 0 <= j && j < n ; }
void path( int x , int y ){

if( shop[x][y] == 'D' ) return ;
for ( int i = 0 ; i < 4 ; i++ ){
    int nx = x + xd[i] ;
    int ny = y + yd[i] ;
    if( shop[nx][ny] != 'X' && inside( nx ,ny ) )
    {
        if( value[nx][ny] > (shop[nx][ny]-'0') + value[x][y] ){
        value[nx][ny] = (shop[nx][ny]-'0') + value[x][y] ;
        path( nx , ny ) ;
        }
    }

}

}




int main()
{

    while( 1 == 1 ){
            for( int i = 0 ; i <= 27 ;i++ ){
            for( int j = 0 ; j <= 27 ; j++ ){
            value[i][j] = 100000 ;}}
    scanf("%d%d" , &n , &m ) ;
     if( n == 0 && m == 0) return 0 ;
    for( int i = 0 ; i < m ; i++)
    {
        for( int j = 0 ; j < n ; j++ )
        {
           cin>>shop[i][j] ;
            if( shop[i][j] == 'S' )
            {
                xS = i ; yS = j ;
            }
            if( shop[i][j] == 'D' )
            {
                xD = i ; yD = j ;
            }
        }
    }
    value[xS][yS] = 0 ;
           path ( xS , yS ) ;

    int r = 1000000 ;

    for( int i = 0 ; i < 4 ;i++ )
    {
       int nx = xd[i] + xD ;
       int ny = yd[i] + yD ;

        if( shop[nx][ny] != 'X' && inside( nx ,ny ) ) r = min( r , value[nx][ny] ) ;
    }

              printf( "%d\n\n" , r ) ;
    }
    return 0;
}
