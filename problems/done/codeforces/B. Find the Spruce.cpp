// Problem: B. Find the Spruce
// Contest: Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL: http://codeforces.com/contest/1461/problem/B
// Memory Limit: 256 MB
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

int n, m;
char grid[555][555];
int sm[555][555];


bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> grid[i];
		
		memset(sm, 0, sizeof sm);
		
		for(int i = 0; i < n; i++){
			
			sm[i][0] = grid[i][0] == '*';
			for(int j = 1; j < m; j++){
				sm[i][j] = sm[i][j-1] + (grid[i][j] == '*');
			}
		}
		
		
		int ans = 0;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) if(grid[i][j] == '*'){
			
			
			for(int k = 0; ;k++){

				
				if(in(i+k, j-k) && in(i+k, j+k)){
					
					int csm = sm[i+k][j+k];
					
					if(j-k) csm -= sm[i+k][j-k-1];
					
					if(csm != 2*k+1){
						break;
					}
				}
				else{
					break;
				}
								
				ans++;
			}
		}

		cout << ans << endl;
    }	
}
