// Problem: D. Radio Towers
// Contest: Codeforces - Educational Codeforces Round 98 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1452/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int mem[NMAX];
int feb[NMAX];

int go(int pos){
	
	if(pos == n+1) return 1;
	
	int & ret = mem[pos];
	if(~ret) return ret;
	
	int ans = 0;
	
	for(int i = 1; pos+i <= n+1; i+=2){
		ans += go(pos+i);
		if(ans >= MOD) ans -= MOD;
	}
	
	return ret = ans;
}

int get_feb(int n){
	feb[1] = feb[2] = 1;
	for(int i = 3; i <= n; i++) 
		feb[i] = (feb[i-1] + feb[i-2])%MOD;
	return feb[n];
}

int fast_pow(int n, int p){
	if(!p) 
		return 1;
	if(p&1)
		return (n * fast_pow(n, p-1)) % MOD;
	else{
		int tmp = fast_pow(n, p/2);
		return (tmp * tmp) % MOD;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
	
    cin >> n;
    
    //memset(mem, -1, sizeof mem);
    //int ans = go(1);

    int ans = get_feb(n);
    int tmp = fast_pow(2, n);
    
    cout << (ans * fast_pow(tmp, MOD-2)) % MOD << endl;
}
