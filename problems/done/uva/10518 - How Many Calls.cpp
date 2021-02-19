// Problem: 10518 - How Many Calls?
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1459
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

lli n, b;

struct matrix{
	
	lli arr[2][2] = {0};
	
	matrix operator * (const matrix &other){
		
		matrix product;
		
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
		for(int k = 0; k < 2; k++) 
			(product.arr[i][k] += arr[i][j] * other.arr[j][k]) %= b;
			
		return product;
	}
};

matrix fast_power(matrix a, lli p){
	
	matrix product;
	for(int i = 0; i < 2; i++) product.arr[i][i] = 1;
	
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

	int t = 1;
    while(cin >> n >> b){
		
		if(!n && !b) break;
		
		matrix single;
		single.arr[0][0] = 0;
		single.arr[0][1] = 1;  	
		single.arr[1][0] = 1;  	
		single.arr[1][1] = 1;
		
		matrix total = fast_power(single, n+2);
		
		cout << "Case " << t++ << ": " << n << ' ' << b << ' ';
		cout << (2LL * total.arr[0][0] -1 + b) % b << endl;
    }
}
