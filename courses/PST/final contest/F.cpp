// Problem: F - 6
// Contest: Virtual Judge - Level 3 - Graduation Contest
// URL: https://vjudge.net/contest/414878#problem/F
// Memory Limit: 262 MB
// Time Limit: 1000 ms
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
int arr[NMAX];
int mem[NMAX][3];

int go(int pos, int pst){
	
	if(pos == n) return 0;
	
	int & ret = mem[pos][pst];
	if(~ret) return ret;
	
	int stPath = go(pos+1, 0) +1;

	if(arr[pos] == 0) 
		return ret = stPath;
	
	else if(arr[pos] == 1){
		if(pst != 1) stPath = go(pos+1, 1);
	}
	
	else if(arr[pos] == 2){
		if(pst != 2) stPath = go(pos+1, 2);
	}
	
	else{
		if(pst == 0){
			stPath = min(go(pos+1, 1), go(pos+1, 2));
		}
		else if(pst == 1){
			stPath = go(pos+1, 2);
		}
		else{
			stPath = go(pos+1, 1);
		}
	}
	
	return ret = stPath;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	{

		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		memset(mem, -1, sizeof mem);
		
		cout << go(0, 0) << endl;
    }	
}
