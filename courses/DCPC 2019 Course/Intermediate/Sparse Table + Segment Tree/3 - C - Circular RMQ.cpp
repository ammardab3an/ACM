#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200100

int n, m;
ll a[N];
ll seg[N * 10];
ll lazy[N * 10];

void build(int p = 1, int L = 1, int R = n){
	if (L == R){
		seg[p] = a[L];
		lazy[p] = 0;
		return;
	}

	int mid = (L + R) / 2;
	build(p * 2, L, mid);
	build(p * 2 + 1, mid + 1, R);
	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

void pushLazy(int p){
	if (lazy[p]){
		lazy[p * 2] += lazy[p];
		lazy[p * 2 + 1] += lazy[p];
		seg[p] += lazy[p];
		lazy[p] = 0;
	}
}

void update(int i, int j, ll val, int p = 1, int L = 1, int R = n){
	pushLazy(p);
	if (L > j || R < i) return;
	if (L >= i && R <= j){
		lazy[p] += val;
		pushLazy(p);
		return;
	}

	int mid = (L + R) / 2;
	update(i, j, val, p * 2, L, mid);
	update(i, j, val, p * 2 + 1, mid + 1, R);
	seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

ll query(int i, int j, int p = 1, int L = 1, int R = n){
	pushLazy(p);
	if (L > j || R < i) return 1e18;
	if (L >= i && R <= j) return seg[p];

	int mid = (L + R) / 2;
	ll c1 = query(i, j, p * 2, L, mid);
	ll c2 = query(i, j, p * 2 + 1, mid + 1, R);
	return min(c1, c2);
}

int main(){
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();

	cin >> m; cin.ignore();
	ll input[5];
	while (m--){
		string line;
		getline(cin, line);
		stringstream ss(line);
		int i = 0;
		while (ss >> input[i++]);
		ll L = input[0], R = input[1];
		L++, R++;
		if (i == 3){
			if (L <= R){
				ll ans = query(L, R);
				cout << ans << endl;
			}
			else{
				swap(L, R);
				ll ans1 = query(1, L);
				ll ans2 = query(R, n);
				cout << min(ans1, ans2) << endl;
			}
		}
		else{
			ll val = input[2];
			if (L <= R){
				update(L, R, val);
			}
			else{
				swap(L, R);
				update(1, L, val);
				update(R, n, val);
			}
		}
	}

	return 0;
}