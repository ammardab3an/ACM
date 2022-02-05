
// Problem : F - Big Maximum Sum
// Contest : Virtual Judge - Week #5.0 DP [Medium]
// URL : https://vjudge.net/contest/401749#problem/F
// Memory Limit : 262 MB
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

const int MAX = 2e5 + 10;

struct op{
	int sum;
	int bst_prf, bst_fus;
	int bst_sub;
};

op calc(vector<int> & vec){
	
	op ret;
	int sz = vec.size();
	for(int i = 0; i < sz; i++){
		ret.sum += vec[i];
		ret.bst_prf = max(ret.bst_prf, sum);
	}
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	
	
	
}
