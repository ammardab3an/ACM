// Problem: C. Searching Local Minimum
// Contest: Codeforces - Codeforces Round #700 (Div. 2)
// URL: https://codeforces.com/contest/1480/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

//#define endl '\n'
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

int32_t main(){

    int n;
    cin >> n;
	
	if(n == 1){
		cout << "! 1" << endl;
		cout.flush();
		return 0;
	}
	
    vi vec(n, -1);

    cout << "? 1" << endl;
    cout << "? 2" << endl;
    cin >> vec[0];
    cin >> vec[1];

	if(vec[0] < vec[1]){
		cout << "! " << 1 << endl;
		cout.flush();
		return 0;
	}

    cout << "? " << n-1 << endl;
    cout << "? " << n << endl;
    cin >> vec[n-2];
    cin >> vec[n-1];

    if(vec[n-2] > vec[n-1]){
    	cout << "! " << n << endl;
    	cout.flush();
    	return 0;
    }

    int l = 1;
    int r = n-2;

    while(l <= r){


    	int m = (l+r)/2;

    	for(int i = -1; i <= +1; i++){
    		cout << "? " << m+i+1 << endl;
    		cin >> vec[m+i];
    	}

    	if(vec[m-1] > vec[m] && vec[m] < vec[m+1]){
    		cout << "! " << m+1 << endl;
    		cout.flush();
    		return 0;
    	}

    	if(vec[m-1] > vec[m]){
    		l = m+1;
    	}
    	else{
    		r = m-1;
    	}
    }


}
