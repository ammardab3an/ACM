
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
const int SMAX = 2e5 + 3000;

vector<int> ans;

bool is(int i, int k){

    vector<int> dig;

    while(i){
        dig.push_back(i%k);
        i/=k;
    }

    bool b = true;

    int l = 0;
    int r = dig.size()-1;

    while(l < r){
        if(dig[l] != dig[r]) {
            b = false;
            break;
        }
        l++;
        r--;
    }

    return b;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    freopen("super.in", "r", stdin);


    for(int i = 0; i < SMAX; i++){

        int cnt = 0;

        cnt += is(i, 2) + is(i, 4) + is(i, 8) + is(i, 3) + is(i, 5) + is(i, 6) + is(i, 7) + is(i, 9) + is(i, 10);

        if(cnt >= 2){
           ans.push_back(i);
        }

    }

    int t; cin >> t; while(t--){

        int n, s;
        cin >> n >> s;

        int idx = upper_bound(ans.begin(), ans.end(), s) - ans.begin();

        while(n--){
            cout << ans[idx++] << endl;
        }
    }

}
