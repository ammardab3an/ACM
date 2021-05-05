// Problem: Order statistic set
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ORDERSET/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

struct node{
    int val;
    bool foo;
    node *nxt[2];
    node(){
        nxt[0] = nxt[1] = nullptr;
        val = foo = 0;
    }    
};


bool check(node *root, int x){
    
    node *cur = root;
    for(int i = 30; i >= 0; i--){
        bool b = x&(1 << i);
        if(!cur->nxt[b]) return 0;
        cur = cur->nxt[b];
    }
    return cur->foo;
}

void add(node *root, int x, int v){
    
    bool check_x = check(root, x);
    if(check_x && v == 1) return;
    if(!check_x && v == -1) return;
    
    node *cur = root;
    cur->val += v;
    
    for(int i = 30; i >= 0; i--){
        bool b = x & (1 << i);
        if(!cur->nxt[b]) cur->nxt[b] = new node();
        cur = cur->nxt[b];
        cur->val += v;
    }
    
    cur->foo = v == 1;
}

int query_k(node *root, int k){
    
    int ret = 0;
    node *cur = root;
    for(int i = 30; i >= 0; i--){
        
        if((cur->nxt[0]) && ((cur->nxt[0])->val >= k)){
            cur = cur->nxt[0];    
        }
        else{
            if(cur->nxt[0]) k -= (cur->nxt[0])->val;
            cur = cur->nxt[1];
            ret |= 1 << i;
        }
    }
    
    return ret;
}

int query_k_neg(node *root, int k){
    
    int ret = 0;
    node *cur = root;
    for(int i = 30; i >= 0; i--){
        
        if((cur->nxt[1]) && ((cur->nxt[1])->val >= k)){
            cur = cur->nxt[1];    
            ret |= 1 << i;
        }
        else{
            if(cur->nxt[1]) k -= (cur->nxt[1])->val;
            cur = cur->nxt[0];
        }
    }
    
    return ret;
}


int query_sm(node *root, int x){
    
    int ret = 0;
    node *cur = root;
    for(int i = 30; i >= 0; i--){
        bool b = x&(1 << i);    
        if(b){
            if(cur->nxt[1]){
                if(cur->nxt[0]) ret += (cur->nxt[0])->val;
                cur = cur->nxt[1];
            }
            else{
                if(cur->nxt[0]) ret += (cur->nxt[0])->val;
                return ret;
            }
        }
        else{
            if(cur->nxt[0]){
                cur = cur->nxt[0];
            }
            else{
                return ret;
            }
        }
    }    
    
    return ret;
}

int query_bg(node *root, int x){
    
    int ret = 0;
    node *cur = root;
    for(int i = 30; i >= 0; i--){
        bool b = x&(1 << i);
        if(!b){
            if(cur->nxt[0]){
                if(cur->nxt[1]) ret += (cur->nxt[1])->val;
                cur = cur->nxt[0];                
            }
            else{
                if(cur->nxt[1]) ret += (cur->nxt[1])->val;
                return ret;
            }
        }
        else{
            if(cur->nxt[1]){
                cur = cur->nxt[1];
            }
            else{
                return ret;
            }
        }
    }
    
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    node *root_pos = new node();
    node *root_neg = new node();
    
    int q; cin >> q; while(q--){
        
        char com; int i;
        cin >> com >> i;
        
        if(com == 'I'){
            
            if(i >= 0) add(root_pos, i, +1);
            else add(root_neg, -i, +1);
            
        } 
        else if(com == 'D') {
            
            if(i >= 0) add(root_pos, i, -1);
            else add(root_neg, -i, -1);
            
        } 
        else if(com == 'K'){
            
            if(i <= (root_pos->val + root_neg->val)){
                
                if(i <= root_neg->val){
                    cout << -query_k_neg(root_neg, i) << endl;
                }
                else{
                    cout << query_k(root_pos, i-(root_neg->val)) << endl;
                }
            } 
            else
                cout << "invalid" << endl;
        }
        else{
            
            if(i >= 0){
                cout << root_neg->val + query_sm(root_pos, i) << endl;
            }
            else{
                cout << query_bg(root_neg, -i) << endl;
            }
        }
            
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
