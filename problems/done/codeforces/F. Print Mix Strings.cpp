
// Problem : F. Print Mix Strings
// Contest : Codeforces - 2015 Damascus Collegiate Programming Contest (DCPC 2015)
// URL : https://codeforces.com/gym/100883/problem/F
// Memory Limit : 64 MB
// Time Limit : 2000 ms
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

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

set<string> st;
string tmp, stri, strj;
int szi, szj;

void go(int i, int j){
	
	if(i == szi && j == szj){
		st.insert(tmp);
		return;
	}
	
	if(i < szi){
		tmp.push_back(stri[i]);
		go(i+1, j);
		tmp.pop_back();
	}
	if(j < szj){
		tmp.push_back(strj[j]);
		go(i, j+1);
		tmp.pop_back();		
	}
	
	
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
	    
	int t; cin >> t; while(t--){
		cin >> stri >> strj;
		tmp.clear(); st.clear(); szi = stri.size(); szj = strj.size();
		go(0, 0);
		for(string str : st) cout << str << endl;
		cout << endl;
	}
	
	
}
