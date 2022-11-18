#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int int64_t

int n, m, k;
int o, t;
vector<int> v[1010];

ll dist[1010][1010];

void dij(int start){

    for(int i = 0; i < n; i++) dist[start][i] = 1e9;

    dist[start][start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int x : v[cur]){
            if(dist[start][x] > dist[start][cur] + 1){
                dist[start][x] = dist[start][cur] + 1;
                q.push(x);
            }
        }
    }
}

int t1[1010];
int t2[1010];
int score[1010];
int dp[2][1010][10010];

ll solve(int cur, int task, int T, bool b){

    if(T < 0) return -1e15;

    if(task == o){
        T -= dist[cur][0];
        return T >= 0 ? 0 : -1e15;
    }

    int &ret = dp[b][task][T];
    if(ret+1) return ret;

    ll f = solve(t1[task], task+1, T - dist[cur][t1[task]], 0);
    ll s = score[task] + solve(t2[task], task+1, T - dist[cur][t1[task]] - dist[t2[task]][t1[task]], 1);

    return ret = max(f, s);
}

main()
{

    scanf("%I64d%I64d%I64d", &n, &m, &k);

    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%I64d%I64d", &x, &y);
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i = 0; i < n; i++){
        dij(i);
    }

    scanf("%I64d%I64d", &o, &t);
    t /= k;

    for(int i = 0; i < o; i++){
        scanf("%I64d", &t1[i]);
        t1[i]--;
    }
    for(int i = 0; i < o; i++){
        scanf("%I64d%I64d", &t2[i], &score[i]);
        t2[i]--;
    }

    memset(dp, -1, sizeof dp);

    ll ans = solve(0, 0, t, 0);

    if(ans < 0) puts("Impossible");
    else cout << ans << endl;

    return 0;
}
