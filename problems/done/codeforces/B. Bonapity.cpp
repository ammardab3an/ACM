// Problem: B. Bonapity
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/B
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		string str0, str1;
		cin >> str0 >> str1;
		
		int sz0 = str0.size(), sz1 = str1.size();
		
		bool b = 1;
		if(sz0 != sz1){
			b = 0;
		}else {
			for(int i = 0; i < sz0; i++){
				
				char c0 = str0[i]; c0 = tolower(c0);
				char c1 = str1[i]; c1 = tolower(c1);
				
				if(c0 != c1){
					if((min(c0, c1) == 'b' && max(c0, c1) == 'p') || (min(c0, c1) == 'e' && max(c0, c1) == 'i')){
						b = b;
					}
					else{
						b = 0;
						break;
					}
				}
			}
			
		}
			cout << (b ?"Yes":"No") << endl;
    }	
}
