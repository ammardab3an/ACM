// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

lli POW ( lli a , lli b , lli c , lli mod ){
    lli ret = a ;
    while ( c ){
        if ( c % 2 )
            ret = ( ret * b ) % mod ;
        b = ( b * b ) % mod ;
        c /= 2 ;
    }
    return ret ;
}

int main(){

	for(int T = 1;; T++){

        lli N, K, A, C;
        scanf("%I64d %I64d %I64d", &N, &K, &A);

        if(!N && !K && !A)
            break;

        scanf("%I64d", &C);
        vll P, ans;

        for(int i = 0; i < C; i++){
            lli x; scanf("%I64d", &x); P.push_back(x);
        }

        printf("Case %d:\n", T);

        for(int i = 0; i < C; i++){

            ans.push_back( POW( A , K , N , P[i] ) ) ;
        }

        for(int i = 0; i < C; i++)
            printf("%I64d%c", ans[i], " \n"[i == C-1]);
	}
}
