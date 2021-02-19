// Problem: E. Knight Paths
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/E
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

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int A = 65;

bool inside(int i, int j){
	int n = 8;
	return 0 <= i && i < n && 0 <= j && j < n; j++;
}

struct matrix{
	
	vector<vector<uint>> arr = vector<vector<uint>>(A, vector<uint>(A));
	
	matrix operator * (const matrix &other){
		
		matrix product;
		
		for(int i = 0; i < A; i++)
		for(int j = 0; j < A; j++)
		for(int k = 0; k < A; k++)
			product.arr[i][k] += arr[i][j] * other.arr[j][k];
			
		return product;
	}
};

matrix fast_power(matrix a, lli p){
	
	matrix product;
	for(int i = 0; i < A; i++) product.arr[i][i] = 1;
	
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

    
    int k;
	cin >> k;
	
	matrix single;
	
	for(int i = 0; i < 8; i++)
	for(int j = 0; j < 8; j++){
		
		for(int ni : {1, -1, 2, -2})
		for(int nj : {1, -1, 2, -2}) 
			if(abs(ni) != abs(nj)) if(inside(i+ni, j+nj)){
				single.arr[8*i + j][8*(i+ni) + (j+nj)] = 1;
		}
	}
	
	for(int i = 0; i < A; i++) single.arr[i][64] = 1;
	
	matrix total = fast_power(single, ++k);
	
	cout << total.arr[0][64] << endl;
}
