// Problem: Ada and Harvest
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ADACROP/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

const int MAX_IDS = 2e5 + 10;
const int MAX_NODES = 2e5 + 10;

struct ids_tracker{
    
    int next_id;
    vector<int> free_list;
    
    ids_tracker(){
        next_id = 1;
    }
    
    int get_free_id(){
        
        assert(next_id < MAX_IDS);
        
        if(free_list.empty()){
            return next_id++;
        }
        else{
            int ret = free_list.back();
            free_list.pop_back();
            return ret;
        }
    }
    
    void make_free(int id){
        free_list.push_back(id);
    }
    
} tracker;

typedef int nodeData;
extern struct node nodes[MAX_NODES];
enum DIR {LF, RI};

struct node{
    
    nodeData val;
    int par, ch[2];
    int sz, frq;
    int lazy;
    
    node(){
        memset(this, 0, sizeof *this);
    }
    
    node(nodeData v){
        val = v;
        sz = frq = 1;
        par = ch[LF] = ch[RI] = 0;
    }
    
    void push_up(){
        sz = frq + nodes[ch[LF]].sz + nodes[ch[RI]].sz;
    }
    
    void push_down(){
        return;    
    }
    
} nodes[MAX_NODES];

struct splay_tree{
    
    int root = 0;
    
    DIR get_dir(int par, int child){
        return (DIR) (nodes[par].ch[RI] == child);
    }
    
    void link(int par, int child, DIR d){
        
        if(par){
            nodes[par].ch[d] = child;
            nodes[par].push_up();
        }    
        
        if(child){
            nodes[child].par = par;
        }
    }
     
    void rotate(int q){
        int p = nodes[q].par;
        DIR d = get_dir(p, q);
        int gp = nodes[p].par;
        link(p, nodes[q].ch[!d], d);
        link(q, p, (DIR)!d);       
        link(gp, q, get_dir(gp, p));
    }
    
    void splay(int node_id, int &rt){
        
        int p;
        while(p = nodes[node_id].par){
            
            int gp = nodes[p].par;
            
            if(!gp){
                rotate(node_id);
            }
            else{
                rotate(get_dir(gp, p)==get_dir(p, node_id) ? p : node_id);
                rotate(node_id);
            }
        }
        
        rt = node_id;
    }
    
    void get_by_idx(int idx, int &rt){
        
        int cur = rt;
        assert(idx < nodes[cur].sz);
        
        while(true){
            
            nodes[cur].push_down();
            
            if(idx < nodes[nodes[cur].ch[LF]].sz){
                cur = nodes[cur].ch[LF];        
            }
            else if(idx >= nodes[nodes[cur].ch[LF]].sz + nodes[cur].frq){
                idx -= nodes[nodes[cur].ch[LF]].sz + nodes[cur].frq;
                cur = nodes[cur].ch[RI];
            }
            else{
                break;
            }
        }
        
        splay(cur, rt);
    }
    
    void get_by_value(nodeData value, int &rt){
        
        int cur = rt;
        while(value != nodes[cur].val){
            
            nodes[cur].push_down();
            
            if(value < nodes[cur].val){
                if(nodes[cur].ch[LF]){
                    cur = nodes[cur].ch[LF];
                }
                else{
                    break;
                }
            }
            else{
                if(nodes[cur].ch[RI]){
                    cur = nodes[cur].ch[RI];
                }
                else{
                    break;
                }
            }
        }    
        
        splay(cur, rt);
    }
    
    void splay_max(int &rt){
        
        int cur = rt;
        
        while(true){
            nodes[cur].push_down();
            if(!nodes[cur].ch[RI]) break;
            cur = nodes[cur].ch[RI];
        }
        
        splay(cur, rt);    
    }
    
    int merge(int ls, int gr){
        if(!ls) return gr;
        splay_max(ls);
        link(ls, gr, RI);
        return ls;    
    }
    
    void insert(nodeData value, int &rt){
        
        if(!rt){
            rt = tracker.get_free_id();
            nodes[rt] = node(value);
            return;
        }
        
        get_by_value(value, rt);
        
        if(nodes[rt].val == value){
            nodes[rt].frq++;
            nodes[rt].sz++;
        }
        else{
            DIR d = (DIR)(nodes[rt].val < value);
            int id = tracker.get_free_id();
            nodes[id] = node(value);
            link(id, nodes[rt].ch[d], d);
            link(rt, 0, d);
            link(id, rt, (DIR)(!d));
            rt = id;
        }
    }
    
    void del(nodeData value, int &rt){
        
        get_by_value(value, rt);
        
        if(nodes[rt].val == value){
            
            if(nodes[rt].frq > 1){
                nodes[rt].frq--;
                nodes[rt].sz--;
            }
            else{
                tracker.make_free(rt);
                link(0, nodes[rt].ch[LF], LF);
                link(0, nodes[rt].ch[RI], LF);
                rt = merge(nodes[rt].ch[LF], nodes[rt].ch[RI]);
            }
        }    
    }
    
    int lb(nodeData value, int &rt){
    
        if(!rt){
            return 0;
        }    
        
        int ret = 0;
        int cur = rt;
        
        while(nodes[cur].val != value){
            
            DIR d = (DIR)(nodes[cur].val < value);
            
            if(d){
                ret += nodes[nodes[cur].ch[LF]].sz + nodes[cur].frq;
            }
            
            if(nodes[cur].ch[d]){
                cur = nodes[cur].ch[d];
            }
            else{
                break;
            }
        }
        
        if(nodes[cur].val == value){
            ret += nodes[nodes[cur].ch[LF]].sz;
        }
        
        splay(cur, rt);
        
        return ret;
    }
    
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n), tmp;
    for(auto &i : vec) cin >> i, tmp.push_back(i);
    
    vpii que(m);
    for(auto &p : que){
        cin >> p.first >> p.second;
        tmp.push_back(p.second);
    }
    
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    for(auto &i : vec){
        i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
    }
    
    vector<splay_tree> trees(tmp.size());
    
    for(int i = 0; i < n; i++){
        trees[vec[i]].insert(i, trees[vec[i]].root);
    }
    
    for(auto p : que){
        
        int i = p.first;
        int nv = lower_bound(tmp.begin(), tmp.end(), p.second) - tmp.begin();
        
        splay_tree &st = trees[nv];
        cout << st.lb(i, st.root) << endl;
        
        st.insert(i, st.root);
        splay_tree &nst = trees[vec[i]];
        nst.del(i, nst.root);
        vec[i] = nv;    
    }
}
