// Problem: C. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1501/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
map<int, vpii> mp;

void check(int sm){
    
    vpii tmp = mp[sm];
    
    for(int sz = tmp.size(), i = 0; i < sz; i++)
    for(int j = i+1; j < sz; j++){
        
        if((tmp[i].first != tmp[j].first) && (tmp[i].first != tmp[j].second) && (tmp[i].second != tmp[j].first) && (tmp[i].second != tmp[j].second)){
        
            cout << "YES" << endl;
            
            for(auto p : (vpii){tmp[i], tmp[j]})
                cout << p.first << ' ' << p.second << ' ';
            
            exit(0);
        }
    }
    
    if(tmp.size() == 4){
        
        cout << "YES" << endl;
        
        if(tmp[0].first == tmp[1].first)
            for(auto p : tmp) cout << p.second << ' ';
        else
            for(auto p : tmp) cout << p.first << ' ';
        
        exit(0);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
        
        int sm = arr[i] + arr[j];
        
        mp[sm].emplace_back(i+1, j+1);
        
        if(mp[sm].size() > 1)
            check(sm);
    }

    cout << "NO" << endl;
}
