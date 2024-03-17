
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
            
            nodes[cur].push_down();
            
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
