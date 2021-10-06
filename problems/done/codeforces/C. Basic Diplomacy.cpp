// Problem: C. Basic Diplomacy
// Contest: Codeforces - Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/C
// Memory Limit: 512 MB
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

int cnt[NMAX];
vi vec[NMAX];
int ans[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n, m;
        cin >> n >> m;
        
        // n frinds
        // m days
        
        memset(cnt, 0, (n+1) * sizeof(cnt[0]));
        memset(ans, -1, (m+1) * sizeof(ans[0]));
        for(int i = 0; i <= m; i++) vec[i].clear();
        
        for(int i = 0; i < m; i++){
            int k; 
            cin >> k; 
            vec[i] = vi(k);
            for(auto &i : vec[i]) cin >> i;
        }
        
        priority_queue<pii, vpii, greater<pii> > que;
        
        for(int i = 0; i < m; i++){
            que.push({vec[i].size(), i});
        }
        
        bool flag = false;
        
        while(!que.empty()){
            
            pii tp = que.top(); que.pop();
            
            int sz = tp.first;
            int idx = tp.second;
            
            if(vec[idx].size() != sz) continue;
            
            int mn = INF;
            int p = -1;
            
            for(auto f : vec[idx]){
                if(cnt[f] < mn){
                    mn = cnt[f];
                    p = f;
                }
            }
            
            cnt[p]++;
            
            if(cnt[p] > (m+1)/2){
                flag = true;
                break;
            }
            
            ans[idx] = p;
        }
        
        if(flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i = 0; i < m; i++) cout << ans[i] << ' ';
            cout << endl;
        }
    }	
}
