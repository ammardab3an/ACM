#include <bits/stdc++.h>

using namespace std;
#define MAX 10000 + 10
int INF = 1e9 ;
bool vis[MAX][MAX] ;
int city[MAX][MAX] ;
int path[MAX][MAX] ;
vector< pair< int ,int > > adj[MAX] ;
string name , name1 , name2 ;
int from , to , n ;
int dist[2020202] ;
int dij( int src , int dest )
{
    priority_queue< pair< int , int > > q ;

    q.push( make_pair( 0 , src ) ) ;

    for( int i = 0 ; i <= n ; ++i )dist[i] = INF ;
    dist[src] = 0 ;
    pair< int , int > p ;

    while( !q.empty() )
    {
        p = q.top() ;
        int node = p.second ;
        int c = -1*p.first ;
        q.pop() ;
        if( dist[node] < c ) continue ;
        if( node == dest ) return c ;
        int len = adj[node].size() ;
        for( int i = 0 ; i < len ; i++ )
        {
            int x = adj[node][i].first ;
            int y = adj[node][i].second ;
            if( c + x < dist[y] )
            {
                dist[y] = c+x ;
                q.push( make_pair( -1*dist[y] , y ) ) ;
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
        memset( adj , 0 , sizeof(adj) ) ;
        map< string , int > mp ;
        int p , nr , cost ;
        cin>>n ;
        for( int index = 1 ; index <= n ; index++ )
        {
            cin>>name ;
            mp[name] = index ;
            cin>>p ;
            for( int j = 1 ; j <= p ; j++ )
            {
                cin>>nr>>cost ;
                adj[index].push_back( make_pair( cost , nr ) ) ;
            }
        }
        int q ;
        cin>>q ;
        while( q-- )
        {
            cin>>name1>>name2 ;
            from = mp[name1] ;
            to = mp[name2] ;
            int res = dij( from , to ) ;
            cout<<res<<endl ;

        }
    }
    return 0;
}
