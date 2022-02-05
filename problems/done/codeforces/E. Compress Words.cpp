
// Problem : E. Compress Words
// Contest : Codeforces - Codeforces Round #578 (Div. 2)
// URL : https://codeforces.com/contest/1200/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef unsigned int		uint;
typedef long long int       lli;
typedef unsigned long long  ull;
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

int computePrefix(string str){

	int sz = str.size();
	vector<int> longestPrefix(sz);

	for(int i = 1; i < sz; i++){

        int j = longestPrefix[i-1];

		while(j > 0 && str[j] != str[i])
			j = longestPrefix[j-1];

		if(str[j] == str[i])
			j++;

		longestPrefix[i] = j;
	}

	return longestPrefix.back();
}

int main(){

    fastIO;

#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL

	int n;
	string ans;

	cin >> n >> ans;

	for(int i = 1; i < n; i++){

		string nxt;
		cin >> nxt;

		string tmp = nxt + "#";

		int lenAns = ans.length();
		int lenNxt = nxt.length();
		int minLen = min(lenAns, lenNxt);

		// i = i = min(0, lenAns - lenNxt)

		for(int i = lenAns - minLen; i < lenAns; i++)
			tmp.push_back(ans[i]);

		int pos = computePrefix(tmp);
		for(int i = pos; i < lenNxt; i++)
			ans += nxt[i];
	}

	cout << ans;
}
