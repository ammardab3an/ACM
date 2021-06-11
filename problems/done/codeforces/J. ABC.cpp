// Problem: J. ABC
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/J
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

    freopen("abc.in", "r", stdin);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int cnt[3] = {0};

    {
        for(auto c : str) cnt[c-'a']++;

        if(cnt[0] && !cnt[1] && cnt[2]){
            cout << -1 << endl;
            return 0;
        }

        if(cnt[0] && cnt[1] && !cnt[2]){
            cout << 0 << endl;
            return 0;
        }

        if(!cnt[0] && cnt[1] && cnt[2]){
            cout << 0 << endl;
            return 0;
        }

        if(cnt[0] && !cnt[1] && !cnt[2]){
            cout << 0 << endl;
            return 0;
        }

        if(!cnt[0] && !cnt[1] && cnt[2]){
            cout << 0 << endl;
            return 0;
        }
    }

    int idx = -1;

    if(cnt[1])
    for(int i = 0; i < n; i++) if(str[i] == 'b'){
        idx = i;
        break;
    }

    int ans1 = 0;
    for(int i = 0; i < cnt[0]; i++){
        if(str[i] != 'a'){
            ans1++;
        }
    }

    if(cnt[1]) if(str[cnt[0]] != 'b'){
        if(idx < cnt[0] && str[cnt[0]] == 'a') ans1 += 0;
        else ans1 += 1;
    }

    int ans2 = 0;
    for(int i = 0; i < cnt[2]; i++){
        if(str[i] != 'c'){
            ans2++;
        }
    }

    if(cnt[1]) if(str[cnt[2]] != 'b'){
        if(idx < cnt[2] && str[cnt[2]] == 'c') ans2 += 0;
        else ans2 += 1;
    }

    cout << min(ans1, ans2) << endl;
}