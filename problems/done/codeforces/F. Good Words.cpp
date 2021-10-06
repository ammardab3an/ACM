// Problem: F. Good Words
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/F
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

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

int n;
char str[1111];
char bb[5];
int mem[1111][5][2];

int go(int i, int j, bool b){

	if(j == 4) return !b + 1;
	if(i == n) return 0;
	
	int & ret = mem[i][j][b];
	if(~ret) return ret;
	
	int stPath, ndPath(0);
	
	if(str[i] == bb[j]) 
		ndPath = go(i+1, j+1, b);
	else if(!b)
		ndPath = go(i, j+1, 1);
	
	stPath = go(i+1, 0, 0);
	
	return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> str >> bb;
		n = strlen(str);
		
		memset(mem, -1, sizeof mem);
		int ans = go(0, 0, 0);
		
		switch(ans){

			case 0:
			cout << "none" << endl;
			break;

			case 1:
			cout << "almost good" << endl;
			break;

			case 2:
			cout << "good" << endl;
			break;
		}
		

    }	
}
