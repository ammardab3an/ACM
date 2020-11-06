
// Problem : H - Divisible Group Sums
// Contest : Virtual Judge - Week #4.2 [DP #1] Easy
// URL : https://vjudge.net/contest/399816#problem/H
// Memory Limit : 1024 MB
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

int n, d;
int arr[222];
int mem[222][22][11];

int go(int pos, int sm, int k){
	
	if(!k) return !sm;
	if(pos == n) return 0;
	
	int & ret = mem[pos][sm][k];
	if(ret != -1) return ret;
	
	int stPath = go(pos+1, sm, k);
	int ndPath = go(pos+1, (sm + arr[pos]%d + d)%d, k-1);
	
	return ret = stPath + ndPath;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
    int q;
	for(int t = 0; cin >> n >> q; t++){
		
		if(!n && !q) break;
		
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		cout << "SET " << t+1 << ":" << endl;
		
		int m;
		for(int i = 0; i < q; i++){
			cin >> d >> m;
			memset(mem, -1, sizeof mem);
			cout << "QUERY " << i+1 << ": " << go(0, 0, m) << endl;
		}	
	}
	
}
