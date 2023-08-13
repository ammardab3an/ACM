
// G. Great Chase
// https://qoj.ac/contest/1103/problem/5505


#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll N = 1e6 + 10, MM = 1e9 + 7, MAX = 1e18;

int solve() {
	
	int n; 
	cin >> n;
	
	ll v; 
	cin >> v;
	
	vector<pair<ll, ll>>lef, rig;
	
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		if (a < 0) {
			lef.emplace_back(a, b);
		}
		else {
			rig.emplace_back(a, b);
		}
	}

	long double l = 0, r = 1e18;
	long double time = 0;
	
	int num = 150;
	while (num--) {
		
		long double mid = l + (r - l) / 2.0;
		long double mxlef = -1e18, mnrig = 1e18;
		
		for (auto x : lef) {
			mxlef = max(mxlef, mid * (long double)(x.second) + (long double)(x.first));
		}
		
		for (auto x : rig) {
			mnrig = min(mnrig, (long double)(x.first) - mid * (long double)(x.second));
		}
		
		if (mnrig <= mxlef) {
			time = mid;
			r = mid;
		}
		else {
			l = mid;
		}
	}
	
	cout << fixed << setprecision(10) << time*v << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	int i = 1;
	while (t--) {
		solve();
	}
	return 0;
}