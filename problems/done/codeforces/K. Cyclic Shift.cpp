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

    #define endl '\n'

//    #ifdef LOCAL
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif // LOCAL

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        string str_a, str_b;
        cin >> str_a >> str_b;

        vi tmp;
        for(int i = 0; i < n; i++){
            if(str_a[i] != str_b[i]){
                tmp.push_back(i);
            }
        }

        if(tmp.empty()){
            cout << "YES" << endl;
            continue;
        }

        string tmp_a = str_a;

        int sz = tmp.size();

        for(int i = 0; i < sz; i++){
            tmp_a[tmp[i]] = str_a[tmp[(i+1)%sz]];
        }

        if(tmp_a == str_b){
            cout << "YES" << endl;
            continue;
        }

        tmp_a = str_a;

        for(int i = 0; i < sz; i++){
            tmp_a[tmp[i]] = str_a[tmp[(i-1+sz)%sz]];
        }

        if(tmp_a == str_b){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

}