// Problem: D - Flipping and Bonus
// Contest: AtCoder - AtCoder Beginner Contest 261
// URL: https://atcoder.jp/contests/abc261/tasks/abc261_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include<bits/stdc++.h>

#define int int64_t
#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int NMAX = 5000 + 10;

int n, m;
int arr[NMAX];
int bon[NMAX];
int mem[NMAX][NMAX];

int go(int i, int cnt){

	if(i==n){
		return bon[cnt];
	}

	int &ret = mem[i][cnt];
	if(ret+1) return ret;
	
	int st_path = go(i+1, cnt+1) + arr[i];
	int nd_path = go(i+1, 0);

	return ret = max(st_path, nd_path) + bon[cnt];

}

int32_t main(){

	fastIO;

	while(cin >> n >> m){

		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		for(int i = 0; i <= n; i++){
			bon[i] = 0;
		}

		for(int i = 0; i < m; i++){
			int ci;
			cin >> ci;
			cin >> bon[ci];
		}

		memset(mem, -1, sizeof mem);

		cout << go(0, 0) << endl;
	}
}
