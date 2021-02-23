// Problem: 10017 - The Never Ending Towers of Hanoi
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=958
// Memory Limit: 32 MB
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

int n, m;
vi A, B, C;

void print(){
    
    cout << endl;
    
    for(auto  p : { (pair<vi, string>){A, "A=>"}, 
                    (pair<vi, string>){B, "B=>"}, 
                    (pair<vi, string>){C, "C=>"}}){
        
        cout << p.second;
        
        if(!p.first.empty()){
            cout << "   ";
            bool b = false;
            for(auto i : p.first) 
                cout << (vector<string>){"", " "}[b++] << i;
        }
        cout << endl;
    }
}

void go(int n, vi &src, vi &dis, vi &aux){
    
    if(!m || !n) return;
        
    go(n-1, src, aux, dis);
    
    if(!m) return;
    m--;
    
    dis.push_back(src.back());
    src.pop_back();
    print();
    
    go(n-1, aux, dis, src);    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t = 1;
    while(cin >> n >> m, n){
        
        A.clear();
        B.clear();
        C.clear();
        
        for(int i = n; i >= 1; i--) A.push_back(i);
        
        cout << "Problem #" << t++ << endl;
        
        print();
        go(n, A, C, B);
        
        cout << endl;
    }
}
