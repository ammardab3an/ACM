// Problem: Can you answer these queries VI
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/GSS6/
// Memory LFmit: 1536 MB
// Time LFmit: 1000 ms
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

typedef int nodeData;
const int MAX_NODES = 2e5 + 10;
extern struct node nodes[MAX_NODES];
enum DIR {LF, RI};

void print(int node);
void print(int node, int depth);

struct node{

    nodeData val;
    int sz, par, ch[2];
    int pre, suf, sum, ans;

    void set(nodeData nodeValue, bool only_val = false){
        sz = 1;
        pre = suf = sum = ans = val = nodeValue;
        if(!only_val) par = ch[LF] = ch[RI] = 0;
    }

    void push_up(){
        sz = nodes[ch[LF]].sz + nodes[ch[RI]].sz + 1;
        sum = nodes[ch[LF]].sum + nodes[ch[RI]].sum + val;
        pre = max(nodes[ch[LF]].pre, nodes[ch[LF]].sum + val + max(nodes[ch[RI]].pre, (int)0));
        suf = max(nodes[ch[RI]].suf, nodes[ch[RI]].sum + val + max(nodes[ch[LF]].suf, (int)0));
        ans = max(max(nodes[ch[LF]].ans, nodes[ch[RI]].ans), val + max(nodes[ch[LF]].suf, (int)0) + max(nodes[ch[RI]].pre, (int)0));
    }

} nodes[MAX_NODES];

int free_list[MAX_NODES], free_list_sz, next_node_id;

void init(){
    next_node_id = 1;
    free_list_sz = 0;
    auto &nd = nodes[0];
    nd.sum = 0;
    nd.pre = nd.suf = nd.ans = nd.val = -INF;
}

int get_free_node_id(){
    if(free_list_sz){
        return free_list[--free_list_sz];
    }
    return next_node_id++;
}

void make_free(int id){
    free_list[free_list_sz++] = id;
}

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

void splay(int node_id, int &root){

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

    root = node_id;
}

void splay_max(int &root){
    int cur = root;
    while(nodes[cur].ch[RI]) cur = nodes[cur].ch[RI];
    splay(cur, root);
}

int merge(int ls, int gr){
    if(!ls) return gr;
    splay_max(ls);
    link(ls, gr, RI);
    return ls;
}

void get_by_idx(int idx, int &root){

    assert(idx < nodes[root].sz);
    
    int cur = root;

    while(idx != nodes[nodes[cur].ch[LF]].sz){

        if(idx < nodes[nodes[cur].ch[LF]].sz){
            cur = nodes[cur].ch[LF];
        }
        else{
            idx -= nodes[nodes[cur].ch[LF]].sz + 1;
            cur = nodes[cur].ch[RI];
        }
    }

    splay(cur, root);
}

void insert(int idx, nodeData value, int &root){

    if(!root && idx == -1){
        root = get_free_node_id();
        nodes[root].set(value);
        return;
    }

    get_by_idx(idx, root);

    DIR d = (DIR)(RI);
    int id = get_free_node_id();
    nodes[id].set(value);
    link(id, nodes[root].ch[d], d);
    link(root, 0, d);
    link(id, root, (DIR)(!d));
    root = id;
}

void replace(int idx, nodeData nvalue, int &root){
    get_by_idx(idx, root);
    nodes[root].set(nvalue, true);
    nodes[root].push_up();
}

void del(int idx, int &root){
    get_by_idx(idx, root);
    make_free(root);
    link(0, nodes[root].ch[LF], LF);
    link(0, nodes[root].ch[RI], LF);
    root = merge(nodes[root].ch[LF], nodes[root].ch[RI]);
}

int query(int l, int r, int &root){
    get_by_idx(l-1, root);
    nodes[nodes[root].ch[RI]].par = 0;
    get_by_idx(r-l+1, nodes[root].ch[RI]);
    link(root, nodes[root].ch[RI], RI);
    return nodes[nodes[nodes[root].ch[RI]].ch[LF]].ans;
}

int n;
int arr[NMAX];

void print(int node, int depth){

    if (!node){
        return void();
    }

    print(nodes[node].ch[RI], depth + 2);
    printf("%s%d\n", string(depth, ' ').c_str(), nodes[node].val);
    print(nodes[node].ch[LF], depth + 2);
}

void print(int node){
    puts("--------------");
    print(node, 0);
    puts("--------------");
    fflush(stdout);
}

int32_t main(){

     fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    init();
    int root = 0;

    insert(-1, -INF, root);
    
    for(int i = 0; i < n; i++){
        insert(i, arr[i], root);
    }

    insert(n, -INF, root);

    int m; cin >> m; while(m--){

        char c;
        cin >> c;

        if(c == 'I'){
            int idx, val;
            cin >> idx >> val;
            insert(idx-1, val, root);
        }
        else if(c == 'R'){
            int idx, nval;
            cin >> idx >> nval;
            replace(idx, nval, root);
        }
        else if(c == 'D'){
            int idx;
            cin >> idx;
            del(idx, root);
        }
        else if(c == 'Q'){
            int l, r;
            cin >> l >> r;
            int que = query(l, r, root);
            cout << que << endl;
        }
    
        // print(root);
    }
}
