
// Problem : B. Modulo Sum
// Contest : Codeforces - DP
// URL : https://codeforces.com/group/FqtJd4zMPb/contest/272904/problem/M
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MAX = 1e6 + 10;

int n, k;
int arr[MAX];
int mem[1010][1010][2];

bool go(int pos, int sm, bool b){
	
	if(pos == n) return !sm && !b;
	
	int & ret = mem[pos][sm][b];
	if(~ret) return ret;
	
	bool stPath = go(pos+1, sm, b);
	bool ndPath = go(pos+1, (sm + arr[pos]) % k, 0);
	
	return ret = stPath || ndPath;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	
	cin >> n >> k;
	
	if(n > k){
		cout << "YES" << endl;
	}
	else{
		for(int i = 0; i < n; i++) cin >> arr[i];
		memset(mem, -1, sizeof mem);
		cout << (go(0, 0, 1) ? "YES" : "NO") << endl;
	}
	
}
