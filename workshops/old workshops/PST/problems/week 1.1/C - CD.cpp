
// Problem : C - CD
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/C
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

const int MAX = 2e5 + 10;

int main(){

    fastIO;
	
	int n, m;
	
	while(cin >> n >> m){
		
		vector<int> vec(m);
		
		for(int i = 0; i < m; i++) cin >> vec[i];
		
		int bestMsk(0), bestCnt(0), bestSum(0);
		
		for(int i = 0; i < (1 << m); i++){
			
			int curCnt(0), curSum(0);
			
			for(int j = 0; j < m; j++)
				if(i & (1 << j)) curCnt++, curSum += vec[j];

			if(curSum <= n){
				if(curSum > bestSum || (curSum == bestSum && curCnt > bestCnt)){
					bestMsk = i;
					bestCnt = curCnt;
					bestSum = curSum;
				}
			}
			
		}
		
		for(int i = 0; i < m; i++) 
			if(bestMsk & (1 << i)) cout << vec[i] << ' ';
			
		cout << "sum:" << bestSum << endl;
	}
	
}
