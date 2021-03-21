// tle cause by the primes numbers greater than sqrt(n) you idiot 
// 
// Problem: D. GCD of an Array
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

int arr[NMAX];
vpii seg[NMAX << 2];

vpii get(int num){
    vpii ret;
    for(int i = 2; i*i <= num; i++){
        int cnt = 0;
        while(num%i==0) cnt++, num/=i;
        if(cnt) ret.emplace_back(i, cnt);
    }
    if(num > 1) ret.emplace_back(num, 1);
    return ret;
}

vpii merge(vpii &v0, vpii &v1){

    int i = 0;
    int j = 0;
    
    int sz0 = v0.size();
    int sz1 = v1.size();    
    
    vpii ret;
    
    while(i < sz0 && j < sz1){
        while(i < sz0 && v0[i].first < v1[j].first) i++;
        if(i < sz0 && v0[i].first == v1[j].first)
            ret.emplace_back(v0[i].first, min(v0[i].second, v1[j].second));
        j++;
    }
    
    return ret;
}

vpii add(vpii &v0, vpii &v1){
    
    int i = 0;
    int j = 0;
    
    int sz0 = v0.size();
    int sz1 = v1.size();    
    
    vpii ret;
    
    while(i < sz0 && j < sz1){
        
        while(i < sz0 && v0[i].first < v1[j].first){
            ret.emplace_back(v0[i++]);
        }
        if(i < sz0 && v0[i].first == v1[j].first){
            ret.emplace_back(v0[i].first, v0[i].second + v1[j].second);
            i++;
        }
        else{
            ret.emplace_back(v1[j]);
        }
        j++;
    }
    
    while(i < sz0) ret.emplace_back(v0[i++]);
    while(j < sz1) ret.emplace_back(v1[j++]);
    return ret;
}

void build(int nd, int L, int R){

    if(L == R){
        seg[nd] = get(arr[L]);
        return;
    }

    int mid = (L + R)/2;

    build(nd*2, L, mid);
    build(nd*2+1, mid+1, R);
    
    seg[nd] = merge(seg[nd*2], seg[nd*2+1]);
}

void update(int nd, int L, int R, int idx, int val){

    if(L == R){
        vpii tmp = get(val);
        seg[nd] = add(seg[nd], tmp);
        return;
    }

    int mid = (L + R)/2;

    if(idx <= mid)
        update(nd*2, L, mid, idx, val);
    else
        update(nd*2+1, mid+1, R, idx, val);

    seg[nd] = merge(seg[nd*2], seg[nd*2+1]);
}

int fast_pow(int n, int p){
    if(!p) return 1;
    if(p & 1) return (n * fast_pow(n, p-1)) % MOD;
    int tmp = fast_pow(n, p/2);
    return (tmp * tmp) % MOD;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    build(1, 1, n);
    
    while(m--){
        
        int i, x;
        cin >> i >> x;
        
        update(1, 1, n, i, x);
        
        int ans = 1;
        auto &tmp = seg[1];
        
        for(auto &p : tmp){
            ans *= fast_pow(p.first, p.second);
            ans %= MOD;
        }
        
        cout << ans << endl;
    }	
}
