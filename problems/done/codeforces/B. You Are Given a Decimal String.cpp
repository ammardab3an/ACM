
// Problem : B. You Are Given a Decimal String...
// Contest : Codeforces - Educational Codeforces Round 70 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1202/problem/B
// Memory Limit : 256 MB
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

int x, y;
int dist[11][11];
string str;

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
	
	cin >> str;
	int sz = str.size();
	
	for(int x = 0; x < 10; x++){
		
		for(int y = 0; y < 10; y++){
			
			memset(dist, inf, sizeof dist);
			
			for(int i = 0; i < 10; i++) dist[i][(i+x)%10] = dist[i][(i+y)%10] = 1;
			
			for(int k = 0; k < 10; k++)
			for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			
			lli ans = 0;
			for(int i = 0; i < sz-1; i++){
	
				int a = str[i]   - '0';
				int b = str[i+1] - '0';
	
				if(dist[a][b] == inf){
					ans = -1;
					break;
				}
				
				ans += dist[a][b] -1;
			}
			
			cout << ans << ' ';
		}   
		
		cout << endl;	
	}
		
}
