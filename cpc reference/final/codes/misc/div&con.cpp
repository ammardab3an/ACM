// div & con (lg trick)
// online queries of mul(arr[l ... r]) % p not prime

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, p, q;
        cin >> n >> p >> q;
        int k = n == 1 ? 0 : __lg(n - 1) + 1;
        vector<int> a(1 << k);
        for (int i=0; i<n; i++)
            cin >> a[i];
        vector<int> b(q / 64 + 2);
        for (int &x : b)
            cin >> x;

        vector<vector<long long>> prod(k, vector<long long>(1 << k));

        auto recur = [&] (auto &self, int lg, int l, int r) -> void {
            if (lg < 0)
                return;
            int m = (l + r) / 2;
            for (int i=m-1; i>=l; i--)
                prod[lg][i] = a[i] * (i == m - 1 ? 1 : prod[lg][i+1]) % p;
            for (int i=m; i<r; i++)
                prod[lg][i] = a[i] * (i == m ? 1 : prod[lg][i-1]) % p;
            self(self, lg - 1, l, m);
            self(self, lg - 1, m, r);
        };

        auto query = [&] (int l, int r) -> int {
            if (l == r)
                return a[l];
            int lg = __lg(l ^ r);
            return prod[lg][l] * prod[lg][r] % p;
        };

        recur(recur, k - 1, 0, 1 << k);

        int x = 0, l, r;
        for (int i=0; i<q; i++) {
            if (i % 64 == 0) {
                l = (b[i / 64] + x) % n;
                r = (b[i / 64 + 1] + x) % n;
            } else {
                l = (l + x) % n;
                r = (r + x) % n;
            }
            if (l > r)
                swap(l, r);
            x = (query(l, r) + 1) % p;
        }
        cout << x << "\n";
    }

    return 0;
}