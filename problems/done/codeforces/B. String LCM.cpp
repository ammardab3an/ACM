// Problem: B. String LCM
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1473/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
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
		
		int len0(str0.size()), len1(str1.size());
		
		if(len0 > len1){
			swap(len0, len1);
			swap(str0, str1);
		}
		
		int lcm = (len0 * len1) / __gcd(len0, len1);
		
		string res = "";
		
		for(int i = 0; i < (lcm/len0); i++) res += str0;
		
		bool bb = true;
		
		int n = res.size();
		for(int i = 0; i < n; i++){
			if(res[i] != str1[i%len1]){
				bb = false;
				break;
			}
		}
		
		if(!bb){
			cout << -1 << endl;
		}
		else{
			cout << res << endl;
		}
    }	
}
