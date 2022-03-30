#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int nodeData;

const int MaxNodes = 2e5 + 2;

extern struct node nodes[MaxNodes];

enum DIR {LF, RI};

struct node{
    
    nodeData val;
    int freq, par, Sz, ch[2];

    void set(nodeData nodeValue){
        ch[0] = ch[1] = par = 0;
        val = nodeValue;
        freq = Sz = 1;
    }

    void push_up(){
        Sz = freq + nodes[ch[LF]].Sz + nodes[ch[RI]].Sz;
    }
    
}nodes[MaxNodes];

int freeList[MaxNodes], freeListSz, nextNodeId;

int getFreeNodeId(){
    if (freeListSz){
        return freeList[--freeListSz];
    }
    return nextNodeId++;
}
void init(){
    nextNodeId = 1;
    freeListSz = 0;
}
void makeFree(int nodeId){
    freeList[freeListSz++] = nodeId;
}

void link(int par, int child, DIR d){
    
    if (par){
        nodes[par].ch[d] = child;
        nodes[par].push_up();
    }
    if (child){
        nodes[child].par = par;
    }
}

DIR getDir(int par, int child){
    return (DIR)(nodes[par].ch[RI] == child);
}

/*
 *         gp
 *         |
 *         |
 *         p
 *        / \d
 *       a  q
 *         / \
 *        b   c
 */

/*
 *         gp
 *         |
 *         |
 *         q
 *        / \
 *      p    c
 *     / \
 *   a    b
 */

inline void rotate(int q) {
    int p = nodes[q].par;
    DIR d = getDir(p, q);
    int gp = nodes[p].par;
    // p -> q -> gp
    link(p, nodes[q].ch[!d], d);
    link(q, p, (DIR)!d);
    link(gp, q, getDir(gp, p));
}


/*
 *       gp
 *   gpd/ \
 *     p
 *    / \pd
 *     nodeid
 */
 
inline void splay(int nodeId, int &root) {
    
    int p;
    while(p = nodes[nodeId].par)
    {
        int gp = nodes[p].par;
        if(!gp) rotate(nodeId);
        else
        {
            rotate(getDir(gp, p) == getDir(p, nodeId) ? p : nodeId);
            rotate(nodeId);
        }
    }
    root = nodeId;
}

void getByValue(nodeData value, int &root){
    
    while (value != nodes[root].val){
        
        if (value < nodes[root].val){
            if (nodes[root].ch[LF]){
                root = nodes[root].ch[LF];
            }
            else{
                break;
            }
        }
        else{
            if (nodes[root].ch[RI]){
                root = nodes[root].ch[RI];
            }
            else{
                break;
            }
        }
    }
    
    splay(root, root);
}


nodeData getByIdx(int &root, int index){
    
    if (index >= nodes[root].Sz){
        return INT_MIN;
    }

    int cur = root;
    
    while(true){   
        if(index < nodes[ nodes[cur].ch[LF] ].Sz){
            cur = nodes[cur].ch[LF];
        }
        else if(index >= nodes[ nodes[cur].ch[LF] ].Sz + nodes[cur].freq){
            index -= nodes[ nodes[cur].ch[LF] ].Sz + nodes[cur].freq;
            cur = nodes[cur].ch[RI];
        }
        else{
            break;
        }
    }

    splay(cur, root);
    
    return nodes[cur].val;
}

void insert(int &root, nodeData value){
    
    if (!root) {
        root = getFreeNodeId();
        nodes[root].set(value);
        return void();
    }

    getByValue(value, root);
    
    if (nodes[root].val == value){
        nodes[root].freq++;
        nodes[root].Sz++;
    }
    else{
        DIR d = (DIR)(value > nodes[root].val);
        int id = getFreeNodeId();
        nodes[id].set(value);
        link(id, nodes[root].ch[d], d);
        link(root, 0, d);
        link(id, root, (DIR)(!d));
        root = id;
    }
}

int lb(int &root, nodeData value){ // lower bound
    
    if (!root){
        return 0;
    }

    int ret = 0, cur;
    for (cur = root; nodes[cur].val != value; ){
        
        DIR d = (DIR)(value > nodes[cur].val);

        if (d){
            ret += nodes[ nodes[cur].ch[LF] ].Sz + nodes[cur].freq;
        }

        if (nodes[cur].ch[d]){
            cur = nodes[cur].ch[d];
        }
        else break;
    }
    
    if (value == nodes[cur].val){
        ret += nodes[ nodes[cur].ch[LF] ].Sz;
    }
    
    splay(cur, root);
    
    return ret;
}

int ub(int &root, nodeData value){ // upper bound
    return lb(root, value + 1);
}

void splayMax(int &root){
    int cur ;
    for (cur = root; nodes[cur].ch[RI]; cur = nodes[cur].ch[RI]);
    splay(cur, root);
}

int merge(int ls, int gr){
    if (!ls) return gr;
    splayMax(ls);
    link(ls, gr, RI);
    return ls;
}

void del(int &root, nodeData value){
    
    getByValue(value, root);
    
    if (value == nodes[root].val){
        if (nodes[root].freq > 1){
            --nodes[root].freq;
            --nodes[root].Sz;
        }
        else{
            makeFree(root);
            link(0, nodes[root].ch[LF], LF);
            link(0, nodes[root].ch[RI], LF);
            root = merge(nodes[root].ch[LF], nodes[root].ch[RI]);
        }
    }
}

void print(int node, int depth){
    
    if (!node){
        return void();
    }
    
    print(nodes[node].ch[LF], depth + 1);
    printf("%s%d\n", string(depth, ' ').c_str(), nodes[node].val);
    print(nodes[node].ch[RI], depth + 1);
}

void print(int node){
    puts("--------------");
    print(node, 0);
    puts("--------------");
    fflush(stdout);
}

int main(){
    
    init();
    int root = 0;

    int q;
    scanf("%d", &q);
    while (q--) {
        char t;
        int x;
        scanf(" %c%d", &t, &x);
        switch (t) {
            case 'I': {
                int l = lb(root, x);
                if (getByIdx(root, l) != x)
                    insert(root, x);
                break;
            }
            case 'K':
                if (x > nodes[root].Sz)
                    puts("invalid");
                else
                    printf("%d\n", getByIdx(root, --x));
                break;
            case 'C':
                printf("%d\n", lb(root, x));
                break;
            case 'D':
                int l = lb(root, x);
                if (getByIdx(root, l) == x)
                    del(root, x);
        }
    }
    return 0;
}