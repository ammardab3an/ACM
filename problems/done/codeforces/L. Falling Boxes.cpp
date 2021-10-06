// Problem: L. Falling Boxes
// Contest: Codeforces - LU ICPC Selection Contest 2020 and KFU Open Contest 2020
// URL: https://codeforces.com/gym/102862/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MOD = 1e9 + 7, M = 1e5 + 6;
const double EPS = 1e-9;
const double  PI = acos(-1);

vector < vector <int> > g;

int n;
int dp[M];

int go (int i) {

    if (g[i].size() == 0) return 1;

    int &ret = dp[i];
    if (ret + 1)return ret;

    ret = 0;

    for (auto u : g[i]) {
        ret += go(u);
        ret %= MOD;
    }
    
    return ret;
}

int32_t main(){

    cin >> n;

    vector < pair <int, int>  > v;

    g.resize(n);

    int a, b;
    for (int i=0;i<n;i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i=0;i<n;i++){

        int u = v[i].first;
        int y = v[i].second;

        auto iIterator = lower_bound(v.begin(), v.end(), (pair<int,int>){u+1, y});

        if ( iIterator != v.end() && (*iIterator) == (pair<int,int>){u+1, y}){
            g[i].push_back(iIterator - v.begin());
        }

        iIterator = lower_bound(v.begin(), v.end(), (pair<int,int>){u, y+1});

        if ( iIterator != v.end() && (*iIterator) == (pair<int,int>){u, y+1} ){
            g[i].push_back(iIterator - v.begin());
        }
    }

    memset(dp, -1, sizeof dp);

    cout << go(0) << endl;
}