// Problem: E - Many Operations
// Contest: AtCoder - AtCoder Beginner Contest 261
// URL: https://atcoder.jp/contests/abc261/tasks/abc261_e
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

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int32_t main(){

	fastIO;

	int n, c;
	while(cin >> n >> c){

		vpii tmp(n);
		for(auto &p : tmp) cin >> p.first >> p.second;

		vector<vector<vector<bool>>> vec(n+1, vector<vector<bool>>(31, vector<bool>(2)));

		for(int i = 0; i < 31; i++) vec[0][i][1] = 1;

		for(int i = 1; i <= n; i++){

			int k = tmp[i-1].first;
			int x = tmp[i-1].second;

			if(k==1){
				for(int j = 0; j < 31; j++){
					vec[i][j][0] = vec[i-1][j][0] & ((x>>j)&1);
					vec[i][j][1] = vec[i-1][j][1] & ((x>>j)&1);
				}
			}
			else if(k==2){
				for(int j = 0; j < 31; j++){
					vec[i][j][0] = vec[i-1][j][0] | ((x>>j)&1);
					vec[i][j][1] = vec[i-1][j][1] | ((x>>j)&1);
				}
			}
			else{
				for(int j = 0; j < 31; j++){
					vec[i][j][0] = vec[i-1][j][0] ^ ((x>>j)&1);
					vec[i][j][1] = vec[i-1][j][1] ^ ((x>>j)&1);
				}
			}
		}


		for(int i = 1; i <= n; i++){

			int nc = 0;

			for(int j = 0; j < 31; j++){
				bool b = (c>>j)&1;
				b = vec[i][j][b];
				if(b) nc |= 1ll << j;
			}

			c = nc;

			cout << c << endl;
		}
	}
}
