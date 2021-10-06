// Problem: E. Pattern Matching
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define lli int64_t

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

int n, m, k;
char pat[NMAX][5];
char str[NMAX][5];
int arr[NMAX];
vi adj[NMAX];
int vist[NMAX];
bool valid = true;
vi ans;

bool match(char *str, char*pat){
	for(int i = 0; i < k; i++) {
		if(pat[i] != '_') 
			if(str[i] != pat[i]) return false;
	}
	return true;
}

void dfs(int nd){
	
	if(!valid || vist[nd] == 2) return;
	
	if(vist[nd] == 1){
		valid = 0;
		return;
	}
	
	vist[nd] = 1;
	
	for(auto nxt : adj[nd]) dfs(nxt);
	
	vist[nd] = 2;
	
	ans.push_back(nd);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++) cin >> pat[i];
	for(int i = 0; i < m; i++) cin >> str[i] >> arr[i];
	
	for(int i = 0; i < m; i++) if(!match(str[i], pat[arr[i]-1])){
		cout << "NO" << endl;
		return 0;
	}
	
	unordered_map<string, int> mp;
	
	for(int i = 0; i < n; i++){
		mp[string(pat[i], pat[i]+k)] = i;
	}
	
	for(int i = 0; i < m; i++){
		
		for(int msk = 0; msk < (1 << k); msk++){
			
			string tmp;
			for(int j = 0; j < k; j++){
				tmp.push_back(msk & (1 << j) ? '_' : str[i][j]);
			}
			
			if(mp.find(tmp) != mp.end()){
				int u = arr[i]-1;
				int v = mp[tmp];
				if(u != v) adj[u].push_back(v);
			}
		}
	}
	
	for(int i = 0; i < n; i++) if(!vist[i]) dfs(i);
	
	if(valid){
		cout << "YES" << endl;
		reverse(ans.begin(), ans.end());
		for(auto i : ans) cout << i+1 << ' '; cout << endl;
	}
	else{
		cout << "NO" << endl;
	}

}
