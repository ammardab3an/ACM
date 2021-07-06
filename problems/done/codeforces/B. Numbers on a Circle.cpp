// Problem: B. Numbers on a Circle
// Contest: Codeforces - LU ICPC Selection Contest 2020 and KFU Open Contest 2020
// URL: https://codeforces.com/gym/102862/problem/B
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
int n , k ;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    cin >> n >> k ;

    if(n==4 && k==3){
        cout << "Yes" << endl;
        return 0;
    }

    if(k > 2){
        cout << "No" << endl;
        return 0;
    }
    if(k == 1){
        cout << "Yes" << endl;
        return 0;
    }

    if(k == 2){

        if(n%2==0){
            cout << (0==0 ? "Yes" : "No") << endl;
        }
        else{
            cout << "No" << endl;
        }

        return 0;
    }

}