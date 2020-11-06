// K. Poor Ramzi
// https://codeforces.com/gym/101915/problem/K


#include <bits/stdc++.h>
#define    ll    long long
#define    ld    long double
#define    pb    push_back
#define    F     first
#define    S     second

using namespace std ;
const ll MAX = 1e3 + 10 , OO = 1e9 +10 , MOD = 1e9 + 7;
const ld pi = acos(-1) ;

string s;
ll mem[MAX][MAX] , pre[MAX] ;

ll solve(int l , int r)
{

	ll &ret = mem[l][r] ;
	if(~ret) return ret;
	
	ret = 1 ;

	int pre1 , pre2 ;

	for ( int i = l ; i < r ; i ++ )
	{
		pre1 = pre[i] - pre[l-1] ;
		
		for ( int j = r ; j > i ; j-- )
        {
            pre2 = pre[r] - pre[j-1] ;
            
			if( pre1 == pre2 ){
	
				ret += solve(i+1, j-1);
				if(ret >= MOD) ret -= MOD;
			}
		}
	}
	
	return ret ;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int t;	cin >> t; while( t-- )
    {
		
		cin >> s ;
		int n = s.size() ;
		
		for ( int i = 1 ; i <= n ; i ++ )
            pre[i] = pre[i-1] + (s[i-1]-'0') ;
		
		memset ( mem , -1 , sizeof mem ) ;
		cout << ( solve( 1 , n ) ) << '\n' ;
	}
}