// Problem: C. Component Tree
// Contest: Codeforces - 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// URL: https://codeforces.com/gym/100513/problem/C
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

// #define endl '\n'
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

struct node{
    string val;
    node *left, *right;    
    node(string val, node *left, node *right):
        val(val), left(left), right(right){}
    
    node* insert(int l, int r, int p, const string &val);
};

node *null = new node("", 0, 0);

node* node::insert(int l, int r, int p, const string &val){
    
    if(p < l || r < p) return this;
    
    if(l==r){
        return new node(val, null, null);
    }    
    
    int mid = (l+r)/2;
    return new node("", this->left->insert(l, mid, p, val), 
                        this->right->insert(mid+1, r, p, val));
}

string query(node *nd, int l, int r, int p){
    
    if(l==r){
        return nd->val;
    }    
    
    int mid = (l+r)/2;
    if(p <= mid) return query(nd->left, l, mid, p);
    else return query(nd->right, mid+1, r, p);
}

const int NMAX = 3e5 + 10;

int par[NMAX];
vi adj[NMAX];
node* root[NMAX];
vector<pair<string, string> > tmp[NMAX];
vector<string> comp;
int comp_sz;

void dfs(int u, int p){
    
    int i = u;
    for(int j = 0; j < tmp[i].size(); j++){
        
        int key = lower_bound(comp.begin(), comp.end(), tmp[i][j].first) - comp.begin();
        string value = tmp[i][j].second;
        
        if(j==0){
            root[i] = (i==0 ? null : root[p])->insert(0, comp_sz-1, key, value);
        }
        else{
            root[i] = root[i]->insert(0, comp_sz-1, key, value);
        }
    }
    
    if(tmp[i].empty()){
        root[i] = (i==0) ? null : root[p];
    }
    
    for(auto v : adj[u]){
        dfs(v, u);
    }
}

int32_t main(){

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        int m, p;
        cin >> p >> m;
        
        par[i] = p-1;
        
        if(i != 0){
            adj[par[i]].push_back(i);
        }
        
        for(int j = 0; j < m; j++){
            
            string t;
            cin >> t;
            
            bool b = false;
            string key, value;
            for(char c : t){
                if(c=='='){
                    b = true;
                }
                else if(!b){
                    key.push_back(c);
                }
                else{
                    value.push_back(c);
                }
            }
            
            comp.emplace_back(key);
            
            tmp[i].emplace_back(key, value);
        }    
    }
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    comp_sz = comp.size();
    
    null->left = null->right = null;
    
    dfs(0, -1);
    
    int q; cin >> q; while(q--){
        
        int nd;
        string key;
        cin >> nd >> key;
        nd--;
        
        auto it = lower_bound(comp.begin(), comp.end(), key);
        
        if(it == comp.end() || *it != key){
            cout << "N/A" << endl;
            continue;
        }    
        
        int _key = it - comp.begin();
        
        string que = query(root[nd], 0, comp_sz-1, _key);
        if(que == "") que = "N/A";
        cout << que << endl;
    }
}
