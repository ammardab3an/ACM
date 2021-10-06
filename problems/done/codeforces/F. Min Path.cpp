// Problem: F. Min Path
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/F
// Memory Limit: 256 MB
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

//const int INF = 0x3f3f3f3f;
const lli INF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

lli n, m, k;

struct matrix{
	
	vector<vector<lli>> arr = vector<vector<lli>>(n, vector<lli>(n, INF));
	
	matrix operator * (const matrix &other){
		
		matrix product;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		for(int k = 0; k < n; k++) 
			product.arr[i][k] = min(product.arr[i][k], arr[i][j] + other.arr[j][k]);
			
		return product;
	}
};

matrix fast_power(matrix a, lli p){
	
	matrix product;
	for(int i = 0; i < n; i++) product.arr[i][i] = 0;
	
	while(p){
		if(p&1) product = product * a;
		a = a*a;
		p /= 2;
	}
	
	return product;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m >> k;
    
    matrix single;
    
    for(int i = 0; i < m; i++){
    	lli u, v, c;
    	cin >> u >> v >> c;
    	single.arr[u-1][v-1] = c;
    }
    
    matrix total = fast_power(single, k);
    
    lli ans = INF;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) ans = min(ans, total.arr[i][j]);
    
    if(ans >= INF/2){
    	cout << "IMPOSSIBLE" << endl;
    }
    else{	
	    cout << ans << endl;
    }
}
