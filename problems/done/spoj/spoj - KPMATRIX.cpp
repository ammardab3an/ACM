
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef int nodeData;
const int MAX_NODES = 2e5 + 10;
extern struct node nodes[MAX_NODES];
enum DIR {LF, RI};

struct node{
    
    nodeData val;
    int sz, frq, par, ch[2];
    
    void set(nodeData nodeValue){
        sz = frq = 1;
        val = nodeValue;
        par = ch[LF] = ch[RI] = 0;
    }    
    
    void push_up(){
        sz = frq + nodes[ch[LF]].sz + nodes[ch[RI]].sz;
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

void get_by_value(nodeData value, int &root){
    
    while(value != nodes[root].val){
        
        if(value < nodes[root].val){
            if(nodes[root].ch[LF]){
                root = nodes[root].ch[LF];
            }
            else{
                break;
            }
        }
        else{
            if(nodes[root].ch[RI]){
                root = nodes[root].ch[RI];
            }
            else{
                break;
            }
        }
    }    
    
    splay(root, root);
}

nodeData get_by_idx(int idx, int &root){
    
    if(idx >= nodes[root].sz){
        return INT_MIN;
    }    
    
    int cur = root;
    
    while(true){
        
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
    
    splay(cur, root);
    
    return nodes[cur].val;
}

void insert(nodeData value, int &root){
    
    if(!root){
        root = get_free_node_id();
        nodes[root].set(value);
        return;
    }
    
    get_by_value(value, root);
    
    if(nodes[root].val == value){
        nodes[root].frq++;
        nodes[root].sz++;
    }
    else{
        DIR d = (DIR)(nodes[root].val < value);
        int id = get_free_node_id();
        nodes[id].set(value);
        link(id, nodes[root].ch[d], d);
        link(root, 0, d);
        link(id, root, (DIR)(!d));
        root = id;
    }
}

int lb(nodeData value, int &root){
    
    if(!root){
        return 0;
    }    
    
    int ret = 0;
    int cur = root;
    
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
    
    splay(cur, root);
    
    return ret;
}

int ub(int value, int &root){
    return lb(value+1, root);    
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

void del(nodeData value, int &root){
    
    get_by_value(value, root);
    
    if(nodes[root].val == value){
        
        if(nodes[root].frq > 1){
            nodes[root].frq--;
            nodes[root].sz--;
        }
        else{
            make_free(root);
            link(0, nodes[root].ch[LF], LF);
            link(0, nodes[root].ch[RI], LF);
            root = merge(nodes[root].ch[LF], nodes[root].ch[RI]);
        }
    }    
}

int32_t main(){
    
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    init();
    int root = 0;
    
    
}
