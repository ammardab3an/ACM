// Problem: F. Multicolored Markers
// Contest: Codeforces - Codeforces Round #506 (Div. 3)
// URL: https://codeforces.com/contest/1029/problem/F
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

pii tree[NMAX<<2];

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p){
        return ;
    }    
    
    if(l==r){
        tree[nd] = {val, l};
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
    
    if(q_r < l || r < q_l){
        return {INFLL, -1};
    }
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    auto st_path = query(nd*2, l, mid, q_l, q_r);
    auto nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    memset(tree, INF, sizeof tree);
    
    int a, b;
    cin >> a >> b;
    
    vi comp;
    vpii vec;
    
    for(int i = 1; i*i <= a; i++){
        if(a%i==0){
            vec.push_back({i, a/i});
            comp.push_back(i);
            comp.push_back(a/i);
        }
    }
    
    for(int i = 1; i*i <= b; i++){
        if(b%i==0){
            vec.push_back({i, b/i});
            comp.push_back(i);
            comp.push_back(b/i);
        }
    }
    
    int area = a+b;
    vpii vec_area;
    
    for(int i = 1; i*i <= area; i++){
        if(area%i==0){
            vec_area.push_back({i, area/i});
            comp.push_back(i);
            comp.push_back(area/i);
        }
    }
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    
    for(auto &p : vec){
        int &i = p.first;
        int &j = p.second;
        i = lower_bound(comp.begin(), comp.end(), i) - comp.begin();
        j = lower_bound(comp.begin(), comp.end(), j) - comp.begin();
    }
    
    for(auto &p : vec_area){
        int &i = p.first;
        int &j = p.second;
        i = lower_bound(comp.begin(), comp.end(), i) - comp.begin();
        j = lower_bound(comp.begin(), comp.end(), j) - comp.begin();
    }
    
    
    sort(vec.begin(), vec.end());
    sort(vec_area.begin(), vec_area.end());
    reverse(vec.begin(), vec.end());
    reverse(vec_area.begin(), vec_area.end());
    
    int ans = INFLL;
    
    int j = 0;
    
    for(int i = 0; i < vec.size(); i++){
        
        while((j<vec_area.size()) && (vec_area[j].first >= vec[i].first)){
            int per = 2ll*(comp[vec_area[j].first] + comp[vec_area[j].second]);
            update(1, 0, comp.size()-1, vec_area[j].second, per);
            j++;
        }
        
        auto cans = query(1, 0, comp.size()-1, vec[i].second, comp.size()-1);
        ans = min(ans, cans.first);
    }
    
    cout << ans << endl;
}

