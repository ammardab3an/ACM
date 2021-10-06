
// Problem : C. ABBB
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/C
// Memory Limit : 256 MB
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

string str, tmp;
int arr[MAX];

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
    int t; cin >> t; while(t--){
    	
    	cin >> str;
		tmp.clear();
		
		int n = str.size();
		
		int ln = n;
		
		while(true){
			n = ln;
			int cnt0 = 0, cnt1 = 0;
			
			for(int i = 0; i < n; i++){
							
				if(str[i] == 'A'){
					cnt0++;	
				}
				else{
					cnt1 = 1;
					int j;
					for(j = i+1; j < n; j++){
						if(str[j] == 'B') cnt1++;
						else break;
					}
					
					char c = cnt0 <= cnt1 ? 'B' : 'A';
					int m = abs(cnt0 - cnt1);
					for(int k = 0; k < m; k++) tmp.push_back(c);
					
					cnt0 = cnt1 = 0;
					i = j-1;
				}
			}
			
			char c = cnt0 <= cnt1 ? 'B' : 'A';
			int m = abs(cnt0 - cnt1);
			for(int k = 0; k < m; k++) tmp.push_back(c);
			
			int cln = tmp.size();
			if(cln == ln) break;
			
			ln = cln;
			str = tmp;
			tmp.clear();
			
		}
				
		int ans = 0;
		int cnt = 0;
		for(int i = 0; i < ln; i++){
			if(str[i] == 'B') cnt++;
			else{
				if(cnt % 2 == 1) ans++;
				ans++;
				cnt = 0;
			}
		}
		
		if(cnt % 2 == 1) ans++;
		
		cout << ans << endl;
    }
}
