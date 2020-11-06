#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000100

int n;
ll seg[N * 5];
// 0 is XOR
// 1 is OR
ll op[N * 5];
ll a[N];

void merge(int p){
	if (op[p]) seg[p] = seg[p * 2] | seg[p * 2 + 1];
	else seg[p] = seg[p * 2] ^ seg[p * 2 + 1];
}

void build(int p = 1, int L = 1, int R = n){
	if (L == R){
		seg[p] = a[L];
		op[p] = 0;
		return;
	}

	int mid = (L + R) / 2;
	build(p * 2, L, mid);
	build(p * 2 + 1, mid + 1, R);

	assert(op[p * 2] == op[p * 2 + 1]);
	op[p] = !op[p * 2];
	merge(p);
}

void update(int i, ll val, int p = 1, int L = 1, int R = n){
	if (L > i || R < i) return;
	if (L == i && R == i){
		seg[p] = val;
		return;
	}

	int mid = (L + R) / 2;
	update(i, val, p * 2, L, mid);
	update(i, val, p * 2 + 1, mid + 1, R);

	merge(p);
}

int main(){
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n; n = (1 << n);
	int m; cin >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();
	while (m--){
		ll i, b; cin >> i >> b;
		update(i, b);
		cout << seg[1] << endl;
	}

	return 0;
}