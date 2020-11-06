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
vector<int>p[N];
int per[N][LOG];
int lev[N],n;

void init(int x,int pp = 0,int l =0){
    lev[x] = l;
    per[x][0] = pp;
    for(int i=0 ;i <p[x].size() ;i ++){
        if(pp == p[x][i])continue;
        init(p[x][i],x,l+1);
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

int pre[N];
int a[N],b[N];

map<pii,int>resEd;

int dfs(int x,int pp =0){
    int sum = 0;
    for(int i=0 ;i <p[x].size() ;i ++){
        int ch = p[x][i];
        if(pp == ch)continue;

        int r = dfs(ch,x);

        resEd[{ch,x}] = r;
        resEd[{x,ch}] = r;

        sum += r;
    }
    return sum + pre[x];
}

int main(){
    cin>>n;
    int u,v;
    for(int i=0 ;i <n-1 ;i ++){
        scanf("%d%d",&a[i],&b[i]);
        u = a[i];
        v = b[i];
        p[u].push_back(v);
        p[v].push_back(u);
    }
    int root = 1;
    init(root);
    pro();

    int k;
    cin>>k;
    for(int i=0 ;i<k ;i ++){
        scanf("%d%d",&u,&v);
        pre[u]++;
        pre[v]++;
        pre[lca(u,v)]-=2;
    }

    dfs(root);

    for(int i=0 ;i <n-1; i++){
        printf("%d ",resEd[{a[i],b[i]}]);
    }

    return 0;
}
