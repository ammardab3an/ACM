// Problem: J. X and Beasts
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/J
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// powaered by CP Editor (https://cpeditor.org)


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

int n;
int arr[111];
int powa[111];
int mem[111][111];

int go(int pos, int lst){
	
	if(pos == n+1) return 0;
	
	int & ret = mem[pos][lst];
	if(~ret) return ret;
	
	int stPath = go(pos+1, lst);
	
	int ndPath = -1;
	
	if(arr[lst] < arr[pos])
		ndPath = go(pos+1, pos) + powa[pos];
	
	return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 1; i <= n; i++){
			
			cin >> arr[i];
			
			if(arr[i] & 1){
				powa[i] = 0;
				
			} else{
				
				powa[i] = 0;
				
				int tmp = arr[i];
				
				while(!(tmp&1)){
					powa[i]++;
					tmp >>= 1;
				}
				
			}
		}
		
		//for(int i = 1; i <= n; i++) cout << powa[i] << ' '; cout << endl;
		
		memset(mem, -1, sizeof mem);
		cout << go(1, 0) << endl;
    }	
}
