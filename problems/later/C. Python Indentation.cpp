
// Problem : C. Python Indentation
// Contest : Codeforces - DP
// URL : https://codeforces.com/group/FqtJd4zMPb/contest/272904/problem/P
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

const int INF = 0x3f3f3f3f;
const int MAX = 5e3 + 10;
const int MOD = 1e9 + 7;

int n;
char arr[MAX];
int cnt[MAX];
int mem[MAX][MAX];

int go(int pos, int lvl){
	
	if(pos == n) return 1;
	
	int & ret = mem[pos][lvl];
	if(~ret) return ret;
	
	if(arr[pos-1] == 'f') return ret = go(pos+1, lvl+1);
	
	int ans = 0;
	
	for(int i = 0; i <= lvl; i++){
		ans += go(pos+1, i);
		if(ans >= MOD) ans -= MOD;
	}
		
	return ret = ans;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	cin >> n; 

	for(int i = 0; i < n; i++) cin >> arr[i];
	
	for(int i = 1; i < n; i++) cnt[i] = cnt[i-1] + (arr[i-1] == 'f');
	
	mem[0][0] = 1;
	
	for(int pos = 1; pos < n; pos++){
		
		for(int lvl = 0; lvl <= 5000; lvl++){
			
			if(arr[pos-1] == 'f'){
				for(int j = 0; j < pos; j++)
					mem[pos][j] = mem[pos-1][j];
//				mem[pos][lvl] = mem[pos-1][lvl-1];
			}
			else{
				for(int i = 0; i <= lvl; i++)
					mem[pos][lvl] += mem[pos-1][i];
			}
			
			cout << mem[pos][lvl] << ' ';
		}
		cout << endl;
	}
	
	int ans = 0;
	for(int i = 0; i <= 5000; i++) ans += mem[n-1][i];
	
	cout << ans << endl;
	
	
}
