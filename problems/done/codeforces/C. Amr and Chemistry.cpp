// Problem: C. Amr and Chemistry
// Contest: Codeforces - Codeforces Round #312 (Div. 2)
// URL: https://codeforces.com/problemset/problem/558/C
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

const int NMAX = 1e5 + 10;

int n, mx;
int arr[NMAX];
int cnt[NMAX];
int ans[NMAX];
int vis[NMAX], vid;

void bfs(int num){
	
	vid++;
	vis[num] = vid;
	cnt[num] += 1;
	
	queue<pii> que;
	que.push({0, num});
	
	while(!que.empty()){
		
		pii fr = que.front(); que.pop();
		
		int cdis = fr.first;
		int cnum = fr.second;
		
		if(vis[cnum/2] != vid){
			
			vis[cnum/2] = vid;
			cnt[cnum/2] += 1;
			ans[cnum/2] += cdis+1;
			
			que.push({cdis+1, cnum/2});
		}
		
		if((cnum*2 <= mx) && (vis[cnum*2] != vid)){
			
			vis[cnum*2] = vid;
			cnt[cnum*2] += 1;
			ans[cnum*2] += cdis+1;
			
			que.push({cdis+1, cnum*2});
		}
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i], mx = max(mx, arr[i]);
	
	for(int i = 0; i < n; i++) bfs(arr[i]);
	
	int cans = INF;
	for(int i = 0; i <= mx; i++){
		if(cnt[i] == n){
			cans = min(cans, ans[i]);
		}
	}
	
	cout << cans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
