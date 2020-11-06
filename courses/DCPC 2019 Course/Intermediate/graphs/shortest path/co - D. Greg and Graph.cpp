#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const int INF = 1e9;
const int N = 510;
int a[N][N];
int x[N];
int dist[N][N];
bool vis[N];
ll res[N];

int main(){
    int n;
    cin>>n;
    for(int i=1; i <=n ;i ++){
        for(int j=1; j<= n ;j++){
            scanf("%d",&a[i][j]);
            dist[i][j] = INF;
        }
    }

    for(int i=0 ;i <n ;i++){
        scanf("%d",&x[i]);
    }
    int mid;
    for(int k=n-1 ; k>=0 ; k--){
        mid = x[k];
        vis[mid] = 1;
        for(int i=1 ;i <=n ;i ++){
            if(!vis[i])continue;
            dist[i][mid] = min(dist[i][mid],a[i][mid]);
            dist[mid][i] = min(dist[mid][i],a[mid][i]);
        }
        ll r = 0;
        for(int i=1 ;i <=n ;i ++){
            if(!vis[i])continue;
            for(int j=1 ;j <=n ;j ++){
                if(!vis[j])continue;
                dist[i][mid] = min(dist[i][mid],dist[i][j]+dist[j][mid]);
                dist[mid][i] = min(dist[mid][i],dist[mid][j]+dist[j][i]);
            }
        }
        for(int i=1 ;i <=n ;i ++){
            if(!vis[i])continue;
            for(int j=1 ;j <=n ;j ++){
                if(!vis[j])continue;
                dist[i][j] = min(dist[i][j],dist[i][mid]+dist[mid][j]);
                r += dist[i][j];
            }
        }
        res[k] = r;
    }

    for(int i=0 ;i <n ;i ++){
        printf("%lld ",res[i]);
    }

    return 0;
}
