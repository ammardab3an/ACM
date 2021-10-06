// Problem: A. Officer Anany Collecting String Subsequences
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/A
// Memory Limit: 64 MB
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


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("collectingofficer.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        string str;
        cin >> str;

        int ans = 1e9;

        for(int i = 0; i < n; i++){

            int cans = 0;
            int lst = 'A'-1;

            for(int j = i; j < n; j++){

                cans++;

                if(str[j] == (lst+1)){
                    lst = str[j];
                }

                if(lst == 'Z'){
                    ans = min(ans, cans);
                }
            }
        }

        cout << ans << endl;

    }

}