
// Problem : A - Restaurant
// Contest : Virtual Judge - Week #2.1 [Greedy] easy ~ medium
// URL : https://vjudge.net/contest/396749#problem/A
// Memory Limit : 262 MB
// Time Limit : 4000 ms
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

const int MAX = 5e5 + 10;

int n;
int mem[MAX];
pii arr[MAX];
int st[MAX];
int nd[MAX];

int go(int pos){
	
	if(pos >= n) return 0;
	
	int & ret = mem[pos];
	if(ret != -1) return ret;
	
	int mx = go(pos+1);
	
	auto it = upper_bound(st, st+n, nd[pos]);
	
	mx = max(mx, go(it - st) + 1);
	
	return ret = mx;
}

int main(){

    fastIO;
    
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}	
	
	auto comp = [](pii a, pii b){
		if(a.first != b.first)
			return a.first < b.first;
		return a.second < b.second;
	};
	
	sort(arr, arr+n, comp);
    	
	for(int i = 0; i < n; i++){
		st[i] = arr[i].first;
		nd[i] = arr[i].second;
	}
	
	memset(mem, -1, sizeof mem);
	
	cout << go(0) << endl;	
	
}
