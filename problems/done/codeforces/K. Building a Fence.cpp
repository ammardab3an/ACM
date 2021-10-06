// Problem: K. Building a Fence
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/K
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int long long int

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

		int n, k;
		cin >> n >> k;

		vector<int> vec(n);
		for(int i = 0; i < n; i++) cin >> vec[i];
		
		int lb, ub, nlb, nub;
		lb = ub = vec[0];
		
		for(int i = 1; i < n-1; i++){
			
			int nlb = max(lb - (k-1) , 0LL);
			int nub = ub + (k-1);
			nlb = max(nlb, vec[i]);
			nub = min(nub, vec[i] + (k-1));
			
			if(nlb > nub){
				cout << "No" << endl;
				goto next;
			}
			
			lb = nlb;
			ub = nub;
		}
		
		
		nlb = max(lb-(k-1), 0LL);
		nub = ub + (k-1);
		
		if(vec[n-1] < nlb || nub < vec[n-1]){
			cout << "No" << endl;
		}else{
			cout << "Yes" << endl;
		}
		
		next:;
    }	
}
