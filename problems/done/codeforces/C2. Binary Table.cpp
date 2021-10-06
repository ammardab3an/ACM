// Problem: C2. Binary Table (Hard Version)
// Contest: Codeforces - Codeforces Round #684 (Div. 2)
// URL: http://codeforces.com/contest/1440/problem/C2
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
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
bool grid[110][110];

int mem[2][2][2][2][5];

vector< array<int, 2> > go_ret;

int dp(int a0, int a1, int a2, int a3, int cnt){

	if(cnt == 5) return 10;

    if(!a0 && !a1 && !a2 && !a3) return 0;	
	
    int & ret = mem[a0][a1][a2][a3][cnt];
    if(ret != -1) return ret;

	cnt++;
    int stPath = dp(!a0, !a1, !a2, a3, cnt);
    int ndPath = dp(a0, !a1, !a2, !a3, cnt);
    int rdPath = dp(!a0, a1, !a2, !a3, cnt);
    int thPath = dp(!a0, !a1, a2, !a3, cnt);
    
    return ret = min({stPath, ndPath, rdPath, thPath}) + 1;
}

void go(int a0, int a1, int a2, int a3, int cnt){
	
    if(!a0 && !a1 && !a2 && !a3) return;

    int ans = dp(a0, a1, a2, a3, cnt);
	
	cnt++;
    int stPath = dp(!a0, !a1, !a2, a3, cnt);
    int ndPath = dp(a0, !a1, !a2, !a3, cnt);
    int rdPath = dp(!a0, a1, !a2, !a3, cnt);
    int thPath = dp(!a0, !a1, a2, !a3, cnt);

	ans--;
    if(ans == stPath){
        go_ret.push_back({0, 0});
        go_ret.push_back({0, 1});
        go_ret.push_back({1, 1});
        go(!a0, !a1, !a2, a3, cnt);
    }

    else if(ans == ndPath){
        go_ret.push_back({1, 0});
        go_ret.push_back({0, 1});
        go_ret.push_back({1, 1});
        go(a0, !a1, !a2, !a3, cnt);
    }

    else if(ans == rdPath){
        go_ret.push_back({0, 0});
        go_ret.push_back({1, 0});
        go_ret.push_back({1, 1});
        go(!a0, a1, !a2, !a3, cnt);
    }

    else if(ans == thPath){
        go_ret.push_back({0, 0});
        go_ret.push_back({0, 1});
        go_ret.push_back({1, 0});
        go(!a0, !a1, a2, !a3, cnt);
    }

}



int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
	
	memset(mem, -1, sizeof mem);
	
    int t; cin >> t; while(t--){
		
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			string str; cin >> str;
			for(int j = 0; j < m; j++) grid[i][j] = str[j] == '1';
		}
		
		vector< array<int, 6> > ans;
		
		for(int i = 0; i < n-2; i++)
		for(int j = 0; j < m; j++) if(grid[i][j]){
			
			if(j != m-1){
				ans.push_back({i, j, i+1, j, i+1, j+1});
				grid[i+1][j] ^= 1;
				grid[i+1][j+1] ^= 1;
			}
			else{
				ans.push_back({i, j, i+1, j, i+1, j-1});
				grid[i+1][j] ^= 1;
				grid[i+1][j-1] ^= 1;
			}
		}
		
		for(int j = 0; j < m-2; j++){
			if(grid[n-2][j]) {
				ans.push_back({n-2, j, n-2, j+1, n-1, j+1});
				grid[n-2][j+1] ^= 1;
				grid[n-1][j+1] ^= 1;
			}
			
			if(grid[n-1][j]) {
				ans.push_back({n-1, j, n-2, j+1, n-1, j+1});
				grid[n-2][j+1] ^= 1;
				grid[n-1][j+1] ^= 1;
			}
		}

		if(true){
			int i = n-2;
			int j = m-2;
			
			int a0 = grid[i][j];
	        int a1 = grid[i][j+1];
	        int a2 = grid[i+1][j+1];
	        int a3 = grid[i+1][j];
	
	        go_ret.clear();
	        go(a0, a1, a2, a3, 0);
			
			array<int, 6> tmp;
			
			int tmp_i = 0;
	        for(auto a : go_ret){
				tmp[tmp_i++] = a[0]+i;
				tmp[tmp_i++] = a[1]+j;
				if(tmp_i == 6){
					ans.push_back(tmp);
					tmp_i = 0;
				}
	        }
		}


		cout << ans.size() << endl;
		for(auto a : ans){
			for(auto i : a)
				cout << i+1 << ' ';
			cout << endl;
		}
    }
}
