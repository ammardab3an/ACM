// Problem: M. Ahmad Jaber Rectangles
// Contest: Codeforces - Training Contest
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309757/problem/M
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    
    int x0, x1, x2, x3, h;
    cin >> x0 >>x1 >> x2 >> x3 >> h;
    
    if(x1-x0 < x3-x2){
    	swap(x0, x2);
    	swap(x1, x3);
    }
    
    if(x1 <= x2 || x3 <= x0){
    	cout << 0;
    	return 0;
    }
    
    if(x0 <= x2 && x3 <= x1){
    	cout << h *(x3-x2) << endl;
    	return 0;
    }
    
    if(x3 > x1)
	    cout << h*(x1-x2) << endl;
    else
	    cout << h*(x3-x0) << endl;
}
