// Problem: K. Binary Sequence
// Contest: Codeforces - LU ICPC Selection Contest 2020 and KFU Open Contest 2020
// URL: https://codeforces.com/gym/102862/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 2e5 + 10;
ll n , b[MAX] , ans , par[MAX] , m , u , v;

ll fnd ( ll x ){
    if ( par[x] == x ) return x ;
    return par[x] = fnd(par[x]) ;
}

void mrg( ll x , ll y ){
    x = fnd(x) ;
    y = fnd(y) ;
    if ( x != y ){
        par[x] = y ;
        b[y] += b[x] ;
    }
    return ;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    {
        cin >> n ;
        for ( int i = 0 ; i <= n ; i ++ )
            par[i] = i ;
        for ( int i = 1 ; i <= n ; i ++ )
            cin >> b[i] ;
        cin >> m ;
        for ( int i = 0 ; i < m ; i++ ){
            cin >> u >> v ;
            mrg( u,v ) ;
        }
        bool ans = 1 ;
        for ( int i = 1 ; i <= n ; i++ ){
            if ( fnd(i) == i && (b[i]&1) )
                ans = 0 ;
        }
        cout << (ans ? "Yes\n" : "No\n" ) ;

    }

}