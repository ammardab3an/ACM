#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 400100

int n;
int hsCnt;
map<int, int> hs;
set<int> have;
ll from[N];
ll to[N];
ll seg[N * 10];
ll lazy[N * 10];

void build(int p = 1, int L = 0, int R = hsCnt - 1){
	if (L == R){
		seg[p] = lazy[p] = 0;
		return;
	}

	int mid = (L + R) / 2;
	build(p * 2, L, mid);
	build(p * 2 + 1, mid + 1, R);
}

void pushLazy(int p){
	if (lazy[p]){
		lazy[p * 2] = lazy[p * 2 + 1] = seg[p] = lazy[p];
		lazy[p] = 0;
	}
}

void update(int i, int j, int val, int p = 1, int L = 0, int R = hsCnt - 1){
	pushLazy(p);
	if (L > j || R < i) return;
	if (L >= i && R <= j){
		lazy[p] = val;
		pushLazy(p);
		return;
	}

	int mid = (L + R) / 2;
	update(i, j, val, p * 2, L, mid);
	update(i, j, val, p * 2 + 1, mid + 1, R);
}

int query(int i, int p = 1, int L = 0, int R = hsCnt - 1){
	pushLazy(p);
	if (L > i || R < i) return 0;
	if (L == i && R == i) return seg[p];

	int mid = (L + R) / 2;
	int c1 = query(i, p * 2, L, mid);
	int c2 = query(i, p * 2 + 1, mid + 1, R);
	if (c1) return c1;
	else return c2;
}

int main(){
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> from[i] >> to[i];
			hs[from[i]]; hs[from[i] - 1]; hs[from[i] + 1];
			hs[to[i]]; hs[to[i] - 1]; hs[to[i] + 1];
		}
		hsCnt = 0;
		for (map<int, int>::iterator it = hs.begin(); it != hs.end(); it++) it->second = hsCnt++;
		for (int i = 1; i <= n; i++) from[i] = hs[from[i]], to[i] = hs[to[i]];

		build();
		for (int i = 1; i <= n; i++){
			update(from[i], to[i], i);
		}
		have.clear();
		for (int i = 0; i < hsCnt; i++){
			int val = query(i);
			if (val > 0) have.insert(val);
		}
		cout << have.size() << endl;
	}

	return 0;
}