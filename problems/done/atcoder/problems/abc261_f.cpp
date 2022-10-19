// Problem: F - Sorting Color Balls
// Contest: AtCoder - AtCoder Beginner Contest 261
// URL: https://atcoder.jp/contests/abc261/tasks/abc261_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include<bits/stdc++.h>

#define int int64_t
#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

typedef vector<int> vi;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int32_t main(){

	fastIO;

	int n;
	while(cin >> n){

		vi vec_c(n);
		for(auto &i : vec_c) cin >> i, --i;
		vi vec_x(n);
		for(auto &i : vec_x) cin >> i, --i;

		int ans = 0;
		vector<vi> vec(n);

		{
			FenwickTree bit(n);
			for(int i = 0; i < n; i++){
				int c = vec_c[i];
				int x = vec_x[i];
				if(x < n-1) ans += bit.sum(x+1, n-1);
				bit.add(x, 1);
				vec[c].push_back(x);
			}
		}

		for(auto &v : vec){

			vi tmp = v;
			sort(tmp.begin(), tmp.end());
			tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
			for(auto &i : v) i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();

			int sz = tmp.size();
			FenwickTree bit(sz);
			for(auto i : v){
				if(i != sz) ans -= bit.sum(i+1, sz-1);
				bit.add(i, 1);
			}
		}

		cout << ans << endl;
	}
}
