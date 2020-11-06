// Problem : J. Ladder
// Contest : Codeforces - DP
// URL : https://codeforces.com/group/FqtJd4zMPb/contest/272904/problem/J
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

const int MAX = 1e5 + 10;

int arr[MAX];
int pos[MAX];
int neg[MAX];

int main(){

    fastIO;

    int n, m;
    cin >> n >> m;

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	pos[0] = neg[0] = 1;
	for(int i = 1; i < n; i++){
		pos[i] = pos[i-1] + (arr[i-1] <= arr[i]);
		neg[i] = neg[i-1] + (arr[i-1] >= arr[i]);
	}

	while(m--){

		int l, r; cin >> l >> r; l--; r--;

		bool b = false;

		int cl = l;
		int cr = r;

		while(cl <= cr){

			int mid = (cl+cr)/2;

			int sm0 = pos[mid] - pos[l];
			int sm1 = neg[r] - neg[mid];

			bool b0 = sm0 == (mid-l);
			bool b1 = sm1 == (r-mid);

			if(b0 && b1){
				b = true;
				break;
			}

			if(!b0 && !b1) break;

			if(b0) cl = mid+1;
			if(b1) cr = mid-1;

		}

		cout << (b ? "Yes" : "No") << endl;
	}
}
