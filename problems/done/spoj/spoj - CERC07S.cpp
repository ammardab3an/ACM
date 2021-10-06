
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef int nodeData;
const int MAX_NODES = 2e5 + 10;
extern struct node nodes[MAX_NODES];
enum DIR {LF, RI};

struct node{
    
    nodeData val;
    int sz, par, ch[2];
    int lazy_rev;
    
    void set(nodeData nodeValue){
        sz = 1;
        val = nodeValue;
        par = ch[LF] = ch[RI] = 0;
    }    
    
    void push_up(){
        sz = 1 + nodes[ch[LF]].sz + nodes[ch[RI]].sz;
    }
    
    void push_down(){
        if(lazy_rev){
            swap(ch[LF], ch[RI]);
            for(auto id : ch){
                nodes[id].lazy_rev ^= 1;
            }
            lazy_rev = 0;
        }
    }
    
    void reverse(){
        lazy_rev ^= 1;
    }
    
} nodes[MAX_NODES];

int free_list[MAX_NODES], free_list_sz, next_node_id;

void init(){
    next_node_id = 1;
    free_list_sz = 0;
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


nodeData get_by_idx(int idx, int &root){
    
    int cur = root;
    
    while(true){
        
        nodes[cur].push_down();
        
        if(idx < nodes[nodes[cur].ch[LF]].sz){
            cur = nodes[cur].ch[LF];        
        }
        else if(idx >= nodes[nodes[cur].ch[LF]].sz + 1){
            idx -= nodes[nodes[cur].ch[LF]].sz + 1;
            cur = nodes[cur].ch[RI];
        }
        else{
            break;
        }
    }
    
    splay(cur, root);
    
    return nodes[cur].val;
}

void splay_max(int &root){
    int cur = root;
    while(nodes[cur].push_down(), nodes[cur].ch[RI]) cur = nodes[cur].ch[RI];
    splay(cur, root);    
}

int merge(int ls, int gr){
    if(!ls) return gr;
    splay_max(ls);
    link(ls, gr, RI);
    return ls;    
}

void split(int root, int lf_sz, int &ls, int &gr){
    
    if(lf_sz >= nodes[root].sz){
        ls = root;
        gr = 0;
        return;    
    }
    
    get_by_idx(lf_sz, root);
    ls = nodes[root].ch[LF];
    link(root, 0, LF);
    link(0, ls, LF);
    gr = root;
}

void push_down_from_root(int nd){
    if(!nd) return;
    push_down_from_root(nodes[nd].par);
    nodes[nd].push_down();
}

int get_idx(int cur){
    push_down_from_root(cur);
    int ret = nodes[nodes[cur].ch[LF]].sz;
    while(cur){
        int p = nodes[cur].par;
        if(get_dir(p, cur) == RI){
            ret += nodes[nodes[p].ch[LF]].sz + 1;
        }
        cur = p;
    }
    return ret;
}

void reverse(int &cur, int st, int en){
    int bef, aft, btwn;
    split(cur, en+1, cur, aft);
    split(cur, st, bef, btwn);
    nodes[btwn].reverse();
    cur = merge(btwn, aft);
    cur = merge(bef, cur);    
}

int32_t main(){
    
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    while(cin >> n, n){
        
        init();
        int root = 0;
        
        vector<int> vec;
        
        for(int i = 0; i < n; i++){
            int ai;
            cin >> ai;
            int id = get_free_node_id();
            nodes[id].set(ai);
            vec.push_back(id);
            root = merge(root, id);
        }
        
        stable_sort(vec.begin(), vec.end(), [&](int a, int b){
            return nodes[a].val < nodes[b].val;
        });
        
        int i = 0;
        for(auto &id : vec){
            int idx = get_idx(id);
            cout << idx+1 << ' ';
            reverse(root, i++, idx); 
        }
        cout << endl;
    }
}
