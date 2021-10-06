// Problem: G. Cutie Pie
// Contest: Codeforces - Training Contest 3
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/310125/problem/G
// Memory Limit: 64 MB
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
char grid[33][33];
bool vist[33][33];
pii mvArr[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

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
		for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) cin >> grid[i][j];
		
		bool b = false;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			
			for(pii p : mvArr){
	
				string str = ""; str += grid[i][j];
				
				int ii = i;
				int jj = j;
					
				for(int k = 0; k < 2; k++){
					ii += p.first;
					jj += p.second;	
					if(!in(ii, jj)) break;
					str.push_back(grid[ii][jj]);
				}

				//cout << str << endl;

				if(str == "pie"){
					b = true;
					break;
				}
				
			}
		}
		
		cout << (b ? "Cutie Pie!" : "Sorry Man") << endl;
    }	
}
