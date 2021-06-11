// Problem: M. Baby Ehab's Whining Chance
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/M
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 2e5 + 10;

#define int ll

int32_t main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("lis.in", "r", stdin);

    string str;
    cin >> str;

    int n = str.size();

    vi vec(n);
    for(int i = 0; i < n; i++) vec[i] = str[i] -'0';

    vi pre(n);

    pre[0] = vec[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + vec[i];

    int ans = pre.back();

    for(int i = 0; i < n; i++){

        int cans = 0;
        if(i) cans += pre[i-1];
        if(vec[i]) cans += vec[i]-1;
        cans += (n-i-1) * 9;
        ans = max(ans ,cans);
    }

    cout << ans << endl;
}