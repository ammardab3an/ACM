// xor tree
// Problem: E. Swap and Maximum Block
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)

#include "bits/stdc++.h"

struct node{
	int pre, suf, sum, ans;	
};

node merge(const node &a, const node &b){
	
	node ret;
	ret.sum = a.sum + b.sum;
	ret.pre = max(a.pre, a.sum + b.pre);
	ret.suf = max(b.suf, a.suf + b.sum);
	ret.ans = max({a.ans, b.ans, a.suf+b.pre});
	
	return ret;
}

int arr[NMAX];
vector<node> tree[NMAX << 2];

void build(int nd, int l, int r, int b){
	
	if(l==r){
		int tt = max(arr[l], 0ll);
		tree[nd].push_back((node){tt, tt, arr[l], tt});
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid, b-1);
	build(nd*2+1, mid+1, r, b-1);
	
	for(int x = 0; x < (1<<(b-1)); x++){
		node a = tree[nd*2][x];
		node b = tree[nd*2+1][x];
		tree[nd].push_back(merge(a, b));
	}
	
	for(int x = 0; x < (1<<(b-1)); x++){
		node a = tree[nd*2][x];
		node b = tree[nd*2+1][x];
		tree[nd].push_back(merge(b, a));
	}
}

int32_t main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < (1<<n); i++){
		cin >> arr[i];
	}
	
	build(1, 0, (1<<n)-1, n);
	
	int x = 0;
	int q; cin >> q; while(q--){
		
		int cx;
		cin >> cx;
		x ^= 1<<cx;
		
		cout << tree[1][x].ans << endl;
	}
}
