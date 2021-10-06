
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
const int NMAX = 2e5 + 10;


int n, m, l, r;
string str;
int arr[NMAX];
//int pre[NMAX][10];

int mem[NMAX][10];

int go(int pos, int k){

    if(k == 10) return 0;
    if(pos == r+1) return 0;

    int &ret = mem[pos][k];
    if(ret != -1) return ret;

    return ret = max(go(pos+1, k) + (arr[pos] == k), go(pos, k+1));
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("nds.in", "r", stdin);
  //  freopen("input.txt", "r", stdin);

    int t; cin >> t; while(t--){

        cin >> n >> m >> str;
        for(int i = 0; i < n; i++ ) arr[i] = str[i] - '0';

//        go(0, 0);

//        for(int i = 0; i < 10; i++){
//
//            pre[i][0];
//            for(int j = 1; j < n; i++){
//                pre[i][j] = pre[i][j-1] + (arr[j] == i);
//            }
//        }

        while(m--){
            cin >> l >> r;
            memset(mem, -1, sizeof mem);
            cout << go(l, 0) << endl;
        }
    }

}
