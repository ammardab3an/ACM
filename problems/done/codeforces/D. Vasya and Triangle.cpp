// Problem: D. Vasya and Triangle
// Contest: Codeforces - Technocup 2019 - Elimination Round 1
// URL: https://codeforces.com/problemset/problem/1030/D
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int n, m, k;
	cin >> n >> m >> k;
	
	// using integer coordinates, we can only genrade triangers with 
	// areas equal to (x * 0.5), se we need to check that the required 
	// area is a multiple of 0.5
	
	if((2*n*m)%k){
		cout << "NO" << endl;
		return 0;
	}
	
	/*
	
		area = mn/k = xy/2
		
		2mn/k = xy
		mn/(k/2) = x y; if k is even
		
		g = gcd(n, k)
		m (n/g)/(k/g) = x y
		m a/k' = x y
		m/k' a = x y
		b a = x y	
		
		a = n/g
		b = m/k'
		
		if(k%2){
			if(2a <= n) a *= 2;
			else b*= 2;
		}
	*/
	
	bool odd = k%2;
	if(!odd) k /= 2;
	
	int g = __gcd(n, k);
	int a = n/g;
	int kk = k/g;
	int b = m/kk;
	
	cout << "YES" << endl;
	
	if(odd){
		if(a*2 <= n) a*=2;
		else b*=2;
	}	
	
	cout << 0 << ' ' << 0 << endl;
	cout << a << ' ' << 0 << endl;
	cout << 0 << ' ' << b << endl;

}
