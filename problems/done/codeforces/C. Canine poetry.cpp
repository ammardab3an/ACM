// Problem: C. Canine poetry
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/C
// Memory Limit: 256 MB
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

const int NMAX = 1e5 + 10;

int n;
string str;

int mem[2][27][27];

int go(int pos, int a, int b){
	
	if(pos == n) return 0;
	
	int & ret = mem[pos][a][b];
	if(~ret) return ret;
	
	int c = str[pos] - 'a';
	
	int ans = INF;
	
	if(c == a || c == b){
		for(int i = 0; i <= 25; i++) if(i != a) if(i != b){
			ans = min(ans, go(pos+1, b, i) +1);
		}
	}
	else{
		ans = go(pos+1, b, c);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> str;
		n = str.size();
		
		memset(mem, 0, sizeof mem);
				
		for(int i = n-1; i >= 0; i--)
		for(int j = 0; j <= 26; j++)
		for(int k = 0; k <= 26; k++){
			
			int c = str[i] -'a';
			
			int & ans = mem[i%2][j][k];
			ans = INF;
			
			if(c == j || c == k){
				
				for(int l = 0; l < 26; l++){
					ans = min(ans, mem[(i+1)%2][k][l] +1);
				}
			}	
			else ans = mem[(i+1)%2][k][c];
		}
			
		cout << mem[0][26][26] << endl;
			
//		memset(mem, -1, sizeof mem);
		
//		cout << go(0, 27, 27) << endl;
    }	
}
