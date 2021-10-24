// Problem: D. Yet Another Array Queries Problem
// Contest: Codeforces - Educational Codeforces Round 29
// URL: https://codeforces.com/problemset/problem/863/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
};

typedef int nodeData;
extern struct node nodes[MAX_NODES];
enum DIR {LF, RI};

struct node{
    
    nodeData val;
    int par, ch[2];
    int sz, frq;
    int lazy_rev;
    
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
        
        if(lazy_rev){
            
            for(auto d : {LF, RI}){
                if(ch[d]){
                     nodes[ch[d]].lazy_rev ^= 1;
                }
            }
            
            swap(ch[LF], ch[RI]);
            lazy_rev = 0;
        }
    }
    
} nodes[MAX_NODES];

struct splay_tree{
    
    int root = 0;
    ids_tracker tracker;
    
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
    
    void split(int rt, int lf_sz, int &ls, int &gr){
        
        if(lf_sz >= nodes[rt].sz){
            ls = rt;
            gr = 0;
            return;
        }    
        
        get_by_idx(lf_sz, rt);
        ls = nodes[rt].ch[LF];
        link(rt, 0, LF);
        link(0, ls, LF);
        gr = rt;
    }
    
    void split(int rt, int l, int r, int &bef, int &btw, int &aft){
        split(rt, r+1, rt, aft);
        split(rt, l, bef, btw);
    }
    
    void rev(int &cur, int l, int r){
        
        int bef, btw, aft;
        split(cur, l, r, bef, btw, aft);
        
        nodes[btw].lazy_rev ^= 1;
        nodes[btw].push_down();
        
        cur = merge(btw, aft);
        cur = merge(bef, cur);
    }
    
    void rot(int &cur, int l, int r, int sh){
        
        int bef, btw, aft;
        split(cur, l, r, bef, btw, aft);
        
        int pre, suf;
        split(btw, nodes[btw].sz-sh, pre, suf);
        
        btw = merge(suf, pre);
        cur = merge(btw, aft);
        cur = merge(bef, cur);
    }
};



int n, q, m;
int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    splay_tree st;
    
    cin >> n >> q >> m;
    
    for(int i = 0; i < n; i++){
        
        int ai;
        cin >> ai;
            
        int id = st.tracker.get_free_id();
        nodes[id] = node(ai);
        st.root = st.merge(st.root, id);
    }

    while(q--){
        
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        
        if(t == 1){
            st.rot(st.root, l, r, 1);
        }
        else{
            st.rev(st.root, l, r);
        }
    }    
    
    while(m--){
        
        int i;
        cin >> i;
        i--;
        
        st.get_by_idx(i, st.root);
        cout << nodes[st.root].val << ' ' ;
    }
}