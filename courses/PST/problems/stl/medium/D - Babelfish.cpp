
// Problem : D - Babelfish
// Contest : Virtual Judge - Week #1[STLs - Medium]
// URL : https://vjudge.net/contest/394527#problem/D
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
	
	map<string, string> mp;
	
	string inputLine;
	while(getline(cin, inputLine)){

		if(inputLine == "") break;
		
		stringstream ss(inputLine);
		string fr, to;
		ss >> fr >> to;
		
		mp[to] = fr;
	}
	
	string word;
	while(cin >> word){
		if(mp.find(word) != mp.end())
			cout << mp[word] << endl;
		else 
			cout << "eh" << endl;
	}
}
