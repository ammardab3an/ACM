
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
#define freopenI freopen("mult.in", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;


int main(){
    
    fastIO;
    freopenI;

    int t; cin >> t; while(t--){
    	
    	int n, k;
    	cin >> n >> k;
    	
    	vi vec(n);
    	for(int i = 0; i < n; i++) cin >> vec[i];
    	sort(vec.begin(), vec.end(), greater<int>());

    	int ans = 1;
    	for(int i = 0; i < k; i++) ans *= vec[i];
    	
    	cout << ans << endl;
    }
	
	
	
}
