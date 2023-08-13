/*
           _                   _         _       __  __  _____ 
     /\   | |            /\   | |       | |     |  \/  |/ ____|
    /  \  | |__   ___   /  \  | |__   __| | ___ | \  / | |     
   / /\ \ | '_ \ / _ \ / /\ \ | '_ \ / _` |/ _ \| |\/| | |     
  / ____ \| |_) | (_) / ____ \| |_) | (_| | (_) | |  | | |____ 
 /_/    \_\_.__/ \___/_/    \_\_.__/ \__,_|\___/|_|  |_|\_____|
*/
 
// build command:
// g++ -std=gnu++17 -O3 -DDEBUG -g -fsanitize=signed-integer-overflow -fsanitize=bounds-strict -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=float-divide-by-zero -fsanitize=pointer-overflow -fsanitize=shift-exponent -fsplit-stack -Wshadow -Wall -fconcepts -Wno-unused-result
 
// REMEMBER:
// BS, Offline, Persistent SegTree, SQRT, Treap, MaxFlow, FFT, Matrices
 
#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O3,unroll-loops")
 
// DEBUG STUFF
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
 
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
int getrand(int l,int r) {
	return uniform_int_distribution<int>(l, r)(RNG);
}
 
const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
const int N = 1e6 + 7;
 
int add(int x,int y) {
	int ret = ((ll)x+y)%mod;
	return ret;
}
 
int mult(int x,int y) {
	int ret = ((ll)x*y)%mod;
	return ret;
}
 
string str;
int n,q;
 
struct Query {
	int type;
	char c;
	int k;
};
 
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            int j = i;
            while (j > 0 && 'a' + c != s[j])
                j = pi[j-1];
            if ('a' + c == s[j])
                j++;
            aut[i][c] = j;
        }
    }
}
 
 
void solve(int tc) {
	cin >> str;
	n = sz(str);
	cin >> q;
	vector<Query> queries(q+1);
	for(int i = 1 ; i <= q ; i++) {
		cin >> queries[i].type;
		if (queries[i].type <= 2) cin >> queries[i].c;
		else {
			cin >> queries[i].k;
		}
	}
	
	vector<vector<int>> aut;
	compute_automaton(str, aut);
	
	vector<vector<int>> autq(n+1,vector<int>(q+1));
	vector<vector<int>> ans(n+1,vector<int>(q+1));
 
	for(int i = 0 ; i <= n ; i++) autq[i][0] = i;
 
	for(int j = 1 ; j <= q ; j++) {
		int type = queries[j].type;
		if (type == 1) {
			int c = queries[j].c-'a';
			for(int i = 0 ; i <= n ; i++) {
				autq[i][j] = aut[autq[i][j-1]][c];
				ans[i][j] = add(ans[i][j-1], (aut[autq[i][j-1]][c] == n));
			}
		} else if (type == 2) {
			int c = queries[j].c-'a';
			for(int i = 0 ; i <= n ; i++) {
				autq[i][j] = autq[aut[i][c]][j-1];
				ans[i][j] = add(ans[aut[i][c]][j-1], (aut[i][c] == n));
				//dbg(i,j,autq[i][j]);
			}
		} else if (type == 3) {
			int k = queries[j].k;
			for(int i = 0 ; i <= n ; i++) {
				autq[i][j] = autq[autq[i][j-1]][k];
				ans[i][j] = add(ans[i][j-1], ans[autq[i][j-1]][k]);
			}
		} else if (type == 4) {
			int k = queries[j].k;
			for(int i = 0 ; i <= n ; i++) {
				autq[i][j] = autq[autq[i][k]][j-1];
				ans[i][j] = add(ans[i][k], ans[autq[i][k]][j-1]);
			}
		}
		cout << ans[0][j] << '\n';
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T = 1;
	cin >> T;
	for(int i = 0 ; i < T ; i++) solve(i+1);
	return 0;
}
