
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

lli A;

struct matrix{

	vector<vl> arr = vector<vl>(A, vl(A));

	matrix operator * (const matrix &other){
		matrix product;
		for(int i = 0; i < A; i++)
		for(int j = 0; j < A; j++)
		for(int k = 0; k < A; k++)
			(product.arr[i][k] += arr[i][j] * other.arr[j][k]) %= (lli)1e9;
		return product;
	}
};

matrix fast_power(matrix a, lli p){

	matrix product;
	for(int i = 0; i < A; i++) product.arr[i][i] = 1;

	while(p){
		if(p&1) product = product * a;
		a = a * a;
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

    int t; cin >> t; while(t--){

		lli n, k;
		cin >> k; A = k;

		matrix single, initial;

		for(int i = 0; i < k; i++){
			cin >> initial.arr[i][0];
		}

		for(int i = 0; i < k-1; i++){
			single.arr[i][i+1] = 1;
		}

		for(int i = k-1; i >= 0; i--){
			cin >> single.arr[k-1][i];
		}

		cin >> n;

		matrix total = fast_power(single, n-1) * initial;

		cout << total.arr[0][0] << endl;
    }	
}
