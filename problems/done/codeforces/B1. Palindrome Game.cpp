// Problem: B1. Palindrome Game
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/B1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
char str[1010];
int mem[1010][1010][2][2];
int vis[1010][1010][2][2], vid;

int go(int cnt_l, int cnt_r, int cnt_m, int b){
	
	if(!cnt_l && !cnt_r && !cnt_m) return 0;
	
	if(vis[cnt_l][cnt_r][cnt_m][b] == vid) 
		return mem[cnt_l][cnt_r][cnt_m][b];
	vis[cnt_l][cnt_r][cnt_m][b] = vid;
	
	int ans, stPath, ndPath, rdPath;
	ans = stPath = ndPath = rdPath = INF;
	
	if(b && (cnt_l != cnt_r)) ans = -go(cnt_r, cnt_l, cnt_m, 0);
	
	if(cnt_l) stPath = 1 - go(cnt_l-1, cnt_r, cnt_m, 1);
	if(cnt_r) ndPath = 1 - go(cnt_l, cnt_r-1, cnt_m, 1);
	if(cnt_m) rdPath = 1 - go(cnt_l, cnt_r, cnt_m-1, 1);
	
	return mem[cnt_l][cnt_r][cnt_m][b] = min({ans, stPath, ndPath, rdPath});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    vid++;
    
    int t; cin >> t; while(t--){

		cin >> n >> str;
				
		int cnt_l = 0, cnt_r = 0, cnt_m = 0;
		
		for(int i = 0; i < n/2; i++){
			cnt_l += str[i] == '0';
		}
		
		for(int i = (n+1)/2; i < n; i++){
			cnt_r += str[i] == '0';
		}
		
		if(n%2==1) cnt_m = str[n/2] == '0';
		
		int ans = go(cnt_l, cnt_r, cnt_m, 1);
		
		if(ans == 0){
			cout << "DRAW" << endl;
		}
		else if(ans > 0){
			cout << "BOB" << endl;
		}
		else{
			cout << "ALICE" << endl;
		}
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
