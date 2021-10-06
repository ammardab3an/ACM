// Problem: C. Knapsack
// Contest: Codeforces - Codeforces Round #683 (Div. 2, by Meet IT)
// URL: https://codeforces.com/contest/1447/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int NMAX = 2e5 + 10;

pair<ll, ll> arr[NMAX];

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){

        ll n, w;
        cin >> n >> w;
        
          ll ww =(w+1)/2;

        for(int i = 0; i < n; i++) cin >> arr[i].first, arr[i].second = i;


        sort(arr, arr+n);

        int i = n-1;
        while(i >= 0 && arr[i].first > w) i--;

        ll sm = 0;
        vector<ll> ans;
        for(; i >= 0; i--){
            sm += arr[i].first;
            ans.push_back(arr[i].second);
            if(sm >= ww) break;
        }

        if(ans.empty() || sm < ww){
            cout << -1 << endl;
        }
        else{
            cout << ans.size() << endl;
            for(auto i : ans) cout << i+1 << ' '; cout << endl;
        }
    }


}