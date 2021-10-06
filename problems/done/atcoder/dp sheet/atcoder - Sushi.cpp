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

int n;
int cnt[4];

bool vis[2][303][303][303];
double mem[2][303][303][303];

double go(int cnt1, int cnt2, int cnt3){
    
    
    if(!cnt1 && !cnt2 && !cnt3) return 1;
    
    double &ret = mem[0][cnt1][cnt2][cnt3];
    
    if(vis[0][cnt1][cnt2][cnt3])
        return ret;
    else
        vis[0][cnt1][cnt2][cnt3] = true;
    
    double ans = 0;
    
    if(cnt1) ans += go(cnt1-1, cnt2, cnt3) * double(cnt1) / (cnt1 + cnt2 + cnt3);
    if(cnt2) ans += go(cnt1+1, cnt2-1, cnt3) * double(cnt2) / (cnt1 + cnt2 + cnt3);;
    if(cnt3) ans += go(cnt1, cnt2+1, cnt3-1) * double(cnt3) / (cnt1 + cnt2 + cnt3);;
    
    return ret = ans;
}

double calc(int cnt1, int cnt2, int cnt3){
    
    
    if(!cnt1 && !cnt2 && !cnt3) return 0;
    
    double &ret = mem[1][cnt1][cnt2][cnt3];
    
    if(vis[1][cnt1][cnt2][cnt3])
        return ret;
    else
        vis[1][cnt1][cnt2][cnt3] = true;
    
    double ans = 0;
    double p_waste = (double) (n - (cnt1+cnt2+cnt3)) / n;
    double ev_waste = p_waste / (1 - p_waste) + 1;
    ans += go(cnt1, cnt2, cnt3) * ev_waste;
    
    if(cnt1) ans += calc(cnt1-1, cnt2, cnt3) * double(cnt1) / (cnt1 + cnt2 + cnt3);
    if(cnt2) ans += calc(cnt1+1, cnt2-1, cnt3) * double(cnt2) / (cnt1 + cnt2 + cnt3);
    if(cnt3) ans += calc(cnt1, cnt2+1, cnt3-1) * double(cnt3) / (cnt1 + cnt2 + cnt3);
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    
    int cnt[3] = {0};
    
    for(int i = 0; i < n; i++){
        
        int ai;
        cin >> ai;
        
        cnt[ai-1]++;
    }
    
    cout << setprecision(13) << calc(cnt[0], cnt[1], cnt[2]);
}
