// Problem: D. Cleaning the Phone
// Contest: Codeforces - Codeforces Round #697 (Div. 3)
// URL: https://codeforces.com/contest/1475/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n, m;
int one[NMAX];
int two[NMAX];
int pre_one[NMAX];
int pre_two[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		cin >> n >> m;
		
		int sz0 = 0, sz1 = 0;
		
		vpii tmp(n);
		for(int i = 0; i < n; i++) cin >> tmp[i].first;
		for(int i = 0; i < n; i++) cin >> tmp[i].second;
		
		for(int i = 0; i < n; i++){

			int ai = tmp[i].first;
			int val = tmp[i].second;

			if(val == 1)
				one[sz0++] = ai;
			else
				two[sz1++] = ai;
		}
		
		sort(one, one+sz0, greater<int>());
		sort(two, two+sz1, greater<int>());
		
		pre_one[0] = one[0];
		for(int i = 1; i < sz0; i++) pre_one[i] = pre_one[i-1] + one[i];
		pre_two[0] = two[0];
		for(int i = 1; i < sz1; i++) pre_two[i] = pre_two[i-1] + two[i];
		
		int ans = INF;
		
		for(int i = -1; i < sz0; i++){

			int cur = (i+1) ? pre_one[i] : 0;
			
			int cans = i+1;
			
			if(cur < m){
				int j = lower_bound(pre_two, pre_two+sz1, m-pre_one[i]) - pre_two;
				if(j == sz1) continue;
				cans += 2*(j+1);
			}
			
			ans = min(ans, cans);
		}
		
		cout << (ans!=INF ? ans : -1) << endl;
    }	
}
