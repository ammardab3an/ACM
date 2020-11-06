#include <bits/stdc++.h>
#include <array>
using namespace std;

//declaration
#define MAX 10000 + 10
#define INF INT_MAX

vector< pair< int ,int > > adj[MAX] ;
array<int, 2020202> dist;
string name , name1 , name2 ;
int from , to , n ;


int dij( int src , int dest )
{
    dist.fill(INF);
    dist[src] = 0 ;

    priority_queue< pair< int , int > > q ;
    q.push( { 0 , src } ) ;
    while( !q.empty() )
    {
        int node = q.top().second ;
        int cost = -q.top().first ;
        q.pop() ;

        if( dist[node] < cost ) continue ;
        if( node == dest ) return cost ;

        for(auto to:adj[node])
        {
            int x = to.first ;
            int y = to.second ;
            if( dist[y] > cost + x )
            {
                dist[y] = cost + x ;
                q.push( { -dist[y], y } ) ;
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
        memset(adj, 0, sizeof adj);
        map< string , int > mp ;
        int p , nr , cost ;
        cin>>n ;
        for( int index = 1 ; index <= n ; index++ )
        {
            cin >> name ;
            mp[name] = index ;
            cin >> p ;
            for( int j = 1 ; j <= p ; j++ )
            {
                cin >> nr >> cost ;
                adj[index].push_back( {cost, nr} ) ;
            }
        }
        int q ;
        cin>>q ;
        while( q-- )
        {
            cin >> name1 >> name2 ;
            from = mp[name1] ;
            to = mp[name2] ;
            int res = dij( from , to ) ;
            cout << res << endl ;

        }
    }
    return 0;
}
