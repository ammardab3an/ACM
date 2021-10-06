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

const int NMAX = 3e5 + 10;

struct node{
    
    string val;
    node *l = 0, *r = 0;
    
    node *left(){
        if(!l) l = new node();
        return l;
    }
    
    node *right(){
        if(!r) r = new node();
        return r;
    }
    
    node *insert(int l, int r, int p, const string &str){
        
        node *nd = new node(*this);
        
        if(l==r){
            nd->val = str;
        }
        else if(p <= (l+r)/2){
            nd->l = nd->left()->insert(l, (l+r)/2, p, str);
        }
        else{
            nd->r = nd->right()->insert((l+r)/2+1, r, p, str);
        }
        
        
        return nd;
    }
    
    string query(int l, int r, int p){
        
        if(l == r){
            return val;
        }
        else if(p <= (l+r)/2){
            return this->l ? this->l->query(l, (l+r)/2, p) : "N/A";
        }
        else{
            return this->r ? this->r->query((l+r)/2+1, r, p) : "N/A";
        }
    }
};

node* root[NMAX];
map<string, int> mp;

int32_t main(){

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        int m, p;
        cin >> p >> m;
        
        if(i == 0){
            root[i] = new node();
        }    
        else{
            root[i] = root[p-1];
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
            
            if(!mp.count(key)) mp[key] = mp.size();
            root[i] = root[i]->insert(0, NMAX, mp[key], value);
        }    
    }
    
    int q; cin >> q; while(q--){
        
        int nd;
        string key;
        cin >> nd >> key;
        nd--;
        
        if(!mp.count(key)){
            cout << "N/A" << endl << flush;
        }
        else{
            string value = root[nd]->query(0, NMAX, mp[key]);
            cout << value << endl << flush;
        }
    }
}
