
// Problem : D2. Magic Powder - 2
// Contest : Codeforces - Codeforces Round #350 (Div. 2)
// URL : https://codeforces.com/contest/670/problem/D2
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

const int MAX = 1e5 + 10;

int n, k;
int a[MAX];
int b[MAX];

bool can(lli cnt){

	lli shortage = 0;

	for(int i = 0; i < n; i++){
		shortage += max(0LL, (lli)a[i] * cnt - b[i]);
		if(shortage > k) return false;
	}

	return true;
}

int main(){

    fastIO;

	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	int ans = 0;

	lli l = 0;
	lli r = 2e9;

	while(l <= r){

		lli mid = (l+r)/2;

		if(can(mid)){
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}

	cout << ans << endl;
}
