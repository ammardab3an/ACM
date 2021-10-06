// Problem: C. A or B Equals C
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/C
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t


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
		
		int n; cin >> n;
		string str0, str1;
		cin >> str0 >> str1;
		
		int cnt = 1;
		
		
		for(int i = 0; i < n; i++){
			
			int a = str0[i] - '0';
			int b = str1[i] - '0';
			
			if(a == 1 && b == 1){
				cnt *= 2;
				cnt %= MOD;
			} else if(a == 0 && b == 1){
				cnt *= 1;
			}else if(a == 0 && b == 0){
				cnt *= 1;
			}else if(a == 1 && b == 0){
				cnt = -1;
				break;
			}
		}
		
		if(cnt != -1){
			cout << cnt << endl;
		}else{
			cout << "IMPOSSIBLE" << endl;
		}
    }	
}
