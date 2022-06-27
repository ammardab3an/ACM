#include <bits/stdc++.h>


using namespace std;

const int N = 1e5 + 10;
int a[N];
set<int> v[N];
int sub[N];
int dad[N];

int main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n-1; i++){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        v[x].insert(y);
        v[y].insert(x);
    }

    for(int i = 0; i < k; i++){
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }

    queue<int> q;
    vector<int> bad(n+4, 0);
    for(int i = 1; i <= n; i++){
        if(v[i].size() == 1 && a[i] == 0){
            bad[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(a[cur]) assert(false);

        for(int i : v[cur]){
            v[i].erase(cur);
            if(v[i].size() == 1 && a[i] == 0){
                assert(bad[i] != 1);
                bad[i] = 1;
                q.push(i);
            }
        }

    }

    int ans = n;
    for(int x : bad) ans -= x;

    cout << ans;

}
