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
    
    void push_down_from_root(int cur){
        if(!cur) return;
        push_down_from_root(nodes[cur].par);
        nodes[cur].push_down();
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
    
    void print(int node, int depth){
    
        if (!node){
            return void();
        }
        
        print(nodes[node].ch[RI], depth + 1);
        printf("%s%d\n", string(depth, ' ').c_str(), nodes[node].val);
        print(nodes[node].ch[LF], depth + 1);
    }
    
    void print(int node){
        puts("--------------");
        print(node, 0);
        puts("--------------");
        fflush(stdout);
    }
};

