
// Problem : K. By Elevator or Stairs?
// Contest : Codeforces - DP
// URL : https://codeforces.com/group/FqtJd4zMPb/contest/272904/problem/K
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef unsigned int		uint;
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

const int MAX = 2e5 + 10;

int n, c;
int a[MAX];
int b[MAX];
int mem[MAX][2];

int go(int pos, bool ele){

	if(pos == 0) return 0;

	int & ret = mem[pos][ele];
	if(ret != -1) return ret;

	int mn = INT_MAX;

	mn = min(mn, go(pos-1, 0) + a[pos]);
	mn = min(mn, go(pos-1, 1) + b[pos] + !ele*c);

	return ret = mn;
}

int main(){

    fastIO;
	cin >> n >> c;
	memset(mem, -1, sizeof mem);
	for(int i = 1; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cout << go(i, 0) << ' ';
}
