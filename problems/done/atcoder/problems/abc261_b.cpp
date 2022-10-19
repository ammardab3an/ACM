// Problem: B - Tournament Result
// Contest: AtCoder - AtCoder Beginner Contest 261
// URL: https://atcoder.jp/contests/abc261/tasks/abc261_b
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

int32_t main(){

	fastIO;

	int n;
	while(cin >> n){

		vector<string> grid(n);
		for(auto &s : grid) cin >> s;

		bool ans = true;

		for(int i = 0; i < n && ans; i++)
		for(int j = 0; j < i; j++) {
			if(grid[i][j]=='-'){
				continue;
			}
			else if(grid[i][j]=='W'){
				if(grid[j][i] != 'L'){
					ans = false;
					break;
				}	
			}
			else if(grid[i][j]=='L'){
				if(grid[j][i] != 'W'){
					ans = false;
					break;
				}
			}
			else if(grid[i][j] != grid[j][i]){
				ans = false;
				break;
			}
		}

		cout << (ans ? "correct" : "incorrect") << endl;
	}
}
