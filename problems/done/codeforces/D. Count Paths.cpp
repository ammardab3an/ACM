// Problem: D. Count Paths
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

lli n, m, k;
vi adj[NMAX];

struct matrix{
	
	lli arr[110][110] = {0};
	
	matrix operator * (const matrix &other){
		
		matrix product;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		for(int k = 0; k < n; k++)
			(product.arr[i][k] += arr[i][j] * other.arr[j][k]) %= MOD;
			
		return product;
	}
};

matrix fast_power(matrix a, lli p){
	
	matrix product;
	for(int i = 0; i < n; i++) product.arr[i][i] = 1;
	
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
    
    matrix signal;
    
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	signal.arr[u-1][v-1] = 1;
    }
    
    matrix total = fast_power(signal, k);
    
    lli ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) (ans += total.arr[i][j]) %= MOD;
    
    cout << ans << endl;
}
