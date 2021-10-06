// Problem: D. Journey
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/D
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 3e5 + 10;

int n;
char tmp[NMAX];
int adj[NMAX];
int mem[NMAX][2][2];

int go(int pos, int dir, int mod){
	
	if(dir && pos == n-1) return 0;
	if(!dir && pos == 0) return 0;
	
	int & ret = mem[pos][dir][mod];
	if(~ret) return ret;
	
	int ans = 0;
	
	if(dir){
		if(adj[pos] ^ mod == dir) 
			ans = go(pos+1, dir, !mod) +1;
	}
	else{
		if(adj[pos-1] ^ mod == dir)
			ans = go(pos-1, dir, !mod) +1;
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		cin >> n;
		cin >> tmp;
		
		for(int i = 0; i < n; i++) adj[i] = tmp[i] == 'R';
		
		n++;
		
		memset(mem, -1, sizeof mem);
		
		for(int i = 0; i < n; i++){
			cout << go(i, 0, 0) + go(i, 1, 0) +1 << ' ';
		}
		
		cout << endl;
    }	
}
