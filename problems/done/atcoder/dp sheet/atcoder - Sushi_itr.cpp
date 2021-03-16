// Problem: J - Sushi
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_j
// Memory Limit: 1024 MB
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

double mem[2][303][303][303];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    int cnt[3] = {0};
    
    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        cnt[ai-1]++;
    }
    
    mem[0][cnt[0]][cnt[1]][cnt[2]] = 1;
    mem[1][cnt[0]][cnt[1]][cnt[2]] = 0;
    
    for(int k = n; k >= 0; k--)
    for(int j = n; j >= 0; j--)
    for(int i = n; i >= 0; i--)
    {
        
        if(!i && !j && !k) continue;
        if(i+j+k > n) continue;
        
        // p_waste + p_waste^2 + p_waste^3 + ... = S
        // 1 + S = S / p_waste
        // -> S = p_waste / (1 - p_waste)
        // 1.0 is the propability of doing the experiment n times
        
        double sp_waste = double(n - (i+j+k))/n;
        double p_waste = sp_waste / (1.0 - sp_waste) + 1.0; 
        mem[1][i][j][k] += mem[0][i][j][k] * p_waste;
        
        if(i){
            double p_go = (double) i / (i+j+k);
            mem[0][i-1][j][k] += mem[0][i][j][k] * p_go;
            mem[1][i-1][j][k] += mem[1][i][j][k] * p_go;
        }
        
        if(j){
            double p_go = (double) j / (i+j+k);
            mem[0][i+1][j-1][k] += mem[0][i][j][k] * p_go;
            mem[1][i+1][j-1][k] += mem[1][i][j][k] * p_go;
        }
        
        if(k){
            double p_go = (double) k / (i+j+k);
            mem[0][i][j+1][k-1] += mem[0][i][j][k] * p_go;
            mem[1][i][j+1][k-1] += mem[1][i][j][k] * p_go;
        }
    }
    
    cout << setprecision(13) << mem[1][0][0][0];
}
