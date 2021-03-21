// Problem: R - Walk
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_r
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

int n, k;

struct matrix{
    
    vector<vi> mat;
    
    matrix(){
        mat.resize(n, vi(n));
    }  
    
    matrix operator * (const matrix &other){
        
        matrix res = matrix();
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++){
            (res.mat[i][k] += (mat[i][j] * other.mat[j][k]) % MOD) %= MOD;
        }
        
        return res;
    }
    
    void print(){
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << mat[i][j] << ' ';
            cout << endl;
        } cout << endl;
    }
};

matrix binary_exp(matrix m, int p){
    
    matrix res = matrix();
    for(int i = 0; i < n; i++) res.mat[i][i] = 1;
    
    while(p){
        
        if(p&1) res = res * m;
        
        m = m * m;
        
        p /= 2;
    }
    
    return res;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> k;
    
    matrix init = matrix();
    for(int i = 0; i < n; i++) init.mat[i][0] = 1;
    
    matrix move = matrix();
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> move.mat[i][j];
    
    matrix res = binary_exp(move, k) * init;
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        (ans += res.mat[i][0]) %= MOD;
    
    cout << ans << endl;
}
