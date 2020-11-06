
// Problem : 990 - Diving for Gold
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=931
// Memory Limit : 32 MB
// Time Limit : 3000 ms
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

const int MAX = 2e5 + 10;

int t, w, n;
pii arr[33];
int mem[33][1010];
vector<pii> ans;       
int go(int pos, int t){
	
	if(pos >= n) return 0;

	int & ret = mem[pos][t];
	if(~ret) return ret;	
	
	ret = go(pos+1, t);
	if(t >= 3 * w * arr[pos].first)
		ret = max(ret, go(pos+1, t - 3 * w * arr[pos].first) + arr[pos].second);
		
	return ret;	
}

void build(int pos, int t){
	
	if(pos >= n) return;
	
	if(go(pos, t) == go(pos+1, t)){
		build(pos+1, t);
	}
	else{
		ans.push_back(arr[pos]);
		build(pos+1, t - 3 * w * arr[pos].first);
	}
}
int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	bool f = false;
	while(cin >> t >> w >> n){
		
		if(f++) cout << endl;
		
		for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
		
		memset(mem, -1, sizeof mem);
		build(0, t);		

		cout << go(0, t) << endl << ans.size() << endl;;

		for(pii p : ans) cout << p.first << ' ' << p.second << endl;
	}

}
