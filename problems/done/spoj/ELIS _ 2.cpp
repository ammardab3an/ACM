
// Problem : Easy Longest Increasing Subsequence
// Contest : SPOJ - Tutorial
// URL : https://www.spoj.com/problems/ELIS/
// Memory Limit : 1536 MB
// Time Limit : 1948 ms
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

const int MAX = 20 + 10;

int n;
int arr[MAX];
int mem[MAX][MAX];
int lis[MAX];

int go(int pos, int lst){
	if(pos == n+1) return 0;
	
	int & ret = mem[pos][lst];
	if(~ret) return ret;
	
	ret = go(pos+1, lst);
	if(arr[lst] < arr[pos]) ret = max(ret, go(pos+1, pos) + 1);
	
	return ret;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	
	fill(lis, lis+n+1, 1);
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(arr[j] < arr[i]) lis[i] = max(lis[i], lis[j]+1);
		}
	}
	
	for(int i = 1; i <= n; i++) cout << lis[i] << ' '; cout << endl;
	cout << *max_element(lis, lis+n+1) << endl;
	
	
	for(int i = n; i >= 1; i--){
		
		for(int j = 0; j <= n; j++){

			mem[i][j] = mem[i+1][j];
			if(arr[j] < arr[i]) mem[i][j] = max(mem[i][j], mem[i+1][i] + 1);
		}
	}
	
	cout << mem[1][0] << endl;
	
	memset(mem, -1, sizeof mem);
	cout << go(1, 0);	
}
