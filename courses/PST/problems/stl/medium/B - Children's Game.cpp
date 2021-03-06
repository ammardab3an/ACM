
// Problem : B - Children's Game
// Contest : Virtual Judge - Week #1[STLs - Medium]
// URL : https://vjudge.net/contest/394527#problem/B
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

	int n;
	string str;
	
	while(cin >> n){
		
		if(!n) break;
		
		vector<string> vec(n);
		
		for(int i = 0; i < n; i++) cin >> vec[i];

		
		auto str_comp = [] (string str1, string str2) {
			
			return str1 + str2 > str2 + str1;
			
		};
		
		sort(vec.begin(), vec.end(), str_comp);
		
		for(string str : vec)
			cout << str;
		
		cout << endl;
	}
	
}
