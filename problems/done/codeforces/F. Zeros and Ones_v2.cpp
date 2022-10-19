// Problem: F. Zeros and Ones
// Contest: Codeforces - Codeforces Round #822 (Div. 2)
// URL: https://codeforces.com/contest/1734/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
#define int int64_t

ll n, m;
ll dp[70][2][2][2][2];

ll solve(int i, ll x){

	if(x > m){
		return 0;
	}
	
    if(i == -1){
    	return (__builtin_popcountll(x)+__builtin_popcountll(x+n))%2;
    }

    ll y = x + (n^(n&((1ll<<(i+1))-1)));
    int f = __builtin_popcountll(x);
    int s = __builtin_popcountll(y);
	
	int xx = 0;
	for(int j = i+1; j < 62; j++){
		if(!(((x+n)>>j)&1)) break;
		xx++;
	}

	bool under = x < (m^(m&((1ll<<(i+1))-1)));
	
	int &ret = dp[i][f%2][s%2][xx%2][under];
	if(ret+1) return ret;
	
    ll s1 = solve(i-1, x);
    ll f1 = solve(i-1, x^(1LL<<i));

    return ret = f1 + s1;
}

main(){

    int t;
    cin >> t;
    while(t--){
        
        cin >> n >> m;
        m--;
        
        memset(dp, -1, sizeof dp);
        cout << solve(61, 0) << endl;
    }

    return 0;

}
