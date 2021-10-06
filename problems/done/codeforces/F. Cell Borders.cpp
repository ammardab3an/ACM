// Problem: F. Cell Borders
// Contest: Codeforces - LU ICPC Selection Contest 2020 and KFU Open Contest 2020
// URL: https://codeforces.com/gym/102862/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int MAX = 2e5 + 10;

const int NMAX = 1E5 + 10;

int n;
int arr[NMAX];
int mem[NMAX][2];

bool go(int idx, int lst){

    if(idx == n)
        return true;

    int &ret = mem[idx][lst];
    if(ret+1) return ret;

    bool ans = false;

    int i = idx;

    if(arr[i] == 0){

        if(lst){
            ans = false;
        }
        else{
            ans = go(idx+1, 0);
        }
    }
    else if(arr[i] == 1){
        if(lst){
            ans = go(idx+1, 0);
        }
        else{
            ans = go(idx+1, 1);
        }
    }
    else if(arr[i] == 2){
        if(!lst){
            ans = false;
        }
        else{
            ans = go(idx+1, 1);
        }
    }

    return ret = ans;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    memset(mem, -1, sizeof mem);

    int ans = go(0, 0) || go(0, 1);

    cout << (ans ? "Yes" : "No") << endl;
}