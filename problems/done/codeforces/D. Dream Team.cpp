// Problem: D. Dream Team
// Contest: Codeforces - Egyptian Collegiate Programming Contest 2017 (ACM ECPC 2017) - original tests edition
// URL: https://codeforces.com/gym/101856/problem/D
// Memory Limit: 1024 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N = 1e5 + 15;
 vector <int>  g[N];
int parent[N], ra[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ra[v] = 0;
}
bool check(int x, int y){
     return find_set(x) == find_set(y);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ra[a] < ra[b])
            swap(a, b);
        parent[b] = a;
        if (ra[a] == ra[b])
            ra[a]++;
    }
}

ll MST () {
    
    ll Ans = 0;
    
    for (int i = N - 5; i >= 1; i--) {
        
        vector <int> &u = g[i];
        if (u.empty()) continue;
        
        int v = u[0];
        
        for (int x : u) {
            if (check(v, x)) continue;
            Ans += i;
            union_sets(v, x);
        }
    }
    
    return Ans;
}

int main() {
    
    freopen("dream.in", "r", stdin);
    
    int t;
    cin >> t;
  
    int I = 1;
  
    while (t--){

        for (int i = 0; i < N; i++)
            make_set(i),
            g[i].clear();
            
        cin >> n;
        
        int x;
        for (int i=0;i<n;i++){
            cin >> x;
            for (int j = 1; j * j <= x; j++) {
                if (x % j == 0) {
                    g[j].push_back(i);
                    if (j * j == x) continue;
                    g[x / j].push_back(i);
                }
            }
        }
        
        ll Ans = MST();
        
        printf("Case %d: %lld\n", I++, Ans);
    }
}