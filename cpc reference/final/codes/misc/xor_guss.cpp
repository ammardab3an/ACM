// xor guss

int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

------------------------------------------------------------------

// all possible value = 2^(size of basis)

------------------------------------------------------------------

// maximum xor

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10, LOG_A = 20;

int basis[LOG_A];

void insertVector(int mask) {
	for (int i = LOG_A - 1; i >= 0; i--) {
		if ((mask & 1 << i) == 0) continue;

		if (!basis[i]) {
			basis[i] = mask;
			return;
		}

		mask ^= basis[i];
	}
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		int a;
		scanf("%d", &a);

		insertVector(a);
	}

	int ans = 0;

	for (int i = LOG_A - 1; i >= 0; i--) {
		if (!basis[i]) continue;

		if (ans & 1 << i) continue;

		ans ^= basis[i];
	}

	cout << ans << endl;

	return 0;
}

------------------------------------------------------------------

// k-th

// up + 
int query(int k) {
	int mask = 0;
 
	int tot = 1 << sz;
	for (int i = LOG_K - 1; i >= 0; i--)
		if (basis[i]) {
			int low = tot / 2;
 
			if ((low < k && (mask & 1 << i) == 0) ||
				(low >= k && (mask & 1 << i) > 0)) mask ^= basis[i];
 
			if (low < k) k -= low;
 
			tot /= 2;
		}
 
	return mask;
}

------------------------------------------------------------------

// Find the number of subsequences of the first l elements of this array, modulo 109+7, such that their bitwise-xor sum is x.

We can answer the queries online. Iterate through the prefix of the array, and for each prefix remember the basis vectors of that prefix.
Then, iterate through the queries. To answer a query, we check if x is actually representable by the prefix of l elements or not, with slight modification to the insertVector function(We don't need to add x, just check if it's representable or not).
If it's not representable, then the answer to the query is 0. If it is representable, then the answer will be 2(l−b), where b is the basis size for the first l elements. It is so, because for each subset of the (l−b) non-basis vectors in the prefix, we find a unique linear combination to yield xor-sum x.
Reference Code
#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii; 
#define x first
#define y second
 
const int N = 1e5 + 10;
const int LOG_A = 20;
const int MOD = 1e9 + 7;
 
int n;
int a[N];
 
int q;
ii q_data[N];
vector<int> q_at[N];
int powers[N];
int ans[N];
 
int base[LOG_A], sz;

bool checkXor(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!base[i]) return false;
 
		mask ^= base[i];
	}
 
	return true;
}

void insertVector(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!base[i]) {
			base[i] = mask;
			sz++;
 
			return;
		}
 
		mask ^= base[i];
	}
}
 
int main() {
	cin >> n >> q;
 
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
 
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &q_data[i].x, &q_data[i].y);
		q_at[q_data[i].x].push_back(i);
	}
 
	powers[0] = 1;
	for (int i = 1; i < N; i++)
		powers[i] = powers[i - 1] * 2LL % MOD;
 
	for (int at = 1; at <= n; at++) {
		insertVector(a[at]);
 
		for (int at_q : q_at[at])
			if (checkXor(q_data[at_q].y)) {
				ans[at_q] = powers[at - sz];
			}
	}
 
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
 
	return 0;
}

------------------------------------------------------------------

You are given an array 0≤ai≤1e9 of 1≤n≤2e5 integers. You have to find the maximum number of segments this array can be partitioned into, such that -
1. Each element is contained in exactly one segment
2. Each segment contains at least one element
3. There doesn't exist a non-empty subset of segments such that bitwise-xor of the numbers from them is equal to 0
Print −1 if no suitable partition exists.


Notice that, saying all subsets of a set yeild non-zero xor is equivalent to saying all subsets of that set yeild different xor-sum. The the xor-sums of segments in the answer partition need to be independent vectors. This is the first of the two main observations.

The second one is that, suppose we picked some segments [l1=1,r1],[l2=r1+1,r2],…,[lk=rk−1+1,rk]. Let, pi be the xor of the xor-sums of the first i segments. Then, observe that, every possible xor of the numbers from some non-empty subset of these segments can also be obtained by xor-ing some subset from the set {p1,p2,ldots,pk} and vice versa. Which means that the set of xor-sums of these segments and the set of prefix xors of these segments produces the exact same set of vectors in Z312. So, if the xor-sums of these segments has to be independent, then so does the prefix xors of these segments. Thus, the answer simply equals the basis size of the n prefix xors of the array. The only exception when the answer equals −1 happens, when the xor-sum of all the elements in the array is 0.
I'll write this solution in more detail tomorrow. I'm half asleep right now.

Reference Code
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10, LOG_PREF = 31;
 
int n;
int basis[LOG_PREF];
 
void insertVector(int mask) {
	for (int i = 0; i < LOG_PREF; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!basis[i]) {
			basis[i] = mask;
			return;
		}
 
		mask ^= basis[i];
	}
}
 
int main() {
	cin >> n;
 
	int pref = 0;
 
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
 
		pref ^= a;
		insertVector(pref);
	}
 
	if (pref == 0) {
		cout << -1 << endl;
		return 0;
	}
 
	int ans = 0;
 
	for (int i = 0; i < LOG_PREF; i++) {
		ans += (basis[i] > 0);
	}
 
	cout << ans << endl;
 
	return 0;
}
