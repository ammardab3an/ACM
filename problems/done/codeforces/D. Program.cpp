// Problem: D. Program
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1473/problem/D
// Memory Limit: 256 MB
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

int tran(char c){
	return 1*(c == '+') -1*(c == '-');
}

struct node{
	int mn, mx;
	node() : mn(0), mx(0) {};
	node(int _mn, int _mx) : mn(_mn), mx(_mx){};
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		int n, m;
		cin >> n >> m;
		
		string str;
		cin >> str;
		
		vector<int> sm(n+2, 0);
		for(int i = 1; i <= n; i++) sm[i] = sm[i-1] + tran(str[i-1]);
		
		vector< node > pre(n+2, node()), suf(n+2, node());
		
		suf[n+1] = node(sm[n], sm[n]);
		
		for(int i = 1; i <= n; i++) pre[i] = node(min(pre[i-1].mn, sm[i]), max(pre[i-1].mx, sm[i]));
		for(int i = n; i >= 1; i--) suf[i] = node(min(suf[i+1].mn, sm[i]), max(suf[i+1].mx, sm[i]));
		
		// for(int i = 0; i <= n+1; i++) {for(auto j : {sm[i], pre[i].mn, pre[i].mx}) cout << j << ' ' ; cout << endl;};
		// cout << endl;
		// for(int i = 0; i <= n+1; i++) {for(auto j : {sm[i], suf[i].mn, suf[i].mx}) cout << j << ' ' ; cout << endl;};

		while(m--){
			
			int l, r;
			cin >> l >> r;
			
			int mn0 = pre[l-1].mn;
			int mx0 = pre[l-1].mx;
			int mn1 = suf[r+1].mn - (sm[r] - sm[l-1]);
			int mx1 = suf[r+1].mx - (sm[r] - sm[l-1]);
			
			cout << max(mx0, mx1)-min(mn0, mn1)+1 << endl;
		}
    }	
}
