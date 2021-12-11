// Problem: E. Messages
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 1000 + 10;
const int NMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n;
vi comp;
pii tmp[NMAX];
vi arr[NMAX];
vi arr_pre[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
        
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp[i].first >> tmp[i].second;
        comp.push_back(tmp[i].first);
    }
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    
    for(int i = 0; i < n; i++){
        int m = tmp[i].first;
        int k = tmp[i].second;
        m = lower_bound(comp.begin(), comp.end(), m) - comp.begin();
        arr[m].push_back(k);
    }
    
    for(int i = 0; i < comp.size(); i++){
        sort(arr[i].begin(), arr[i].end());
        arr_pre[i].resize(arr[i].size());
        arr_pre[i][0] = arr[i][0];
        for(int j = 1; j < arr[i].size(); j++){
            arr_pre[i][j] = arr_pre[i][j-1] + arr[i][j];
        }
    }
    
    double ans = 0;
    multiset<pii> ans_mst;
    
    int mn = min((int)20, n);
    for(int cnt = 1; cnt <= mn; cnt++){
        
        multiset<pii> mst;
        for(int i = 0; i < comp.size(); i++){
            auto it = upper_bound(arr[i].begin(), arr[i].end(), cnt);
            int cur = (arr[i].end() - it) * cnt;
            if(it != arr[i].begin()) cur += arr_pre[i][it-arr[i].begin()-1];
            mst.insert({cur, i});
            if(mst.size() > cnt) mst.erase(mst.begin());
        }
        
        double cans = 0;
        for(auto p : mst) cans += p.first;
        
        cans /= cnt;
        
        if(ans < cans){
            ans = cans;
            ans_mst = mst;
        }
    }   
    
    cout << ans_mst.size() << endl;
    for(auto p : ans_mst) cout << comp[p.second] << ' ' ; cout << endl;
}