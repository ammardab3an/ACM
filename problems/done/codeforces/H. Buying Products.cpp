
// Problem : H. Buying Products
// Contest : Codeforces - ACM International Collegiate Programming Contest, Tishreen Collegiate Programming Contest (2017)
// URL : https://codeforces.com/gym/101915/problem/H
// Memory Limit : 64 MB
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

//#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int NMAX = 1e3 + 10;
const int KMAX = 2e3 + 10;

int n, k;
pii arr[NMAX];
int mem[NMAX][KMAX];

int go(int pos, int rem){
	
	if(!rem) return 0;
	if(pos == n) return INF;
	
	int & ret = mem[pos][rem];
	if(ret + 1) return ret;
	
	int stPath = go(pos+1, rem);
	int ndPath = go(pos+1, rem-1) + arr[pos].first;
	int rdPath = go(pos+1, rem-1) + arr[pos].second;
	int thPath = go(pos+1, rem-2) + arr[pos].first + arr[pos].second;
	
	return ret = min({stPath, ndPath, rdPath, thPath});
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int t; cin >> t; while(t--){
		
		cin >> n >> k;
		
		for(int i = 0; i < n; i++){
			vi vec(3);
			cin >> vec[0] >> vec[1] >> vec[2];
			sort(vec.begin(), vec.end());
			arr[i] = {vec[0], vec[1]};
		}
		
		memset(mem, -1, sizeof mem);
		cout << go(0, k) << endl;
	}
	
	
}
