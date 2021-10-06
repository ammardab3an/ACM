// Problem: A. Crazy Town
// Contest: Codeforces - Codeforces Round #284 (Div. 1)
// URL: https://codeforces.com/problemset/problem/498/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

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

struct line{
	
	int a, b, c;
	
	line(){}
	line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
	
	double calc(int x, int y){
		return double(a*x + b*y + c);
	}
};

int sgn(double i){
	return (double(0) <= i) - (double(0) >= i);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif	
	
	int x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	
	int n;
	cin >> n;
	
	vector<line> lines(n);
	for(auto &ln : lines) cin >> ln.a >> ln.b >> ln.c;
	
	int cnt = 0;
	
	for(auto ln : lines) cnt += sgn(ln.calc(x0, y0)) != sgn(ln.calc(x1, y1));
	
	cout << cnt << endl;
}
