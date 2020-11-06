#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const int INF = 1e9;
const int N = 1010;
int n,m;
char s[N][N];
int dist[N][N];

void init(){
    for(int i=0 ;i <=n ;i ++){
        for(int j=0 ;j <=m ; j++){
            dist[i][j] = INF;
        }
    }
}

int dx[] = {-1,1 ,0 ,0};
int dy[] = {0 ,0 ,-1,1};

bool check(pii x){
    if(x.fr <0 || x.sc <0)return 0;
    if(x.fr >=n || x.sc >= m)return 0;
    return 1;
}

int bfs(){
    init();
    deque<pii>q;
    q.push_back({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        int x = q.front().fr;
        int y = q.front().sc;
        q.pop_front();

        for(int i=0 ;i <4 ; i++){
            pii go = {x+dx[i],y+dy[i]};
            if(!check(go))
                continue;
            if(s[x][y] == s[go.fr][go.sc]){
                if(dist[go.fr][go.sc] <= dist[x][y])
                    continue;

                dist[go.fr][go.sc] = dist[x][y];
                q.push_front(go);
            }
            else{
                if(dist[go.fr][go.sc] <= dist[x][y]+1)
                    continue;
                dist[go.fr][go.sc] = dist[x][y]+1;
                q.push_back(go);
            }
        }
    }
    return dist[n-1][m-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0 ;i <n ;i ++){
            scanf("%s",s[i]);
            //printf("%s\n",s[i]);
        }
        printf("%d\n",bfs());
    }
    return 0;
}
