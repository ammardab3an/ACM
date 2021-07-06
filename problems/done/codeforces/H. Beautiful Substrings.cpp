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



int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){
        set <char> s[26];
        int n, m, k;
        cin >> n >> m >> k;
        string a, b;
        cin >> a >> b;
        for (int i=k-1;i<n;i++){
            s[a[i] - 'a'].insert(a[i - k + 1]);
        }
        int cnt[26]{0};
        ll Ans = 0;
        for (char c : b) {
            cnt[c-'a']++;
            for (char z : s[c-'a'])
                Ans += cnt[z-'a'];
        }
        cout << Ans << endl;

    }

}