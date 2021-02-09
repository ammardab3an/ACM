// Problem: Q - Narrow Art Gallery
// Contest: Virtual Judge - Session 2 Sheet - [Euler,  Hamiltonian, Backtrack, greedy and Classical DP]
// URL: https://vjudge.net/contest/421856#problem/Q
// Memory Limit: 1048 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 222 + 10;
const int KMAX = 222 + 10;


int n, k;
int arr[2][NMAX];
int mem[NMAX][KMAX][2][2];

int go(int pos, int k, bool l, bool r){
	
	if(pos == n) return k ? -INF : 0;
	
	int & ret = mem[pos][k][l][r];
	if(~ret) return ret;
	
	int ans = go(pos+1, k, 0, 0) + arr[0][pos] + arr[1][pos];
	
	if(!l){
		ans = max(ans, go(pos+1, k-1, 0, 1) + arr[0][pos]);
	}
	if(!r){
		ans = max(ans, go(pos+1, k-1, 1, 0) + arr[1][pos]);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(cin >> n >> k, n){
    	
    	for(int i = 0; i < n; i++){
    		cin >> arr[0][i] >> arr[1][i];
    	}
    	
    	memset(mem, -1, sizeof mem);
    	
    	cout << go(0, k, 0, 0) << endl;
    }
}
