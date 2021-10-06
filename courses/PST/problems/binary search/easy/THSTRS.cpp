
// Problem : Three Strings
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/THSTRS
// Memory Limit : 256 MB
// Time Limit : 1750 ms
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

vector<int> computePrefix(string pat){
	
	int sz = pat.size();
	
	vector<int> longestPrefix(sz);
	
	int k = 0;
	for(int i = 1; i < sz; i++){
	
		while(k > 0 && pat[k] != pat[i])
			k = longestPrefix[k-1];
	
		if(pat[k] == pat[i]) 
			k++;

		longestPrefix[i] = k;
	}
	
	return longestPrefix;
}

bool KMP(string str, string pat){
	
	int szStr = str.size();
	int szPat = pat.size();
	
	vector<int> longestPrefix = computePrefix(pat);
	
	int k = 0;
	for(int i = 0; i < szStr; i++){

		while(k > 0 && pat[k] != str[i])
			k = longestPrefix[k-1];
		
		if(pat[k] == str[i])
			k++;
			
		if(k == szPat){
			return true;
			k = longestPrefix[k-1];
		}
	}
	
	return false;
}


int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int t; cin >> t; while(t--){
		
		string a, b, c;
		cin >> a >> b >> c;
	
		int cnt = a.length() + b.length();
		
		if(KMP(a+b, c)){
			cout << cnt << endl;
			continue;
		}
		
		int cnt_t_a = computePrefix(c + "#" + a).back();
		int cnt_t_b = computePrefix(b + "#" + c).back();
		int cnt_t = cnt_t_a + cnt_t_b;
		
		if(cnt_t < c.length()){
			cnt += c.length() - cnt_t;
		}
		
		else{
			cnt += c.length() - max(cnt_t_a, cnt_t_b);
		}
		
		cout << cnt << endl;
	}	
	
	
}
