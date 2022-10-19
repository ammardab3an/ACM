// Problem: C - NewFolder(1)
// Contest: AtCoder - AtCoder Beginner Contest 261
// URL: https://atcoder.jp/contests/abc261/tasks/abc261_c
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

typedef vector<int> vi;
typedef pair<int, int> pii;

int32_t main(){

	fastIO;

	int n;
	while(cin >> n){

		map<pii, int> mp;

		for(int i = 0; i < n; i++){

			string str;
			cin >> str;

			vi hs(2);

			vi p = {31, 37};
			vi m = {(int)1e9+7, (int)1e9+9};

			for(auto c : str){
				for(int j = 0; j < 2; j++){
					hs[j] = ((hs[j] * p[j])%m[j] + (c-'a'+1))%m[j];
				}
			}

			pii _hs = {hs[0], hs[1]};

			auto it = mp.find(_hs);

			if(it != mp.end()){
				cout << str << '(' << (it->second) << ')' << endl;
			}
			else{
				cout << str << endl;
			}

			mp[_hs]++;
		}
	}
}
