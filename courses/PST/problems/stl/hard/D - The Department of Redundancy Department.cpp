
// Problem : D - The Department of Redundancy Department
// Contest : Virtual Judge - Week #1[STLs - Hard]
// URL : https://vjudge.net/contest/394529#problem/D
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
	
	vector<int> vec;
	
	int i; while(cin >> i) vec.push_back(i);
	
	map<int, int> mp;
	for(int i : vec) mp[i]++;
	
	map<int, bool> vis;
	
	for(int i = 0; i < vec.size(); i++){
		vis[vec[i]];
		if(!vis[vec[i]]++){
			cout << vec[i] << ' ' << mp[vec[i]] << endl;
		}
	}
}
