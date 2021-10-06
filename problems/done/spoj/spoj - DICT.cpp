// Problem: Search in the dictionary!
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/DICT/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
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
    node *nxt[26];
    bool val;
    node(){
        memset(nxt, 0, sizeof nxt);
        val = 0;
    }
};

void add(node *root, string str){
    
    node *cur = root;
    
    for(int i = 0; i < str.size(); i++){
        
        if(!cur->nxt[str[i]-'a']) 
            cur->nxt[str[i]-'a'] = new node();
        
        cur = cur->nxt[str[i]-'a'];
    }
    
    cur->val = 1;
}

int dfs(node *cur, string str){
    
    int cnt = 0;
    
    if(cur->val){
        cout << str << endl;
        cnt++;
    }
    
    for(int i = 0; i < 26; i++){
        
        if(cur->nxt[i]) cnt += dfs(cur->nxt[i], str + string(1, 'a' + i));
    }    
    
    return cnt;
}

bool query(node *root, string str){
    
    node *cur = root;
    
    for(int i = 0; i < str.size(); i++){
        
        if(!cur->nxt[str[i]-'a']) return 0;
        
        cur = cur->nxt[str[i]-'a'];
    }
    
    int tot = 0;
    for(int i = 0; i < 26; i++) if(cur->nxt[i]) tot += dfs(cur->nxt[i], str + string(1, 'a' + i));
    return tot;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    node *root = new node();
    
    for(int i = 0; i < n; i++){
        
        string word;
        cin >> word;
        
        add(root, word);
    }
    
    int tt = 1;
    int m; cin >> m; while(m--){
        
        cout << "Case #" << tt++ << ":" << endl;
        
        string pre;
        cin >> pre;
        
        bool que = query(root, pre);
        
        if(!que){
            cout << "No match." << endl;
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
