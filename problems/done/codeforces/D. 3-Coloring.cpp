// Problem: D. 3-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 2)
// URL: https://codeforces.com/contest/1504/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

//#define endl '\n'
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

int read(){
    int n;
    cin >> n;
    return n;
}

int write(int b, int i, int j){
    cout << b << ' ' << i << ' ' << j << endl;
}

int32_t main(){

    int n;
    n = read();

    vpii vec0, vec1;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if((i+j)%2==0)
                vec0.push_back({i+1, j+1});
            else
                vec1.push_back({i+1, j+1});
        }
    }

    vector<vi> grid(n, vi(n, 0));

    int i = 0, j = 0;

    while(i < vec0.size() || j < vec1.size()){

        int x = read();

        if(i < vec0.size() && j < vec1.size()){

            if(x == 1) write(2, vec0[i].first, vec0[i].second), i++;
            else if(x == 2) write(1, vec1[j].first, vec1[j].second), j++;

            else {

                if(vec0.size() > vec1.size()){
                    write(2, vec0[i].first, vec0[i].second), i++;
                }
                else{
                    write(1, vec1[j].first, vec1[j].second), j++;
                }
            }
        }

        else if(j < vec1.size()){

            if(x != 1) write(1, vec1[j].first, vec1[j].second), j++;
            else{
                write(3, vec1[j].first, vec1[j].second), j++;
            }
        }

        else{

            if(x != 2) write(2, vec0[i].first, vec0[i].second), i++;
            else{
                write(3, vec0[i].first, vec0[i].second), i++;
            }
        }
    }

    return 0;
}

/*
  arrays sizes
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'


  notes :


*/
