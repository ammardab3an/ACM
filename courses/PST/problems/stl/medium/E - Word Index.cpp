
// Problem : E - Word Index
// Contest : Virtual Judge - Week #1[STLs - Medium]
// URL : https://vjudge.net/contest/394527#problem/E
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

int cnt = 0;
map<string, int> mp;

auto comp = [] (string str1, string str2) {
	if(str1.size() != str2.size())
		return str1.size() > str2.size();
	else
		return str1 > str2;
};

priority_queue<string, vector<string>, decltype(comp)> que(comp);

void fillQue(string str){
	
	if(str.size() == 6) return;
	
	que.push(str);

	char lst = str.size() ? str.back() : 'a' -1;
	
	for(char c = lst+1; c <= 'z'; c++){
		str.push_back(c);
		fillQue(str);
		str.pop_back();
	}
}

int main(){

    fastIO;
	
	fillQue("");
	
	while(!que.empty()){
		mp[que.top()] = cnt++;
		que.pop();
	}
	
	string str;
	while(cin >> str){
		if(mp.find(str) != mp.end())
			cout << mp[str] << endl;
		else
			cout << 0 << endl;
	}
		
}
