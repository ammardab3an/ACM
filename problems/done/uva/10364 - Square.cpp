
// Problem : 10364 - Square
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1305
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

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

int n, po;
int arr[30];
int mem[4][1 << 20];

bool go(int k, int msk, int sm){

	if(k == 4) return 1;
	if(sm == po) return go(k+1, msk, 0);
	
	int & ret = mem[k][msk];
	if(~ret) return ret;
	
	for(int i = 0; i < n; i++) if(msk & (1 << i)) if(sm + arr[i] <= po){
		if(go(k, msk ^ (1 << i), sm + arr[i]))
			return ret = 1;
	}
	
	return ret = 0;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	
	int t; cin >> t; while(t--){
		
		cin >> n;
		
		int sm = 0;
		for(int i = 0; i < n; i++){
			cin >> arr[i]; 
			sm += arr[i];
		}
		
		if(sm % 4) {
			cout << "no" << endl;
		}
		
		else{
			po = sm/4;
			memset(mem, -1, sizeof mem);
			cout << (go(0, (1 << n) -1, 0) ? "yes" : "no") << endl;
		}
	}	
	
}
