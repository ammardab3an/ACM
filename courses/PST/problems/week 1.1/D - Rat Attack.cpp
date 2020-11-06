
// Problem : D - Rat Attack
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/D
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef long long int       lli;
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

const int MAX = 1024 + 10;

int n = 1024;
int arr[MAX][MAX];

int valid(int i, int j){
	return 0 <= i && i < n &&
		   0 <= j && j < n;
}

int main(){

    fastIO;
	
	int T; cin >> T; while(T--){
		
		memset(arr, 0, sizeof arr);
		
		int d, cnt;		
		cin >> d >> cnt;
		
		while(cnt--){
			int i, j, sz;	
			cin >> i >> j >> sz;
			arr[i][j] = sz;
		}	
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i) arr[i][j] += arr[i-1][j];
				if(j) arr[i][j] += arr[i][j-1];
				if(i && j) arr[i][j] -= arr[i-1][j-1];
			}
		}
		
		int mxI, mxJ, mxSz = -1;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				
				int li, lj, ri, rj;
				
				for(int k = d; k >= 0; k--){
					if(valid(i-k, j-k)){
						li = i-k;
						lj = j-k;
						break;
					}
				}

				for(int k = d; k >= 0; k--){
					if(valid(i+k, j+k)){
						ri = i+k;
						rj = j+k;
						break;
					}
				}

				int curSz = arr[ri][rj];
				if(li) curSz -= arr[li-1][rj];
				if(lj) curSz -= arr[ri][lj-1];
				if(li && lj) curSz += arr[li-1][lj-1];
				
				if(curSz > mxSz){
					mxI = i;
					mxJ = j;
					mxSz = curSz;
				}
				
			}
		}
		

		
		cout << mxI << ' ' << mxJ << ' ' << mxSz << endl;
	
	}
	
}
