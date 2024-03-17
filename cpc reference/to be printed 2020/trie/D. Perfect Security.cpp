// Problem: D. Perfect Security
// Contest: Codeforces - Codeforces Round #470 (rated, Div. 2, based on VK Cup 2018 Round 1)
// URL: https://codeforces.com/contest/948/problem/D
// Memory Limit: 512 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

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

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int  MAX = 2e5 + 10;
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;

int arr[NMAX];

struct node{
	int cnt = 0;
	node * nxt[2] = {nullptr, nullptr};
};

void update(int x, node & root){
	
	node * cur = &root;
	
	for(int i = 30; i >= 0; i--){
		
		bool b = x & (1 << i);
		if(cur->nxt[b] == nullptr) cur->nxt[b] = new node();
		cur = cur->nxt[b];
		cur->cnt++;
	}
}

int get(int x, node & root){
	
	node * cur = &root;
	
	int ans = 0;
	
	for(int i = 30; i >= 0; i--){
		
		bool b = x & (1 << i);
		if(cur->nxt[b] == nullptr || cur->nxt[b]->cnt < 1) b = !b;
		
		ans ^= b << i;
		
		cur = cur->nxt[b];
		cur->cnt--;
	}
	
	return ans;
}


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

	{

		int n;
		cin >> n;
			
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		node root = node();
		
		for(int i = 0; i < n; i++){
			int x; cin >> x; update(x, root);
		}
		
		for(int i = 0; i < n; i++){
			cout << (arr[i] ^ get(arr[i], root)) << ' ';
		}
    }	
}
