// Problem: D1. Too Many Segments (easy version)
// Contest: Codeforces - Codeforces Round #595 (Div. 3)
// URL: https://codeforces.com/contest/1249/problem/D1
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

const int MAX = 3e5 + 10;

ll n , k ;
ll l[MAX] , r[MAX] ;
set < pair < ll , pair <ll,ll> > > st ;
set < pair < ll , pair <ll,ll> > > in ;
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    
    cin >> n >> k ;

    for ( int i = 0 ; i < n ; i ++ ){
        cin >> l[i] >> r[i] ;
        st.insert( { l[i] , {0,i}  } ) ;
        st.insert( { r[i] , {1,i}  } ) ;
    }

    int cnt = 0 ;
    vector<int> vec ;

    while ( !st.empty() ){
        
        auto it = st.begin() ;

        ll tme = it->F ;
        ll type = it->S.F ;
        ll idx = it->S.S ;
        
        st.erase(st.begin()) ;
        
        if ( type == 0 ){
            in.insert( {r[idx],{l[idx],idx} } ) ;
            cnt ++ ;
            if ( cnt > k ){
                auto it = --in.end() ;
                vec.pb(it->S.S) ;
                in.erase(--in.end()) ;
                cnt-- ;
            }
        }else{
            auto it = in.find( {r[idx],{l[idx],idx} } ) ;
            if ( it != in.end() ){
                in.erase( it ) ;
                cnt -- ;
            }
        }
    }
    
    cout  << vec.size() << "\n" ;
    sort ( vec.begin() , vec.end() ) ;
    for ( auto it : vec )
        cout << it+1 << ' ' ;cout << "\n" ;
}
