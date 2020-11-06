#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define fr first
#define sc second
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair

using namespace std;

const int N = 1e5+10,LOG = 18;
vector<pii>p[N];
int per[N][LOG];
int lev[N],n;
ll dist[N];

void init(int x,int pp = 0,int l =0,ll ds=0){
    lev[x] = l;
    dist[x] = ds;
    per[x][0] = pp;
    for(int i=0 ;i <p[x].size() ;i ++){
        int ch = p[x][i].fr;
        int w = p[x][i].sc;
        if(pp == ch)continue;
        init(ch,x,l+1,ds + w);
    }
}

void pro(){
    for(int j=1; j <LOG ;j ++){
        for(int i=1; i <=n ; i++){
            int pp = per[i][j-1];
            per[i][j] = per[pp][j-1];
        }
    }
}

int lca(int x,int y){
    if(lev[x] < lev[y])swap(x,y);
    for(int i=LOG-1; i >=0 ; i--)
        if(per[x][i] && lev[per[x][i]] >= lev[y])
            x = per[x][i];

    if(x == y)
        return x;

    for(int i=LOG-1; i >=0 ; i--)
        if(per[x][i] && per[x][i] != per[y][i]){
            x = per[x][i];
            y = per[y][i];
        }
    return per[y][0];
}

int comp[N];

int getC(int x){
    if(comp[x] == x)
        return x;
    return comp[x] = getC(comp[x]);
}

void merg(int x,int y){
    x = getC(x);
    y = getC(y);
    comp[x] = y;
}

void initTest(){
    for(int i=1 ;i <=n ; i++){
        p[i].clear();
        comp[i] = i;
    }
}

ll go(int x,int y){
    return dist[x] + dist[y] - 2*dist[lca(x,y)];
}

int main(){
    int t;
    cin>>t;
    int q;
    while(t--){
        scanf("%d%d",&n,&q);

        initTest();

        int x,y,edx,edy,w,edw;
        for(int i=0 ;i <n ;i ++){
            scanf("%d%d%d",&x,&y,&w);
            if(getC(x) == getC(y)){
                edx = x;
                edy = y;
                edw = w;
                continue;
            }
            p[x].push_back({y,w});
            p[y].push_back({x,w});
            merg(x,y);
        }

        init(1);
        pro();
        for(int i=0 ;i <q ; i++){
            scanf("%d%d",&x,&y);
            ll mn = go(x,y);
            mn = min(mn,go(x,edx) + go(y,edy) +edw);
            mn = min(mn,go(x,edy) + go(y,edx) +edw);
            printf("%lld\n",mn);
        }
    }
    return 0;
}
