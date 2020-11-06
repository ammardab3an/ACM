
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

vector<int> computePrefix(string pat){
	
	int sz = pat.size();
	
	vector<int> longestPrefix(sz);
	
	for(int i = 1, k = 0; i < sz; i++){
	
		while(k > 0 && pat[k] != pat[i])
			k = longestPrefix[k-1];
	
		if(pat[k] == pat[i]) 
			longestPrefix[i] = ++k;
		else
			longestPrefix[i] = k;
	}
	
	return longestPrefix;
}

void KMP(string str, string pat){
	
	int szStr = str.size();
	int szPat = pat.size();
	
	vector<int> longestPrefix = computePrefix(pat);
	
	for(int i = 0, k = 0; i < szStr; i++){
	
		while(k > 0 && pat[k] != str[i])
			k = longestPrefix[k-1];
		
		if(pat[k] == str[i])
			k++;
			
		if(k == szPat){
			cout << i -szPat +1 << endl;
			k = longestPrefix[k-1];
		}
	}
}
int main(){

    fastIO;
	
	string str, pat;
	cin >> pat >> str;
	KMP(str, pat);
	
}
