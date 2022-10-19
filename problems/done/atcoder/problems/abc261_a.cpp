// Problem: A - Intersection
// Contest: AtCoder - AtCoder Beginner Contest 261
// URL: https://atcoder.jp/contests/abc261/tasks/abc261_a
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

	int l1, r1, l2, r2;
	while(cin >> l1 >> r1 >> l2 >> r2){

		int l = max(l1, l2);
		int r = min(r1, r2);

		int ans = max(int(0), r-l);

		cout << ans << endl;
	}
}
