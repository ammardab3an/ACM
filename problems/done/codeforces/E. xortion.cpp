
// Problem : E. xortion
// Contest : Codeforces - 2015 Damascus Collegiate Programming Contest (DCPC 2015)
// URL : https://codeforces.com/gym/100883/problem/E
// Memory Limit : 128 MB
// Time Limit : 3000 ms
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

const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 10;

int n, q;
int arr[MAX];

struct node{
	node * nxt[2];	
	node(){
		nxt[0] = nxt[1] = nullptr;
	}
};

void add(int x, node & root){
	
	node * cur = &root;
	
	for(int i = 31; i >= 0; i--){
		
		bool v = x & (1 << i);
		
		if(cur -> nxt[v] == nullptr)
			cur -> nxt[v] = new node();
			
		cur = cur -> nxt[v];
	}

}

int query(int x, node & root){
	
	int ans = 0;
	
	node * cur = & root;
	
	for(int i = 31; i >= 0; i--){
		
		bool v = x & (1 << i);
		
		if(cur -> nxt[!v] == nullptr) {
			ans ^= (v) << i;
		}
		else{
			ans ^= (!v) << i;
			v = !v;
		}
		
		cur = cur -> nxt[v];
	}
	
	return ans;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int t; cin >> t; while(t--){

		cin >> n >> q;
		node root = node();
		
		map<int, vi> mp;
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			mp[arr[i]];
			mp[arr[i]].push_back(i);
			add(arr[i], root);
		}
		
		while(q--){
			
			int x; cin >> x;
			int ans = query(x, root);
			cout << mp[ans][0] +1 << endl;
		}
		
		cout << endl;
	}
	
	
}
