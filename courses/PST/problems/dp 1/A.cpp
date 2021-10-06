
// Problem : A - Bargain
// Contest : Virtual Judge - Week #5.0 DP [Medium]
// URL : https://vjudge.net/contest/401749#problem/A
// Memory Limit : 262 MB
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

int n;
string num;

pii go(int pos, int p, bool can){
	
	if(pos >= n) return {0, 0};
	
	int ret = 0;
	
	if(!can){
		ret = go(pos+1, p+1, 0).first + int(num[pos] - '0') * round(pow(10, p));
		return {ret, 1};
	}
	
	else{
		for(int i = pos+1; i < n; i++){
			pii tmp = go(i, p+1, 0);
			ret += tmp.first + tmp.second * 
		}
		
		
		return {ret, n-pos};
	} 
	
}
int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	cin >> num;
	n = num.size();
	reverse(num.begin(), num.end());
	cout << go(0, 0, 0).first;
	
	
}
