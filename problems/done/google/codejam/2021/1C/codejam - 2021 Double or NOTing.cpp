// Problem: Double or NOTing
// Contest: Google Coding Competitions - Round 1C 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c1139
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

bool vis[1 << 16];

string bin(int n){
    
    string str;
    while(n){
        str.push_back((n&1) + '0');
        n /= 2;
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

int bfs(int s, int e){
    
    memset(vis, 0, sizeof vis);
    
    queue<pii> que;
    
    vis[s] = true;
    que.push({s, 0});
    
    while(!que.empty()){
        
        auto fr = que.front(); que.pop();
        
        if(fr.first == e){
            return fr.second;
        }
        
        int i = fr.first;
        int d = fr.second;
        
        if(i*2 < (1 << 16)){
            
            if(!vis[i*2])
            {
                vis[i*2] = true;
                que.push({i*2, d+1});
            }
        }
        
        int cnt = 0;
        int tmp = i;
        while(tmp) cnt++, tmp/=2;
        
        int ni = (~i) & ((1 << cnt)-1);
        
        if(i == 0) ni = 1;
        
        if(!vis[ni]){
            vis[ni] = true;
            que.push({ni, d+1});
        }
    }
    
    return -1;
}

int btoi(string n){
    
    int ret = 0;
    
    for(int i = 0; i < n.size(); i++){
        ret *= 2;
        ret += n[i]-'0';
    }
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){
    
        cout << "Case #" << tt++ << ": ";
        
        string s, e;
        cin >> s >> e;
        
        int ans = bfs(btoi(s),btoi(e));
        
        if(ans != -1){
            cout << ans << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
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
