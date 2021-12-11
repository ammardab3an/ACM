// Problem: Marbles
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/MARBLES
// Memory Limit: 256 MB
// Time Limit: 440 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using namespace std;

#define int uint64_t

const int NMAX = 1e6 + 10;

int choose(int n, int r){
	
	r = min(r, n-r);
	
	int a = 1;
	
	for(int i = 0; i < r; i++){
		a *= n-i;
		a /= i+1;
	}
	
	return a;
}

int32_t main(){
	
		
	int t; cin >> t; while(t--){
		
		int n, k;
		cin >> n >> k;
		
		cout << choose(n-1, k-1) << endl;
	}
}