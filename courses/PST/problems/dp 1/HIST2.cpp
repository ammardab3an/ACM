
// Problem : Histogram
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/HIST2/
// Memory Limit : 1536 MB
// Time Limit : 1000 ms
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

const int MAX = 15;

int n;
int arr[MAX];
int mem[111][1 << MAX];
lli memo[111][1 << MAX];

int go(int lst, int msk){
	
	if(!msk) return lst + n;
	
	int & ret = mem[lst][msk];
	if(~ret) return ret;
	
	int mx = 0;
	
	for(int i = 0; i < n; i++) if(msk & (1 << i)){
		
		int tmp = go(arr[i], msk ^ (1 << i)) + abs(lst - arr[i]) + 1;
		mx = max(mx, tmp);
	}
	
	return ret = mx;
}

lli ways(int lst, int msk){
	
	if(!msk) return 1;
	
	lli & ret = memo[lst][msk];
	if(~ret) return ret;
	
	int ans = go(lst, msk);
	
	lli cnt = 0;
	
	for(int i = 0; i < n; i++) if(msk & (1 << i)){
		
		int tmp = go(arr[i], msk ^ (1 << i)) + abs(lst - arr[i]) +1;
		if(tmp == ans) cnt += ways(arr[i] , msk ^ (1 << i));
	}
	
	return ret = cnt;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	while(cin >> n){
		if(!n) break;
		for(int i = 0; i < n; i++) cin >> arr[i];
		memset(mem, -1, sizeof mem);
		memset(memo, -1, sizeof memo);
		cout << go(0, (1 << n) -1) << ' ' << ways(0, (1 << n) -1) << endl;
	}
	
	
}
