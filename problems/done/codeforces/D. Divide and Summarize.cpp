// Problem: D. Divide and Summarize
// Contest: Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL: http://codeforces.com/contest/1461/problem/D
// Memory Limit: 256 MB
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

int n, q;
int arr[NMAX];
int sm[NMAX];

map<int, bool> all;

void go(int i, int j){
	
	if(i > j) return;
	
	int csm = sm[j];
	if(i) csm -= sm[i-1];
	
	all[csm] = 1;
		
	int mid = (arr[i] + arr[j])/2;
	int pos = upper_bound(arr+i, arr+j+1, mid) - arr;
	
	if(pos-1 != j) {
		go(i, pos-1);
		go(pos, j);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n >> q;
		for(int i = 0; i < n; i++) cin >> arr[i];
	
		sort(arr, arr+n);
		
		sm[0] = arr[0];
		for(int i = 1; i < n; i++) sm[i] = sm[i-1] + arr[i];
		
		all.clear();
		go(0, n-1);
		
		//for(auto p : all) cout << p.first << endl;
		
		while(q--){
			int x; cin >> x;
			cout << (all[x] ? "Yes" : "No") << endl;
		}
    }	
}
