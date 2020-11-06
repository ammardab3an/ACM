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
int in[N],out[N],num;

vector<int>level[N];

void init(int x,int pp = 0,int l =0){
    if(x == 14){
            cout<<"D";
    }
    in[x] = ++num;
    lev[x] = l;
    level[l].push_back(in[x]);
    per[x][0] = pp;

    for(int i=0 ;i <p[x].size() ;i ++){
        int ch = p[x][i];
        if(pp == ch)continue;
        init(ch,x,l+1);
    }
    out[x] = num;
}

void pro(){
    for(int j=1; j <LOG ;j ++){
        for(int i=1; i <=n ; i++){
            int pp = per[i][j-1];
            per[i][j] = per[pp][j-1];
        }
    }
}

int getPer(int x,int nm){
    for(int i = LOG-1; i>=0 ; i--){
        int dist = 1<<i;// 2 ^ i
        if(nm >= dist){
            nm -= dist;
            x = per[x][i];
        }
    }
    return x;
}

int getNodesNum(int x,int lev){
    vector<int>::iterator en = upper_bound(level[lev].begin(),level[lev].end(),out[x]);
    vector<int>::iterator st = lower_bound(level[lev].begin(),level[lev].end(),in[x]);
    return en - st;
}

int main(){
    cin>>n;
    int pr;
    for(int i=1; i <=n; i++){
        scanf("%d",&pr);
        if(!pr)continue;
        per[i][0] = pr;
        p[pr].push_back(i);
    }
    for(int i=1; i <=n; i++){
        if(!per[i][0])
            init(i);
    }



    int m;
    cin>>m;
    int v;

    while(m--){
        scanf("%d%d",&v,&pr);
        pr = getPer(v,pr);
        if(pr == 0){
            printf("0 ");
            continue;
        }

        int sz = getNodesNum(pr,lev[v])-1;
        printf("%d ",sz);
    }

    return 0;
}
