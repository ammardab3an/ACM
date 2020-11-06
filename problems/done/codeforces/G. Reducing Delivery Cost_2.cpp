#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld long double
#define F first
#define S second
#define pb2( x , y  ) push_back( make_pair( x , y ) )
#define pb( x ) push_back( x )
#define E end()
#define B begin()
#define mk(x ,z ) make_pair( x, z)
#define no cout<< "NO" << endl ;
#define yes cout << "YES" << endl ;

ll n, m , k , x , cost[1010][1010];

vector < pair< ll , ll > > ve1 ;


int main()
{

    cin >> n >> m >> k ;

	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++) if(i != j){
		cost[i][j] = 1e9;
	}
	
    vector< pair< ll ,ll >  > ed ;
    
    for( ll i =0 ; i < m ; i++ )
    {
        ll u , v, w;
        cin >> u >> v >> w ;
        cost[u][v] = cost[v][u] = w;
        ed.pb2( u , v )  ;
    }
	
	for(int k = 1; k <= n; k++)
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
		
    for( ll i = 0 ; i < k ; i++ )
    {
        ll u , v ;
        cin >> u >> v ;
        ve1.pb2( u , v ) ;
    }

    ll ans = 1e9;
    
    for( auto edge : ed )
    {
        ll su = 0 ;
        for( auto it : ve1 )
        {
        	ll xx = cost[it.F][edge.F] + cost[edge.S][it.S];
        	ll yy = cost[it.F][edge.S] + cost[edge.F][it.S];

            su += min(cost[it.F][it.S] , min(xx, yy)) ;
        }
        ans = min ( ans , su ) ;
    }

    cout << ans ;

}