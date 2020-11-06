#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000 ;
int n , k , av , bv , a , we , b , w[10001][10001];
int path[10001] ;
vector < int > adj[10001] ;
void dij( int a )
{
    queue < int > q ;
    q.push( a ) ;
    path[a] = 0 ;
    while(!q.empty() )
    {
        int node = q.front() ;
        q.pop() ;
        int l = adj[node].size() ;

        for( int i = 0 ; i < l ; i++ )
        {
            int ver = adj[node][i] ;
            if( path[ver] > path[node] + w[node][ver] )
            {
                path[ver] = path[node] + w[node][ver] ;
                q.push( ver ) ;
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
        for( int i = 1 ; i <= 10001; i++ )
            path[i] = INF ;
        for( int i = 1 ; i <= 10001; i++ )
            adj[i].clear() ;
        // cout<<path[3]<<endl;
        cin>>n>>k;
        for( int i = 0 ; i < k ; i++ )
        {
            cin>>av>>bv>>we ;
            w[av][bv] = we ;
            adj[av].push_back( bv ) ;
            path[av] = INF ;
        }
        cin>>a>>b ;
        dij( a ) ;
        if( path[b] == INF )
            cout<<"NO"<<endl;
        else
            cout<<path[b]<<endl;
    }
    return 0;
}
