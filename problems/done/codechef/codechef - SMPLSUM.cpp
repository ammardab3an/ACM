// Problem: Simple Sum
// Contest: CodeChef - NOV15
// URL: https://www.codechef.com/problems/SMPLSUM
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define ll long long
#define YES "YES"
#define NO "NO"
#define endline '\n'
#define testcases
#define outfiles
#define infiles

using namespace std;

const int N = 1e7 + 10, MM = 998244353, MAX = 1e18;

#define gcd __gcd

// int gcd(int a, int b) {
	// if (b > a)swap(a, b);
	// if (!b)return a;
	// return gcd(b, a % b);
// }

int primes[N],phi[N];

void seive() {
	for (int i = 2; i < N; i++) {
		if (primes[i])continue;
		for (int j = i; j < N; j+=i) {
			if (primes[j])continue;
			primes[j] = i;
		}
	}
	phi[1] = 1;
	for (int i = 2; i < N; i++) {
		int p = primes[i];
		if (i % (p * p) == 0) {
			phi[i] = phi[i / p] * p;
		}
		else {
			phi[i] = phi[i / p] * (p - 1);
		}
	}
}

long long res[N];

void solve1() {
	res[1] = 1;
	for (long long i = 2; i < N; i++) {
		int p = primes[i];
		int cur = p;
		while (i % (cur*p) == 0) {
			cur *= p;
		}
		if (cur == i) {
			res[i] = phi[i] * i + res[i / p];
		}
		else {
			res[i] = res[i / cur] * res[cur];
		}
	}
}

int solve() {
	int n; cin >> n;
	cout << res[n] << '\n';
	return 0;
}

int main() {

	speed;
	seive();
	solve1();

#ifdef outfile
	FILE* stream;
	freopen("out.txt", "w", stdout);
#endif

#ifdef infile
	//FILE* stream;
	freopen("in.txt", "r", stdin);
#endif

	int t = 1;

#ifdef testcases
	cin >> t;
#endif

	int i = 1;
	while (t--) {
		//cout << "Case " << i++ << ": ";
		solve();
	}
	return 0;
}
